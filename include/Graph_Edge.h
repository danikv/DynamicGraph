#ifndef GRAPH_EDGE_H
#define GRAPH_EDGE_H

#include "Graph_Node.h"

struct Graph_Edge {    
    Graph_Edge_Struct* in;
    Graph_Node* node_in;
    Graph_Edge_Struct* out;
    Graph_Node* node_out;
    Graph_Edge* next;
    Graph_Edge* prev;
};

#endif