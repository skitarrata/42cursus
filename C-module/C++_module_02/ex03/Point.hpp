#ifndef POINT_HPP
# define POINT_HPP 

#include "Fixed.hpp"

class						Point
{
	private:
		Fixed const x;
		Fixed const y;
	public:
		Point();
		Point(const float _x, const float _y);
		Point(const Point& p);
		Point&				operator=(const Point& p);
		~Point();

		const Fixed&		getX() const;
		const Fixed&		getY() const;
};

#endif