#include "../includes/Vect2.hpp"
#include <cstdlib>

Vect2::Vect2() : x(0), y(0) {}
Vect2::Vect2(int vx, int vy) : x(vx), y(vy) {}

bool	Vect2::operator==(const Vect2& vect) const { return x == vect.x && y == vect.y;}
Vect2	Vect2::operator+(const Vect2& vect) const { return Vect2(x + vect.x, y + vect.y);}

bool	Vect2::has() const { return x != 0 || y != 0 ;}

bool	Vect2::isAdjacent(const Vect2& vect) const {
	return (std::abs(this->x - vect.x) + std::abs(this->y - vect.y)) == 1 ; /*https://www.geeksforgeeks.org/data-science/manhattan-distance/*/
}
