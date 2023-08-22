#include "Point.hpp"

Point::Point() : x(0), y(0) {}
Point::Point(const float _x, const float _y) : x(_x), y(_y) {}
Point::Point(const Point& p) { *this = p; }
Point::~Point() {}

Point&					Point::operator=(const Point& p)
{
	(void)p;
	return (*this);
}

const Fixed&				Point::getX() const { return (x); }
const Fixed&				Point::getY() const { return (y); }