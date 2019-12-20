#include "Graph_Edge.h"


Graph_Edge::Graph_Edge() {
}
    
unsigned int Graph_Edge::Get_From() {
    return this->from;
}
    
unsigned int Graph_Edge::Get_To() {
    return this->to;
}

void Graph_Edge::Set_Edge(unsigned int _from, unsigned int _to) {
    this->from = _from;
    this->to = _to;
}