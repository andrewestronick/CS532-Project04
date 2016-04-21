// Andrew Estronick
// March 5th, 2016
// Computer Science 532 - Advanced Data Structures

#include "maze.h"

Maze::Maze(int size)
{
    this->size = size;
    wallSize = (2 * size * size) - (2 * size);

    cell = new tree(size * size);
    wall = new Wall[wallSize];
    graph = new Graph(size * size, false, false);

    initWall();
}


Maze::~Maze()
{
    delete cell;
    delete wall;
    delete graph;
}


void Maze::printMaze(bool pierceCollege)
{
    const std::string destination = "Computer Class";

    printLeft(pierceCollege,false);
    printhorizontalEdge();

    for(int j = 0; j < size; ++j)
    {
        printLeft(pierceCollege, (0 == j));
        std::cout << ((j ==0) ? "   " : "|  ");

        for(int i = 0; i < size - 1; ++i)
            std::cout << (checkWall(i + j * size, 1 + i + j * size) ? "|  " : "   ");

        if(j == size - 1)
            std::cout << "   " << destination << std::endl;
        else
            std::cout << "|  " << std::endl;

        if(j < size -1)
        {
            printLeft(pierceCollege, false);
            for(int i = 0; i < size; ++i)
                std::cout << (checkWall(i + j * size, i + (j + 1) * size) ? "+--" : "+  ");
            std::cout << "+" << std::endl;
        }
    }

    printLeft(pierceCollege, false);
    printhorizontalEdge();
}


void Maze::printWallList(void)
{
    for(int i=0; i < wallSize; ++i)
        std::cout << "Wall #" << (i + 1) << " (" << wall[i].front << ", " << wall[i].back << ") " << (wall[i].up ? "UP" : "DOWN") << std::endl;
}


void Maze::randomizeMaze()
{
    shuffleWall();

    for(int i = 0; i < wallSize; ++i)
        if(!cell->intersect(wall[i].front, wall[i].back))
        {
            cell->wunion(wall[i].front, wall[i].back);
            wall[i].up = false;
        }
    initGraph();
}


void Maze::shuffleWall(void)
{
    std::srand(std::time(0));

    for(int i = 0; i < wallSize; ++i)
        swapWall(i, std::rand() % wallSize);
}


void Maze::solveMaze()
{
    initGraph();

    bool visit[size * size];
    for(int i = 0; i < size * size; ++i)
        visit[i] = false;

    solution.clear();

    rdfs(0, visit);

    std::cout << "Solution: ";
    for(int i = solution.size() - 1; i >= 0; --i)
        std::cout << solution[(unsigned) i] << " ";

    std::cout << std::endl;
}

bool Maze::rdfs(int v, bool *visit)
{
    bool flag = (v == size * size - 1);
    visit[v] = true;

    std::vector<Edge> list = graph->getAdjecentList(v);
    for(Edge e : list)
    {
        if(visit[e.getEnd()])
            continue;
        if(rdfs(e.getEnd(), visit))
           flag = true;
    }

    if(flag)
        solution.push_back(v);

    return flag;
}


void Maze::addWall(int index, int front, int back)
{
        wall[index].front = front;
        wall[index].back = back;
        wall[index].up = true;
}


bool Maze::checkWall(int front, int back)
{
    for(int i = 0; i < wallSize; ++i)
        if((wall[i].front == front && wall[i].back == back ) || (wall[i].front == back && wall[i].back == front))
            return wall[i].up;

    return false;
}


void Maze::initWall(void)
{
    for (int i = 0, j, k = 0; i < ((size * size) - 1); ++i)
    {
        j = i + 1;
        if((j % size) != 0)
            addWall(k++, i, j);

        j = i + size;
        if (j < (size * size))
            addWall(k++, i, j);
    }
}


void Maze::printhorizontalEdge(void)
{
    for(int i = 0; i < size; ++i)
        std::cout << "+--";

    std::cout << "+" << std::endl;
}


void Maze::printLeft(bool pierceCollege, bool start)
{
    const std::string startLocation = "Pierce College Parking Lot";
    const std::string space = std::string(startLocation.length(), ' ');

    if(start)
        std::cout << (pierceCollege ? startLocation : "");
    else
        std::cout << (pierceCollege ? space : "");
}


void Maze::swapWall(int firstWall, int secondWall)
{
    Wall tempWall;

    tempWall.front = wall[firstWall].front;
    tempWall.back = wall[firstWall].back;
    tempWall.up = wall[firstWall].up;

    wall[firstWall].front = wall[secondWall].front;
    wall[firstWall].back = wall[secondWall].back;
    wall[firstWall].up = wall[secondWall].up;

    wall[secondWall].front = tempWall.front;
    wall[secondWall].back = tempWall.back;
    wall[secondWall].up = tempWall.up;
}


void Maze::initGraph()
{
    for(int i = 0; i < wallSize; ++i)
        if(!wall[i].up && !graph->edgeExist(wall[i].front, wall[i].back) && !graph->edgeExist(wall[i].back, wall[i].front))
                graph->addEdge(Edge(wall[i].front, wall[i].back));
}
