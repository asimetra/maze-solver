CXX      = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -I ./include/ -g
OBJS     = lib/main.o lib/Maze.o lib/Vect2.o lib/Solver.o lib/Render.o

ifeq ($(OS),Windows_NT)
    SHELL  := cmd.exe
    TARGET  = bin/MazeSolver.exe
    RUN     = bin\MazeSolver.exe
    CLEAN   = del /Q /F lib\*.o bin\MazeSolver.exe
else
    TARGET  = bin/MazeSolver
    RUN     = ./bin/MazeSolver
    CLEAN   = rm -f lib/*.o bin/MazeSolver
endif

all: $(TARGET)
	$(RUN)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

lib/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	-$(CLEAN)

re: clean all

.PHONY: all clean re
