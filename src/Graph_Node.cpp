
#include "Graph_Node.h"


Graph_Node::Graph_Node(unsigned int _key)
: key(_key)
{
}
    
unsigned Graph_Node::Get_out_Degree() const {
    return 0;
}
    
unsigned Graph_Node::Get_in_Degree() const {
    return 0;
}
    
unsigned Graph_Node::Get_key() const {
    return key;
}