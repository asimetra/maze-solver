#ifndef RENDER_HPP
# define RENDER_HPP

#include "Maze.hpp"
#include <stack>

#define FPS 5

class Render {
    private:
        Maze	_maze;
        
        /* UTF-8 filled arrows (◄ ► ▲ ▼), order follows dir::Dir: LEFT, RIGHT, UP, DOWN.
           Raw bytes 16/17/30/31 are control codes in modern consoles and print nothing. */
        const char* _dirChr[4] = {"\xE2\x97\x84", "\xE2\x96\xBA", "\xE2\x96\xB2", "\xE2\x96\xBC"};

        void    renderFrame(const Vect2& pos, dir::Dir dir);
        void    clearScreen();
        void    waitNextFrame(unsigned int us);

    public:
        Render(const Maze& maze);

        void    render(std::stack<dir::Dir> steps);
};

#endif
