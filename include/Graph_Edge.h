#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H

#include "Graph_Node.h"

class Graph_Edge {

public:
    Graph_Edge();
    ~Graph_Edge();
    Graph_Node* Get_From();
    Graph_Node* Get_To();
    void Set_Edge(Graph_Node* _from, Graph_Node* _to);

    Graph_Edge* next;
    Graph_Edge* prev;

private:
    Graph_Node* from;
    Graph_Node* to;
};

#endif