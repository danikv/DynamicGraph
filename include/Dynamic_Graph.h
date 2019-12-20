#ifndef DYNAMIC_GRAPH_H
#define DYNAMIC_GRAPH_H

#include "Rooted_Tree.h"
#include "Graph_Node.h"
#include "Graph_Edge.h"

class Dynamic_Graph {

public:
    Dynamic_Graph();
    ~Dynamic_Graph();
    Graph_Node* Insert_Node(unsigned node_key);
    void Delete_Node(Graph_Node* node);
    Graph_Edge* Insert_Edge(Graph_Node* from, Graph_Node* to);
    void Delete_Edge(Graph_Edge* edge);
    Rooted_Tree* SCC() const;
    Rooted_Tree* BFS(Graph_Node* source) const;

private:
    Linked_List<Graph_Node> nodes;
    Linked_List<Graph_Edge> edges;
};

#endif