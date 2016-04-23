#include <iostream>
#include "maze.h"

using namespace std;

int main(int argc, char *argv[])
{
    Maze m1(4);
    m1.randomizeMaze();
    m1.printMaze(false);
    m1.printWallList();
    m1.solveMaze();

    Maze m2(5);
    m2.randomizeMaze();
    m2.printMaze(false);
    m2.printWallList();
    m2.solveMaze();
    return 0;
}
