#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H

class Graph_Edge {

public:
    Graph_Edge();
    unsigned int Get_From();
    unsigned int Get_To();
    void Set_Edge(unsigned int _from, unsigned int _to);

    Graph_Edge* next;
    Graph_Edge* prev;

private:
    unsigned int from;
    unsigned int to;
};

#endif