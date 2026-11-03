#ifndef SOLVER_HPP
# define SOLVER_HPP

#include "Maze.hpp"
#include <stack>
#include "Vect2.hpp"

class Solver {
    private:
        bool	_visited[HEIGHT][WIDTH];
        Maze	_maze;

        void    initVisited();
        bool    isVisited(const Vect2& pos);

        dir::Dir    getNextStep(const Vect2& pos);
        std::stack<dir::Dir>    reverse(std::stack<dir::Dir> path);

    public:
        Solver(const Maze& maze);

        std::stack<dir::Dir> Solve();
};

#endif