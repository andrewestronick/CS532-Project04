// Andrew Estronick
// April 10th, 2016
// Computer Science 532 - Advanced Data Structures

#ifndef GRAPH_H
#define GRAPH_H
#include <vector>
#include "edge.h"

struct Node
{
    Edge *edge = nullptr;
    Node *next = nullptr;
};

class Graph
{
public:

    Graph(int n, bool directed, bool weighted);
    ~Graph();
    void addEdge(const Edge &e);
    std::vector<Edge> getAdjecentList(int v);
    Edge getEdge(int v1, int v2);
    int getNumVertices(void) const;
    int getNumEdges(void) const;
    void insertNode(int vertex, Node *node);

private:

    Node **vertices;
    int size;
    int edges = 0;
    bool directed;
    bool weighted;
};

#endif // GRAPH_H
