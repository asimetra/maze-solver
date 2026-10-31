#include <iostream>
#include "Maze.hpp"

/*
    Parse Maze -> Solve -> Render

    Valid Maze:
    just 1 enter & exit;
    every line end with \n;
    sequantial exit & enter is not valid;
*/

int main(int ac, char** av) {
    if (ac > 2) {
        std::cout << "Usage: " << av[0] << " [map_file]" << std::endl;
        return -1;
    }

    std::string mapFile = (ac == 2) ? av[1] : "maze/default.txt";
    try {
        const Maze& maze = Maze::fromFile(mapFile);
        (void)maze;
        // Solver.solve
        //render
    } catch (std::exception &err) {
        std::cerr << "error: " << err.what() << std::endl; 
    }

    return 0;
}

