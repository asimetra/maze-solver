#ifndef VECT2_HPP
# define VECT2_HPP

struct Vect2 {
	int x, y;

	Vect2();
	Vect2(int px, int py);

	bool	operator==(const Vect2& vect) const;
	Vect2	operator+(const Vect2& vect) const;
	
    bool	has() const;
	bool	isAdjacent(const Vect2& vect) const;
};

#endif
