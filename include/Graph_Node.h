#ifndef GRAPH_NODE_H
#define GRAPH_NODE_H

#include "Linked_List.h"
#include "Graph_Edge.h"

class Graph_Node {

public:
    Graph_Node();
    unsigned Get_out_Degree() const;
    unsigned Get_in_Degree() const;
    unsigned Get_key() const;
    void Set_Key(unsigned int key);
    //Linked_List<Graph_Edge>& Get_Edges_In();
    //Linked_List<Graph_Edge>& Get_Edges_Out();

    Graph_Node* next;
    Graph_Node* prev;

private:
    unsigned int key;
    //Linked_List<Graph_Edge> in;
    //Linked_List<Graph_Edge> out;
};

#endif