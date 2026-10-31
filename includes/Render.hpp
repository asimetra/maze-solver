#ifndef RENDER_HPP
# define RENDER_HPP

#include "Maze.hpp"

class Render {
    private:
        Maze	_maze;

    public:
        Render(const Maze& maze);

        void    Draw();
};

#endif
