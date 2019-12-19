#include "Graph_Edge.h"


Graph_Edge::Graph_Edge(unsigned int _from, unsigned int _to)
: from{_from}
, to{_to}
{
}
    
unsigned int Graph_Edge::get_from() {
    return from;
}
    
unsigned int Graph_Edge::get_to() {
    return to;
}