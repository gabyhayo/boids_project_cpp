#ifndef FLOCK_H
#define FLOCK_H

#include "Boid.h"
#include <vector>

template<typename color1, typename color2 >
void choose_color(std::vector<boid::Boid> boids) {
	int n = 10;
	for (int i = 0; i < n; i++) {
		int j = rand() % 2 - 1;
		if (j == 0) {
			boids.push_back(temp color1);
		}
		else { 
			boids.push_back(new color2);
		}
	}
}

class Flock {
public:
	std::vector<boid::Boid> boids;

	// Constructor
	Flock();
	Flock(int first_size);
	// Destructor
	virtual ~Flock();

	// Copy Constructor
	Flock(const Flock& x) : boids(x.boids) {
	};

	Eigen::Vector3f center_of_mass();
	Eigen::Vector3f separation(boid::Boid boid);
	Eigen::Vector3f alignement(boid::Boid boid);

	void rules(float dt, Eigen::Vector3f center_mass);
	//Eigen::Vector3f rule_cohesion(Eigen::Vector3f center_mass);

	void Print();
	void update();
	void draw();
	void move();
};

#endif 
