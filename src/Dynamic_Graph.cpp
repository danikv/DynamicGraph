
#include "Dynamic_Graph.h"
#include "Queue.h"
#include <iostream>

    
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
    if(node->Get_Edges_In().isEmpty() && node->Get_Edges_Out().isEmpty())
        nodes.Delete_Node(node);
}

Graph_Edge* Dynamic_Graph::Insert_Edge(Graph_Node* from, Graph_Node* to) {
    Graph_Edge_Struct* edge_from = from->Get_Edges_Out().Insert();
    edge_from->in_node = to;
    edge_from->out_node = from;
    Graph_Edge_Struct* edge_in = to->Get_Edges_In().Insert();
    edge_in->in_node = to;
    edge_in->out_node = from;
    Graph_Edge* edge = new Graph_Edge(edge_in, to, edge_from, from);
    return edge;
}
    
void Dynamic_Graph::Delete_Edge(Graph_Edge* edge) {
    delete edge;
    return;
}
    
Rooted_Tree* Dynamic_Graph::SCC() const {
    Rooted_Tree * tree = new Rooted_Tree(0);
    return tree;
}
    
Rooted_Tree* Dynamic_Graph::BFS(Graph_Node* source) const {
    Rooted_Tree * tree = new Rooted_Tree(source);
    Queue queue;
    queue.push(tree->Get_Root());
    while(!queue.empty()) {
        Tree_Node* current = (Tree_Node*)queue.pop();
        if(current->node->Get_Color() !=  2 && !current->node->Get_Edges_Out().isEmpty()) {
            Graph_Edge_Struct* temp = current->node->Get_Edges_Out().Get_Head();
            Tree_Node* left_sibling = NULL;
            while(temp != NULL) {
                if(temp->in_node->Get_Color() == 0) {
                    if(left_sibling == NULL) {
                        left_sibling = tree->Insert_Left_Child(temp->in_node, current);
                    }
                    else {
                        left_sibling = tree->Insert_Right_Sibling(temp->in_node, current, left_sibling);
                    }
                    queue.push(left_sibling);
                    temp->in_node->Set_Color(1);
                }
                temp = temp->next;
            }
            current->node->Set_Color(2);
        }
    }

    Graph_Node* temp = this->nodes.Get_Head();
    while(temp != NULL) {
        temp->Set_Color(0);
        temp = temp->next;
    }
    return tree;
}