#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H

#include "Graph_Node.h"

class Graph_Edge {

public:
    Graph_Edge(Graph_Edge_Struct* _in, Graph_Node* _node_in, Graph_Edge_Struct* _out, Graph_Node* _node_out);
    ~Graph_Edge();

private:
    Graph_Edge_Struct* in;
    Graph_Node* node_in;
    Graph_Edge_Struct* out;
    Graph_Node* node_out;
};

#endif