
#include "Graph_Node.h"


Graph_Node::Graph_Node()
: key(-1)
, color(0)
{
}
    
unsigned Graph_Node::Get_out_Degree() const {
    return this->out.Size();
}
    
unsigned Graph_Node::Get_in_Degree() const {
    return this->in.Size();
}
    
unsigned Graph_Node::Get_key() const {
    return this->key;
}

void Graph_Node::Set_Key(unsigned int _key) {
    this->key = _key;
}

Linked_List<Graph_Edge_Struct>& Graph_Node::Get_Edges_In() {
    return this->in;
}


Linked_List<Graph_Edge_Struct>& Graph_Node::Get_Edges_Out() {
    return this->out;
}

int Graph_Node::Get_Color() const {
    return this->color;
}

void Graph_Node::Set_Color(int _color) {
    this->color = _color;
}