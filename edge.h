// Andrew Estronick
// April 10th, 2016
// Computer Science 532 - Advanced Data Structures

#ifndef EDGE_H
#define EDGE_H


class Edge
{
public:

    Edge(int start, int end);
    Edge(int start, int end, int weight);
    Edge(const Edge &e);
    Edge(Edge *e);
    void init(int start, int end);
    int getStart(void) const;
    int getEnd(void) const;
    double getWeight(void) const;
    void setStart(int start);
    void setEnd(int end);
    void setWeight(double weight);

private:

    int start;
    int end;
    double weight;
};

#endif // EDGE_H
