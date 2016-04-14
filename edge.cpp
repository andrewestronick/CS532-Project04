// Andrew Estronick
// April 10th, 2016
// Computer Science 532 - Advanced Data Structures

#include "edge.h"


Edge::Edge(const int start, const int end)
{
    init(start, end);
}


Edge::Edge(int start, int end, int weight)
{
    this->weight = weight;
    init(start, end);
}


Edge::Edge(const Edge &e)
{
        weight = e.weight;
        init(e.start, e.end);
}


Edge::Edge(Edge *e)
{
    weight = e->getWeight();
    init(e->getStart(), e->getEnd());
}


void Edge::init(int start, int end)
{
    this->start = start;
    this->end = end;
}


int Edge::getStart() const
{
    return start;
}


int Edge::getEnd() const
{
    return end;
}


double Edge::getWeight() const
{
    return weight;
}


void Edge::setStart(int start)
{
    this->start = start;
}


void Edge::setEnd(int end)
{
    this->end = end;
}


void Edge::setWeight(double weight)
{
    this->weight = weight;
}
