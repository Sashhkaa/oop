#include <iostream>
#include <iomanip>
#include <cmath>
#include "point.h"
using std::cout, std::endl;


Point::Point(float x,float y){
 float mx=x;
 float my=y;
}

Point::Point(){// default constructor
    mx = 0;
    my = 0;
}

float Point::Getx(){
 return int x;
}

float Point::Gety(){
 return y;
}

float Point::norm() const
{
	return std::sqrt(mx * mx + my * my);
}

void Point::normalize()
{
	float pnorm = norm();
	mx /= pnorm;
	my /= pnorm;
}

float Point::distance(const Point& p) const
{
	return std::sqrt((p.mx - mx) * (p.mx - mx) + (p.my - my) * (p.my - my));
}

Point Point::operator+(const Point& p) const
{
	Point result = {mx + p.mx, my + p.my};
	return result;
}

Point Point::operator*(float a) const
{
	Point result = {a * mx, a * my};
	return result;
}

Point operator*(float a, const Point& p)
{
	Point result = {a * p.mx, a * p.my};
	return result;
}

std::ostream& operator<<(std::ostream& a, const Point& p)
{
	a << "(" << p.mx << ", " << p.my << ")";
	return a;
}
