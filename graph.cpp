// Andrew Estronick
// April 10th, 2016
// Computer Science 532 - Advanced Data Structures

#include "graph.h"


Graph::Graph(int n, bool directed, bool weighted)
{
    size = n;
    vertices = new Node*[size];
    for(int i = 0; i < size; ++i)
        vertices[i] = nullptr;

    this->directed = directed;
    this->weighted = weighted;
}


Graph::~Graph()
{
    for(int i = 0; i < size; ++i)
    {
        if(nullptr == vertices[i])
            continue;

        Node *ptr2, *ptr1 = vertices[i];
        while(ptr1 != nullptr)
        {
            delete ptr1->edge;
            ptr2 = ptr1;
            ptr1 = ptr1->next;
            delete ptr2;
        }
    }
    delete vertices;
}

void Graph::addEdge(const Edge &e)
{
    Node *node = new Node;
    node->edge = new Edge(e);

    insertNode(node->edge->getStart(), node);

    if(!directed)
    {
        Node *rnode = new Node;
        rnode->edge = new Edge(e.getEnd(), e.getStart(), e.getWeight());

        insertNode(rnode->edge->getStart(), rnode);
    }
}


std::vector<Edge> Graph::getAdjecentList(int v)
{
    std::vector<Edge> list;
    if(nullptr == vertices[v])
        return list;

    Node *ptr = vertices[v];

    do
    {
        list.emplace_back(Edge(ptr->edge));
        ptr = ptr->next;
    } while(ptr != nullptr);

    delete ptr;
    return list;
}


Edge Graph::getEdge(int v1, int v2)
{
    if(nullptr == vertices[v1])
        return nullptr;

    Node *ptr = vertices[v1];

    while(ptr->next != nullptr)
    {
        if(ptr->edge->getEnd() == v2)
            return Edge(ptr->edge);

        ptr = ptr->next;
    }

    return nullptr;
}


int Graph::getNumVertices() const
{
    return size;
}


int Graph::getNumEdges() const
{
    return edges;
}


void Graph::insertNode(int vertex, Node *node)
{
    if(nullptr == vertices[vertex])
    {
        vertices[vertex] = node;
    }
    else
    {
        Node *ptr = vertices[vertex];
        while(ptr->next != nullptr)
            ptr = ptr->next;
        ptr->next = node;
    }
    ++edges;
}
