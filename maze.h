// Andrew Estronick
// March 5th, 2016
// Computer Science 532 - Advanced Data Structures

#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "tree.h"
#include "graph.h"
#include "edge.h"

struct Wall
{
    int front;
    int back;
    bool up;
};

class Maze
{
public:

    Maze(int size);
    ~Maze();
    void printMaze(bool pierceCollege);
    void printWallList(void);
    void randomizeMaze(void);
    void shuffleWall(void);

private:

    int size;
    int wallSize;
    tree *cell;
    Wall *wall;
    Graph *graph;

    void addWall(int index, int front, int back);
    bool checkWall(int front, int back);
    void initWall(void);
    void printhorizontalEdge(void);
    void printLeft(bool PierceCollege, bool start);
    void swapWall(int firstWall, int secondWall);
    void initGraph(void);
};

#endif // MAZE_H
