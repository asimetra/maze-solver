#ifndef VECT2_HPP
# define VECT2_HPP

struct Vect2 {
	int x, y;

	Vect2();
	Vect2(int px, int py);

	bool	operator==(const Vect2& vect) const;
	bool	operator!=(const Vect2& vect) const;
	
	Vect2&	operator-=(const Vect2& vect);
	Vect2&	operator+=(const Vect2& vect);

	Vect2	operator+(const Vect2& vect) const;
	Vect2	operator-(const Vect2& vect) const;

    bool	has() const;
	bool	isAdjacent(const Vect2& vect) const;
};

namespace dir {
	enum Dir {LEFT, RIGHT, UP, DOWN, NONE};

	Vect2 toVect2(const Dir& dir);
}

#endif
