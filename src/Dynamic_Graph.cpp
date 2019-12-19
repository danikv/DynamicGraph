
#include "Dynamic_Graph.h"

    
Dynamic_Graph::Dynamic_Graph() {

}
    
Dynamic_Graph::~Dynamic_Graph() {

}

Graph_Node* Dynamic_Graph::Insert_Node(unsigned node_key) {
    return new Graph_Node(5);
}
    
void Dynamic_Graph::Delete_Node(Graph_Node* node) {

}

Graph_Edge* Dynamic_Graph::Insert_Edge(Graph_Node* from, Graph_Node* to) {
    return new Graph_Edge(5, 10);
}
    
void Dynamic_Graph::Delete_Edge(Graph_Edge* edge) {

}
    
Rooted_Tree* Dynamic_Graph::SCC() const {
    Rooted_Tree * tree = new Rooted_Tree();
    return tree;
}

    
Rooted_Tree* Dynamic_Graph::BFS(Graph_Node* source) const {
    Rooted_Tree * tree = new Rooted_Tree();
    return tree;
}