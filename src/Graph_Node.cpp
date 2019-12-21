
#include "Graph_Node.h"


Graph_Node::Graph_Node()
: key(-1)
, in_deg(0)
, out_deg(0)
{
}
    
unsigned Graph_Node::Get_out_Degree() const {
    return this->out_deg;
}
    
unsigned Graph_Node::Get_in_Degree() const {
    return this->in_deg;
}
    
unsigned Graph_Node::Get_key() const {
    return this->key;
}

void Graph_Node::Set_Key(unsigned int _key) {
    this->key = _key;
}

void Graph_Node::Set_In_Deg(unsigned int _in_deg) {
    this->in_deg = _in_deg;
}

void Graph_Node::Set_Out_Deg(unsigned int _out_deg) {
    this->out_deg = _out_deg;
}

/*Linked_List<Graph_Edge> Graph_Node::Get_Edges_In() {
    return this->in;
}


Linked_List<Graph_Edge> Graph_Node::Get_Edges_Out() {
    return this->out;
}*/