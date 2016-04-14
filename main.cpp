#include <iostream>
#include "maze.h"

using namespace std;

int main(int argc, char *argv[])
{
    Maze m1(8);
    m1.randomizeMaze();
    m1.printMaze(false);
    return 0;
}
