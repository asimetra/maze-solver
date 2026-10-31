#ifndef MAZE_HPP
# define MAZE_HPP

#include <string>
#include "Vect2.hpp"

#define WIDTH 50
#define HEIGHT 20

class Maze {
    private:
		char	_map[HEIGHT][WIDTH];   
		Vect2	_start;
		Vect2	_exit;	
		
		void	build(std::istream& input);
		void	parseLine(const std::string& line, int lindex);
		
		void	parseGate(const Vect2 &vect);

		Maze(std::istream& input);

		bool	isValidTile(char c) const;
		bool	isCornerTile(const Vect2 &vect) const;
		bool	isBorderTile(const Vect2 &vect) const;
		bool	isHorizBorderTile(const Vect2 &vect) const;
		bool	isVertBorderTile(const Vect2 &vect) const;

		void	setGate(const Vect2 &vect);

	public:
		typedef enum { WALL = '#', FLOOR = ' ' } Tile;

		static Maze	fromFile(const std::string &mf);

		const Vect2&	getStart() const;
		const Vect2&	getExit() const;

		int	getWidth() const;
		int	getHeight() const;

		bool		isValidMove(const Vect2& vect) const;

		Tile	getTile(const Vect2& vect) const;
};

#endif
