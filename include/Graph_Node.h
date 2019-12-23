#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H

#include "Graph_Edge_Struct.h"
#include "Linked_List.h"

class Graph_Node {

public:
    Graph_Node();
    unsigned Get_out_Degree() const;
    unsigned Get_in_Degree() const;
    unsigned Get_key() const;
    void Set_Key(unsigned int key);
    Linked_List<Graph_Edge_Struct>& Get_Edges_In();
    Linked_List<Graph_Edge_Struct>& Get_Edges_Out();

    Graph_Node* next;
    Graph_Node* prev;

private:
    unsigned int key;
    Linked_List<Graph_Edge_Struct> in;
    Linked_List<Graph_Edge_Struct> out;
};

#endif