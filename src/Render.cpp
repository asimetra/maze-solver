#include "Render.hpp"
#include <chrono>
#include <stack>
#include <iostream>
#include <algorithm>

#ifdef _WIN32
    #ifndef NOMINMAX /* windows.h defines min/max macros that break std::max */
        #define NOMINMAX
    #endif
    #include <windows.h>
#else
    #include <unistd.h>
#endif

Render::Render(const Maze& maze) : _maze(maze) {
    #ifdef _WIN32 /*https://learn.microsoft.com/en-us/cpp/preprocessor/predefined-macros*/
        SetConsoleOutputCP(CP_UTF8);
    #endif
}

void    Render::render(std::stack<dir::Dir> steps) {
    auto next_frame = std::chrono::steady_clock::now();
    auto frame_time = std::chrono::nanoseconds(1000000000 / FPS); /* 1/fps * 1e9  {1 sec = 1e9 nanosec} */  
    Vect2 pos = _maze.getStart();

    while (!steps.empty()) {
        next_frame += frame_time;
        
        clearScreen();
        pos += dir::toVect2(steps.top()); 
        renderFrame(pos, steps.top());
        steps.pop();
        
        auto remain = std::max(next_frame - std::chrono::steady_clock::now(), std::chrono::nanoseconds(0));
        waitNextFrame(std::chrono::duration_cast<std::chrono::microseconds>(remain).count());
    }

}

void    Render::renderFrame(const Vect2& pos, dir::Dir dir) {
    Vect2 v;

    for (v.x = 0; v.x < HEIGHT; v.x++) {
        for (v.y = 0; v.y < WIDTH; v.y++) {
            if (pos == v)
                std::cout << _dirChr[dir];
            else
                std::cout << (char)_maze.getTile(v);
        }
        std::cout << '\n';
    }
    std::cout << std::flush;
}



void    Render::clearScreen() {
    #ifdef _WIN32 
        system("cls"); 
    #else
        system("clear");
    #endif
}

void Render::waitNextFrame(unsigned int us) {
    #ifdef _WIN32 
        Sleep(us / 1000);
    #else  
        usleep(us);
    #endif
}

