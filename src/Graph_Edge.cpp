#include "Graph_Edge.h"


Graph_Edge::Graph_Edge(Graph_Edge_Struct* _in, Graph_Node* _node_in, Graph_Edge_Struct* _out, Graph_Node* _node_out)
: in{_in}
, node_in{_node_in}
, out{_out}
, node_out{_node_out}
{
}

Graph_Edge::~Graph_Edge() {
    this->node_in->Get_Edges_In().Delete_Node(this->in);
    this->node_out->Get_Edges_Out().Delete_Node(this->out);
}