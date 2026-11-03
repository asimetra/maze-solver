#include <iostream>
#include "Maze.hpp"
#include "Solver.hpp"
#include "Render.hpp"

int main(int ac, char** av) {
    if (ac > 2) {
        std::cout << "Usage: " << av[0] << " [map_file]" << std::endl;
        return 1;
    }

    std::string mapFile = (ac == 2) ? av[1] : "maze/default.txt";
    try {
        const Maze& maze = Maze::fromFile(mapFile);
        
        std::stack<dir::Dir> steps = Solver(maze).Solve();
        if (steps.empty()) {
            std::cout << "No solution found." << std::endl;
            return 1;
        }
        Render render = Render(maze);
        render.render(steps);
    } catch (std::exception &err) {
        std::cerr << "error: " << err.what() << std::endl; 
        return 1;
    }

    return 0;
}

