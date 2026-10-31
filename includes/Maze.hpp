#ifndef MAZE_HPP
# define MAZE_HPP

#include <string>

#define WIDTH 50
#define HEIGHT 20

/*POD*/
struct vect2 { 
	int x; 
	int y; 
	
	bool operator==(const vect2& vect) const { return x == vect.x && y == vect.y;}
	vect2 operator+(const vect2& vect) const { return vect2{x + vect.x, y + vect.y};}
	bool has() const { return x != 0 || y != 0 ;}
	bool isAdjacent(const vect2& vect) const { /*list initialization: https://www.cppreference.com/cpp/language/list_initialization*/
		 return *this == (vect + vect2{0, 1}) ||
		 		*this == (vect + vect2{1, 0}) ||
				*this == (vect + vect2{-1, 0}) ||
				*this == (vect + vect2{0, -1});
	} 
};

class Maze {
    private:
		char	_map[HEIGHT][WIDTH];   
		vect2	_start;
		vect2	_exit;	
		
		void	build(std::istream& input);
		void	parseLine(const std::string& line, int lindex);
		
		void	parseGate(const vect2 &vect);

		Maze(std::istream& input);

		bool	isValidTile(char c) const;
		bool	isCornerTile(const vect2 &vect) const;
		bool	isBorderTile(const vect2 &vect) const;
		bool	isHorizBorderTile(const vect2 &vect) const;
		bool	isVertBorderTile(const vect2 &vect) const;

		void	setGate(const vect2 &vect);

	public:
		typedef enum { WALL = '#', FLOOR = ' ' } Tile;

		static Maze	fromFile(const std::string &mf);

		const vect2&	getStart() const;
		const vect2&	getExit() const;

		int	getWidth() const;
		int	getHeight() const;

		bool		isValidMove(const vect2& vect) const;

		Tile	getTile(const vect2& vect) const;
};

#endif
