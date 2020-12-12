#include "nemMath.h"

//When this function is called it sets the x and y values to 0.
void vec2D::setZero()
{
    x = 0.0f;
    y = 0.0f;
}

//When this function is called it sets x and y values to the values received by the function.
void vec2D::Set(const float& x_, const float& y_)
{
    x = x_;
    y = y_;
}

//When this function is called it prints the vector x and y values.
void vec2D::displayVector() const
{
    std::cout << "(" << x << "," << y << ")" << std::endl;
}

float vec2D::lengthSquared() const
{
    return x * x + y * y;  //Here we are calculating the lengthsquared of the vector which is the sum of x and y to the power of 2.
}

float vec2D::length() const
{
    return sqrt(x * x + y * y); //Here we are calculating square root of the x and y values to the power of 2.
}

/*In this function we are doing a operator overload on the operator + so that when its used, it automatically sums the value it was used on to x and y
/so that we can make a sum directly with the vector instead of doing it with the individual parts of the vector (x and y).*/
void vec2D::operator+=(const vec2D& v)
{
    x += v.x;
    y += v.y;
}
/*In this function we are doing a operator overload on the operator - so that when its used, it automatically difference the value it was used on to x and y
/so that we can make a difference directly with the vector instead of doing it with the individual parts of the vector (x and y).*/
void vec2D::operator-=(const vec2D& v)
{
    x -= v.x;
    y -= v.y;
}

/*In this function we are doing a operator overload on the operator * so that when its used, it automatically multiplies the value it was used on to x and y
/so that we can make a multiplication directly with the vector instead of doing it with the individual parts of the vector (x and y).*/
void vec2D::operator*=(const float& k)
{
    x *= k; /* x = k*x */
    y *= k; /* y = k*y */
}