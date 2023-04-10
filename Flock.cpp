#include <iostream>
#include <glut.h>
#include "Flock.h"
//#include "Boid.h"

const float C_1 = 0.01; //constant for cohesion rule

const float max_dist_2 = 5.; //distance max for separation rule 
const float C_2 = - 0.5; //constant for separation rule, negative because it is repulsive

const float C_3 = 0.2; //constant for alignement rule

//BOID
Flock::Flock() {
	choose_color <boid::Boid_white, boid::Boid_red>(boids);
}

Flock::Flock(int first_size) {
	boids = std::vector<boid::Boid>(first_size);
}

Flock::~Flock() {
}

void Flock::Print() {
	std::cout << "size = " << this-> boids.size() << std::endl;
	for (auto i = 0; i < this->boids.size(); ++i) {
		boids[i].PrintPosition();
	};
}

Eigen::Vector3f Flock::center_of_mass() {
	Eigen::Vector3f mean(0., 0., 0.);
	for (int i = 0; i < this->boids.size(); ++i) {
		mean += boids[i].p;
	};
	mean = mean / (this->boids.size()-1);

	return mean;
}

Eigen::Vector3f Flock::separation(boid::Boid boid) {
	Eigen::Vector3f sum (0.,0.,0.);

	for (int i = 0; i < this->boids.size(); ++i) {
		float distance = (boid.p - boids[i].p).norm();

		if (distance != 0. and distance <= max_dist_2) {
			sum = sum + (boid.p - boids[i].p);
		};
	};
	return C_2 * sum;
}

Eigen::Vector3f Flock::alignement(boid::Boid boid) {
	Eigen::Vector3f mean_v(0., 0., 0.);
	for (int i = 0; i < this->boids.size(); ++i) {
		//std::cout << boids[i].v << std::endl;

		mean_v = mean_v + boids[i].v;
	};
	mean_v = mean_v / (this->boids.size()-1);

	return C_3 * (mean_v - boid.v);
};


void Flock::rules(float dt, Eigen::Vector3f center_mass) {	
	if (this->boids.size() < 2) {
		throw std::exception("There is only 1 bird");
	};

	std::vector<boid::Boid> temp;
	for (int i = 0; i < this->boids.size(); ++i) {
		Eigen::Vector3f a1(0., 0., 0.);
		Eigen::Vector3f a2(0., 0., 0.);
		Eigen::Vector3f a3(0., 0., 0.);
			

		boid::Boid temp_boid;


		a1 = C_1 * (center_mass - boids[i].p);
		a2 = separation(boids[i]);
		a3 = alignement(boids[i]);
			
		//temp_boid.a = 0.2 * (a1 + a2 - 2 * boids[i].p ) / (dt * dt);
		//std::cout << a3 << std::endl;
		temp_boid.a = (a1 + a2 + a3);

		//temp_boid.a = 0.1 * a3;
		//temp_boid.PrintAcceleration();

		temp_boid.v = (boids[i].v + dt * temp_boid.a);
		temp_boid.p = boids[i].p + dt * temp_boid.v;

		temp.push_back(temp_boid);
	};
	this->boids = temp;
} 

void Flock::update() {

}

void Flock::draw()
{
	for (auto i = 0; i < this->boids.size(); ++i) {
		boids[i].draw();
	};
}

void Flock::move()
{

}