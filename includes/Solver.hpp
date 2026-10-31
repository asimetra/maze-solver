#ifndef SOLVER_HPP
# define SOLVER_HPP

#include "Maze.hpp"
#include <stack>

class Solver {
    private:
        int		_visited[HEIGHT][WIDTH]; /*visiter or shing*/
        Maze	_maze;

    public:
        Solver(const Maze& maze);

        std::stack<int> Solve(); //prop we have to turn stack instead of using void 
};

#endif