
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
    if(node->Get_in_Degree() == 0 && node->Get_out_Degree() == 0)
        nodes.Delete_Node(node);
}

Graph_Edge* Dynamic_Graph::Insert_Edge(Graph_Node* from, Graph_Node* to) {
    Graph_Edge* edge = edges.Insert();
    edge->Set_Edge(from, to);
    return edge;
}
    
void Dynamic_Graph::Delete_Edge(Graph_Edge* edge) {
    edges.Delete_Node(edge);
}

unsigned int** Dynamic_Graph::Create_Adj_Matrix(unsigned int** nodes_map, unsigned int nodes_size, unsigned int edges_size) {
    unsigned ** adj_matrix = new unsigned int*[nodes_size];
    *nodes_map = new unsigned int[nodes_size];
    for(int i = 0; i < nodes_size; ++i) {
        adj_matrix[i] = new unsigned int[edges_size];
    }
    
    /*for(int i = 0; i < edges_size; ++i) {
        adj_matrix[]
    }*/
    return adj_matrix;
}
    
Rooted_Tree* Dynamic_Graph::SCC() const {
    Rooted_Tree * tree = new Rooted_Tree();
    return tree;
}

    
Rooted_Tree* Dynamic_Graph::BFS(Graph_Node* source) const {
    Rooted_Tree * tree = new Rooted_Tree();
    return tree;
}