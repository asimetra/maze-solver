#ifndef RENDER_HPP
# define RENDER_HPP

#include "Maze.hpp"
#include <stack>

#define FPS 5

class Render {
    private:
        Maze	_maze;
        
        #ifdef _WIN32 /*https://learn.microsoft.com/en-us/cpp/preprocessor/predefined-macros*/
            char    _dirChr[4] = {17, 16, 30, 31}; /*NDSMI: https://en.cppreference.com/cpp/language/data_members */
        #else
            char    _dirChr[4] = {'<', '>', '^', 'v'};
        #endif

        void    renderFrame(const Vect2& pos, dir::Dir dir);
        void    clearScreen();
        void    waitNextFrame(unsigned int us);

    public:
        Render(const Maze& maze);

        void    render(std::stack<dir::Dir> steps);
};

#endif
