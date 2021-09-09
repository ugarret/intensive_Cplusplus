#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class	Point
{
	private:
		Fixed const _x;
		Fixed const _y;

	public:
		Point();
		Point(float const x, float const y);
		~Point();
		Point(const Point &other);
		Point &operator=(const Point &other);
		Fixed get_x() const;
		Fixed get_y() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif