#include <iostream>
#include <glut.h>
#include "Boid.h"

//BOID

using namespace boid;

Boid::Boid() {
	float FLOAT_MIN = -5.;
	float FLOAT_MAX = 5.;


	float x = FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX / (FLOAT_MAX - FLOAT_MIN)));
	float y = FLOAT_MIN + (float)(rand()) / ((float)(RAND_MAX / (FLOAT_MAX - FLOAT_MIN)));

	this->p << x, y, 0.;

	this->v << 0., 0., 0.;
	this->a << 0., 0., 0.;
};

Boid::~Boid() {
}

void Boid::PrintPosition() {
	std::cout << "px = " << p[0] << " py = " << p[1] << " pz = " << p[2] << std::endl;
}

void Boid::PrintVelocity() {
	std::cout << "vx = " << v[0] << " vy = " << v[1] << " vz = " << v[2] << std::endl;
}

void Boid::PrintAcceleration() {
	std::cout << "ax = " << a[0] << " ay = " << a[1] << " az = " << a[2] << std::endl;
}

void Boid::DrawTriangles(Eigen::Vector3f c) {

	float px = this->p[0], py = this->p[1], pz = this->p[2];

	Eigen::Vector3f direction = v / v.norm();

	Eigen::Vector3f summit1 = p + 0.5 * direction;

	Eigen::Matrix3f m_rot2;
	m_rot2 = Eigen::AngleAxisf((11 * M_PI )/ 12 , Eigen::Vector3f(0., 0., 1.0));
	Eigen::Vector3f summit2 = .75 * direction.transpose() * m_rot2;
	summit2 = summit1 + summit2;

	Eigen::Matrix3f m_rot3;
	m_rot3 = Eigen::AngleAxisf((- 11 * M_PI) / 12, Eigen::Vector3f(0., 0., 1.0));
	Eigen::Vector3f summit3 = .75 * direction.transpose() * m_rot3;
	summit3 = summit1 + summit3;


	glPointSize(5);
	glBegin(GL_POINTS);

		// Show the center of the triangle
		glColor3f(0., 1., 0.);
		glVertex3f(px, py, pz);

	glEnd();
	
	
	glBegin(GL_TRIANGLES);
	glColor3f(c[0], c[1], c[2]);
	glVertex3f(summit1[0], summit1[1], summit1[2]);
	glVertex3f(summit2[0], summit2[1], summit2[2]);
	glVertex3f(summit3[0], summit3[1], summit3[2]);
	glEnd();
	
}

void Boid::draw()
{
	float px = this->p[0], py = this->p[1], pz = this->p[2];	
	DrawTriangles({ 0.,0.,1. });
}


Boid_white::Boid_white() {
	this->color << 1., 1. ,1.;
}
void Boid_white::draw()
{
	float px = this->p[0], py = this->p[1], pz = this->p[2];
	DrawTriangles(this->color);
}

Boid_red::Boid_red() {
	this->color << 1., 0. ,0.;
}
void Boid_red::draw()
{
	float px = this->p[0], py = this->p[1], pz = this->p[2];
	DrawTriangles(this->color);
}