#include "Graph_Edge.h"


Graph_Edge::Graph_Edge() {
}

Graph_Edge::~Graph_Edge() {
    this->from->Set_Out_Deg(this->from->Get_out_Degree() - 1);
    this->to->Set_In_Deg(this->to->Get_in_Degree() - 1);
}
    
Graph_Node* Graph_Edge::Get_From() {
    return this->from;
}
    
Graph_Node* Graph_Edge::Get_To() {
    return this->to;
}

void Graph_Edge::Set_Edge(Graph_Node* _from, Graph_Node* _to) {
    this->from = _from;
    this->to = _to;
    this->from->Set_Out_Deg(this->from->Get_out_Degree() + 1);
    this->to->Set_In_Deg(this->to->Get_in_Degree() + 1);
}