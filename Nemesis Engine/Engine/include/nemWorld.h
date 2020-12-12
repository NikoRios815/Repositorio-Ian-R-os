#pragma once
#ifndef NEMWORLD_H
#define NEMWORLD_H
#include "nemBody.h"
#include <vector>

struct nemWorld
{
	//We define the constructor.
	nemWorld() {}

	//We define the constructor that sends the gravity value.
	nemWorld(vec2D gravity) : gravity(gravity) {}

	//We declare the world's gravity.
	vec2D gravity;

	//We declare a vector that holds all the bodies in the world. 
	std::vector<nBody*> bodies;

	//We declare a method to assign the value of gravity. 
	void setGravity(const vec2D& g);

	//We declare a method to add bodies to the world. 
	void addBody(nBody* b);

	//We create this method to handle simulations. It receives dt which should be the time between frames.
	void Step(float dt); 

};

#endif /* NEMWORLD_H */