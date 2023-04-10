#ifndef BOIDS_H
#define BOIDS_H

#include <Eigen/Dense>


namespace boid
{
class Boid {
public:
	Eigen::Vector3f p;
	Eigen::Vector3f v;
	Eigen::Vector3f a;

	// Constructor
	Boid();
	
	// Destructor
	~Boid();

	// Copy Constructor
	Boid(const Boid& x) : p(x.p), v(x.v), a(x.a) {
	};

	void PrintPosition();
	void PrintVelocity();
	void PrintAcceleration();

	void DrawTriangles(Eigen::Vector3f color = { 0.,0.,1. });
	virtual void draw();
};

class Boid_white : public Boid {
public:
	Eigen::Vector3f color;
	Boid_white();
	void draw() override;
};

class Boid_red : public Boid {
public:
	Eigen::Vector3f color;
	Boid_red();
	void draw() override;
};

};

#endif  // BOIDS_LIB_SAMPLE_CLASS_H_
