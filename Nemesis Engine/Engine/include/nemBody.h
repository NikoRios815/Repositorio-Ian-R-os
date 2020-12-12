#ifndef NEMBODY_H
#define NEMBODY_H

#include "nemMath.h"

struct nBody
{

	//We declare the constructor.
	nBody();

	//We declared the mass and the invMass of the body.
	float mass;
	float invMass;

	//We declared the lineal position of the body.
	vec2D position;

	//We declared the lineal velocity of the body. 
	vec2D velocity;

	//We declared the applied force over the object.
	vec2D force;

	//We created a method to add force to the applied force. 
	void addForce(const vec2D& f);

	//We created a method to assign the body's mass. 
	void setMass(const float& m);

	//We created a method to display the body's properties. 
	void displayBodyInfo();

};

#endif /*NEMBODY_H*/