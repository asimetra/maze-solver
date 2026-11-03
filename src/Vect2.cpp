#include "Vect2.hpp"
#include <cstdlib>
#include <stdexcept>

Vect2::Vect2() : x(0), y(0) {}
Vect2::Vect2(int vx, int vy) : x(vx), y(vy) {}

bool	Vect2::operator==(const Vect2& vect) const { return x == vect.x && y == vect.y;}
bool	Vect2::operator!=(const Vect2& vect) const { return !this->operator==(vect);}

Vect2&	Vect2::operator-=(const Vect2& vect) { *this = *this - vect; return *this;}
Vect2&	Vect2::operator+=(const Vect2& vect) { *this = *this + vect; return *this;}

Vect2	Vect2::operator+(const Vect2& vect) const { return Vect2(x + vect.x, y + vect.y);}
Vect2	Vect2::operator-(const Vect2& vect) const { return Vect2(x - vect.x, y - vect.y);}

bool	Vect2::has() const { return x != 0 || y != 0 ;}

bool	Vect2::isAdjacent(const Vect2& vect) const {
	return (std::abs(this->x - vect.x) + std::abs(this->y - vect.y)) == 1 ; /*https://www.geeksforgeeks.org/data-science/manhattan-distance/*/
}

Vect2	dir::toVect2(const Dir& dir) {
	Vect2 vect;
	
	switch (dir) {
		case Dir::LEFT	: vect = Vect2(0, -1); break;
		case Dir::RIGHT	: vect = Vect2(0, 1); break;
		case Dir::UP 	: vect = Vect2(-1, 0); break;
		case Dir::DOWN	: vect = Vect2(1, 0); break;
		default: throw std::runtime_error("Invalid direction");
	}
	return vect;
}
