
#include "Graph_Node.h"


Graph_Node::Graph_Node()
: key(-1)
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