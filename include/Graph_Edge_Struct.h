#ifndef GRAPH_EDGE_STRUCT_H
#define GRAPH_EDGE_STRUCT_H


class Graph_Node;

struct Graph_Edge_Struct {
    Graph_Node* in_node;
    Graph_Node* out_node;

    Graph_Edge_Struct* next;
    Graph_Edge_Struct* prev;

};

#endif