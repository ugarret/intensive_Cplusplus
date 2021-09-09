#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed bY_cY = b.get_y() - c.get_y();
	Fixed aX_cX = a.get_x() - c.get_x();
	Fixed cX_bX = c.get_x() - b.get_x();
	Fixed aY_cY = a.get_y() - c.get_y();
	Fixed cY_aY = c.get_y() - a.get_y();
	Fixed pX_cX = point.get_x() - c.get_x();
	Fixed pY_cY = point.get_y() - c.get_y();
	Fixed alpha = (bY_cY * pX_cX + cX_bX * pY_cY) / (bY_cY * aX_cX + cX_bX * aY_cY);
	Fixed beta = (cY_aY * pX_cX + aX_cX * pY_cY) / (bY_cY * aX_cX + cX_bX * aY_cY);
	Fixed gamma(1.0f);
	gamma = gamma - alpha;
	gamma = gamma - beta;
	if (alpha > 0 && beta > 0 && gamma > 0)
		return true;
	return false;
}