#include <iostream>
#include "maze.h"

using namespace std;

int main(int argc, char *argv[])
{
    Maze m1(3);
    m1.randomizeMaze();
    m1.printMaze(false);
    m1.solveMaze();
    return 0;
}
