#include "../includes/Maze.hpp"
#include <fstream>
#include <stdexcept>

Maze::Maze(std::istream& input) : _start(), _exit() {build(input);}

bool	Maze::isValidTile(char c) const { return  c == WALL || c == FLOOR;}
bool 	Maze::isHorizBorderTile(const vect2 &vect) const { return vect.x == 0 || vect.x == HEIGHT - 1;}
bool 	Maze::isVertBorderTile(const vect2 &vect) const { return vect.y == 0 || vect.y == WIDTH - 1;}
bool	Maze::isBorderTile(const vect2 &vect) const { return isHorizBorderTile(vect) || isVertBorderTile(vect);}
bool	Maze::isCornerTile(const vect2 &vect) const {return isHorizBorderTile(vect) && isVertBorderTile(vect);};

int		Maze::getWidth() const {return WIDTH;}
int 	Maze::getHeight() const {return HEIGHT;}

const vect2&	Maze::getStart() const { return _start;};
const vect2&	Maze::getExit() const  { return _exit;};

bool	Maze::isValidMove(const vect2& vect) const { return vect.x >= 0 && vect.y >= 0 && vect.y < WIDTH && vect.x < HEIGHT;}

Maze    Maze::fromFile(const std::string &mf) {
    if (mf.size() <= 4 || mf.substr(mf.size() - 4) != ".txt") {
        throw std::runtime_error("invalid file extension");
    }
    
    std::ifstream input(mf.c_str());
	if (!input.is_open()) {
		throw std::runtime_error("cannot open maze file");
	}

    return Maze(input);
}

void    Maze::build(std::istream& input) {
	std::string line;
	int	lineCount = 0;

	/*void pointer operator return fail*/
    while (lineCount < HEIGHT && std::getline(input, line) ) { 
        /* C streams on Windows OS convert '\n' to '\r\n' on output, 
		and convert '\r\n' to '\n' on input. ref: https://en.cppreference.com/c/io/FILE
		so a CRLF file read on Linux leaves a trailing '\r' in each line*/
		if (!line.empty() && line.back() == '\r') { 
			line.pop_back();
		}
		
		parseLine(line, lineCount);
		lineCount++;
	}

	if (input.bad()) {
		throw std::runtime_error("reading input");
	}

	/* If good() == true, returns the next character as obtained by rdbuf()->sgetc().
	   Otherwise, returns Traits::eof()*/
    if (input.peek() != std::char_traits<char>::eof()) {
        throw std::runtime_error("too many lines");
    }

	if (lineCount != HEIGHT) {
		throw std::runtime_error("invalid HEIGHT");
	}

	if (!_exit.has()) {
		throw std::runtime_error("invalid GATE COUNT on map");
	}

}

void	Maze::parseLine(const std::string& line, int lindex) {	
	if (line.size() != WIDTH) {
		throw std::runtime_error("invalid WIDTH");
	}

	for (vect2 v = {lindex, 0}; v.y < WIDTH; v.y++) {		
		char tile = line[v.y];
		
		if (!isValidTile(line[v.y])) {
			throw std::runtime_error("invalid TILE on map");
		}
		_map[v.x][v.y] = tile; /*assign to map*/ 

		if (tile == FLOOR && isBorderTile(v)) {
			parseGate(v);
		}
	}

}

/* dispatcher func
	TOP-BOTTOM Line: Horizontal: Cannot be Corner and horiz sequential gate
	BODY Line: Vertical: Cannot be vert sequential gate
*/
void	Maze::parseGate(const vect2 &vect) {
	if (isCornerTile(vect)) { /*Corner Horiz & Vert*/
		throw std::runtime_error("invalid GATE on map");
	}

	setGate(vect);
	if (_exit.has() && _exit.isAdjacent(_start)) {
		throw std::runtime_error("sequential GATE on map");
	}
}

void	Maze::setGate(const vect2 &vect) {
	if (!_start.has()) { 
		_start = vect;
	}
	else if (!_exit.has()) {
		_exit = vect;
	} else {
		throw std::runtime_error("invalid GATE COUNT on map");
	}
}

Maze::Tile	Maze::getTile(const vect2& vect) const {
	if (!isValidMove(vect)) {
		throw std::runtime_error("invalid TILE position");
	}

	return (Tile)_map[vect.x][vect.y];
}
