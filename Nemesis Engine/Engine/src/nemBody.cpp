#include "nemBody.h"

//This is the constructor that builds the body. As a default it sets the Body's position, velocity and force to 0.
nBody::nBody()
{
	position.setZero();

	velocity.setZero();

	force.setZero();

	mass = 1.0f;
	invMass = 1.0f; /* 1/mass */ //explain what is  invMass
}

//This function is used to add force.
void nBody::addForce(const vec2D & f)
{
	force += f;
}

//This function is used to sett mass.
void nBody::setMass(const float& m)
{
	mass = m;
	invMass = 1 / m;
}

//This function displays the info of the Body.
void nBody::displayBodyInfo()
{
	std::cout << "m: " << mass << std::endl;
	std::cout << "Inv mass: " << invMass << std::endl;
	std::cout << "pos: ", position.displayVector();
	std::cout << "vel: ", velocity.displayVector();
	std::cout << "\n" << std::endl;
}