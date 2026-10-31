#ifndef SOLVER_HPP
# define SOLVER_HPP

#include "Maze.hpp"

class Solver {
    private:
        int		_visited[HEIGHT][WIDTH]; /*visiter or shing*/
        Maze	_maze;

    public:
        Solver(const Maze& maze);

        void    Solve(); //prop we have to turn stack instead of using void 
};

#endif