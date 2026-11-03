NAME = MazeSolver

SRCS = src/main.cpp \
	src/Maze.cpp \
	src/Vect2.cpp \
	src/Render.cpp \
	src/Solver.cpp

OBJS = $(SRCS:.cpp=.o)

CXX = g++

CXXFLAGS = -Wall -Wextra -std=c++11  -Iinclude -g

# Windows sets OS=Windows_NT; force cmd.exe so the result does not depend on whether sh.exe is in PATH
ifeq ($(OS),Windows_NT)
    SHELL := cmd.exe
    TARGET = $(NAME).exe
    RM = del /Q /F
    FIX = $(subst /,\,$1)
    RUN = $(TARGET)
else
    TARGET = $(NAME)
    RM = rm -f
    FIX = $1
    RUN = ./$(TARGET)
endif

all: $(TARGET)

$(TARGET): $(OBJS)
	@$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

run: all
	@$(RUN)

clean:
	-@$(RM) $(call FIX,$(OBJS))

fclean: clean
	-@$(RM) $(call FIX,$(TARGET))

re: fclean all

.PHONY: all run clean fclean re
