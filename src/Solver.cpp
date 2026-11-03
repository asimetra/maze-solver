#include "Solver.hpp"
#include <stack>

Solver::Solver(const Maze& maze) : _maze(maze) {initVisited();}

bool    Solver::isVisited(const Vect2& pos) { return !_maze.isValidMove(pos) || _visited[pos.x][pos.y];}

std::stack<dir::Dir> Solver::Solve() {
    std::stack<dir::Dir>    path;
    Vect2   pos = _maze.getStart();
    Vect2   target = _maze.getExit();

    while (pos != target) {
        dir::Dir step = getNextStep(pos);

        if (step != dir::NONE) {
            path.push(step);
            pos += dir::toVect2(path.top());
            _visited[pos.x][pos.y] = true;
            continue;
        }

        if (path.empty()) { break; }
        pos -= dir::toVect2(path.top());
        path.pop();
    }

   return (reverse(path));
};

void    Solver::initVisited() {
    Vect2 start = _maze.getStart();
    Vect2   v;

    for (v.x = 0; v.x < HEIGHT; v.x++) {    
        for (v.y = 0; v.y < WIDTH; v.y++) {
            _visited[v.x][v.y] = _maze.getTile(v) == Maze::WALL;            
        }
    }

    _visited[start.x][start.y] = true;
}

dir::Dir    Solver::getNextStep(const Vect2& pos) {
    dir::Dir dirs[4] = {dir::LEFT, dir::RIGHT, dir::UP, dir::DOWN};

    for (int i = 0; i < 4; i++) {
        Vect2 neighbour = pos + dir::toVect2(dirs[i]);
        if (!isVisited(neighbour)) { return dirs[i];}
    }

    return dir::NONE;
}

std::stack<dir::Dir>    Solver::reverse(std::stack<dir::Dir> path) {
    std::stack<dir::Dir>    reversed;

    while (!path.empty()) {
        reversed.push(path.top());
        path.pop();
    }

    return reversed;
}
