#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed d[3];

	d[0] = (((point.getX() - a.getX()) * (c.getY() - a.getY())) - ((point.getY() - a.getY()) * (c.getX() - a.getX())));
	d[1] = (((a.getX() - point.getX()) * (b.getY() - a.getY())) - ((a.getY() - point.getY()) * (b.getX() - a.getX())));
	d[2] = (((b.getX() - a.getX()) * (c.getY() - a.getY())) - ((b.getY() - a.getY()) * (c.getX() - a.getX())));

	Fixed z(d[0] / d[2]);
	Fixed v(d[1] / d[2]);

	if ( z > 0 && v > 0 && z + v < 1)
		return (true);
	return (false);
}