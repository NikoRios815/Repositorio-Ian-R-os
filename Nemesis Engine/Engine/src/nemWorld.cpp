#include "nemWorld.h"

//This function is used to give a value to gravity.
void nemWorld::setGravity(const vec2D& g)
{
	gravity = g;
}

//This function is used to add the body created in nemBody into the world "scene".
void nemWorld::addBody(nBody* b)
{
	bodies.push_back(b);
}

//This function handles the simulations by calculating the body velocity and position.
void nemWorld::Step(float dt)
{
	for (int counter = 0; counter < bodies.size(); counter++) {
		bodies[counter]->velocity.x += (gravity.x + bodies[counter]->force.x * bodies[counter]->invMass) * dt;
		bodies[counter]->velocity.y += (gravity.y + bodies[counter]->force.y * bodies[counter]->invMass) * dt;
	}

	for (int counter = 0; counter < bodies.size(); counter++) {
		bodies[counter]->position.x += bodies[counter]->velocity.x * dt;
		bodies[counter]->position.y += bodies[counter]->velocity.y * dt;

		bodies[counter]->force.setZero();
	}
}