
#include "Dynamic_Graph.h"

    
Dynamic_Graph::Dynamic_Graph() {
}
    
Dynamic_Graph::~Dynamic_Graph() {
}

Graph_Node* Dynamic_Graph::Insert_Node(unsigned node_key) {
    Graph_Node* new_node = nodes.Insert();
    new_node->Set_Key(node_key);
    return new_node;
}
    
void Dynamic_Graph::Delete_Node(Graph_Node* node) {
    nodes.Delete_Node(node);
}

Graph_Edge* Dynamic_Graph::Insert_Edge(Graph_Node* from, Graph_Node* to) {
    Graph_Edge* edge = edges.Insert();
    edge->Set_Edge(from->Get_key(), to->Get_key());
    return edge;
}
    
void Dynamic_Graph::Delete_Edge(Graph_Edge* edge) {
    edges.Delete_Node(edge);
}
    
Rooted_Tree* Dynamic_Graph::SCC() const {
    Rooted_Tree * tree = new Rooted_Tree();
    return tree;
}

    
Rooted_Tree* Dynamic_Graph::BFS(Graph_Node* source) const {
    Rooted_Tree * tree = new Rooted_Tree();
    return tree;
}