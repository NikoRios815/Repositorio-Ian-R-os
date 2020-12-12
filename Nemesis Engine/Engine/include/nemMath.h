#ifndef NEMMATH_H
#define NEMMATH_H

#include <iostream>
#include <math.h>
#include <float.h>
#include <stdlib.h>

struct vec2D
{
	//We declare the vector's components. 
	float x, y;

	//We create a constructor.
	vec2D() {}

	//We create a constructor that passes the vector's components values.
	vec2D(float x, float y) : x(x), y(y) {}

	//We create a methos that is used to exchange the value of the vector's compenents to 0.
	void setZero();
	
	//We create a method that is used to exchange the value of the vector's components.
	void Set(const float& x_, const float& y_);

	//We create a method that prints the vector's x and y values.
	void displayVector() const;

	//We create a method that calculates the squared length of the vector.
	float lengthSquared() const;

	//We create a method that calculates the length of the vector.
	float length() const;

	//We create a methos to sum a vector to the vector
	void operator += (const vec2D& v);

	//We create a method that subtract a vector with the vector. 
	void operator -= (const vec2D& v);

	//We create a method to multiply the vector with a scalar.
	void operator *= (const float& k);

};

inline vec2D operator + (const vec2D& a, const vec2D& b)
{
	return vec2D(a.x + b.x, a.y + b.y);
}

inline vec2D operator - (const vec2D& a, const vec2D& b)
{
	return vec2D(a.x - b.x, a.y - b.y);
}

inline vec2D operator * (const float& k, const vec2D& v)
{
	return vec2D(k * v.x, k * v.y);
}

#endif /*NEMMATH_H*/