
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
    Graph_Node * empty_node = new Graph_Node();
    empty_node->Set_Key(0);
    Rooted_Tree * tree = new Rooted_Tree(empty_node);
    DFS(tree);
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
                        left_sibling = Rooted_Tree::Insert_Left_Child(temp->in_node, current);
                    }
                    else {
                        left_sibling = Rooted_Tree::Insert_Right_Sibling(temp->in_node, current, left_sibling);
                    }
                    queue.push(left_sibling);
                    temp->in_node->Set_Color(1);
                }
                temp = temp->next;
            }
            current->node->Set_Color(2);
        }
    }

    setNodesColorToWhite();
    return tree;
}

Tree_Node* DFS_Util(Graph_Node* node, Tree_Node* parent, Tree_Node* left_sibling) {
    node->Set_Color(1);
    Tree_Node* starting_node = NULL;
    if(left_sibling == NULL) {
        starting_node = Rooted_Tree::Insert_Left_Child(node, parent);
    }
    else {
        starting_node = Rooted_Tree::Insert_Right_Sibling(node, parent, left_sibling);
    }

    Graph_Edge_Struct* starting_edge = node->Get_Edges_Out().Get_Head();
    Tree_Node* last_inserted_node = NULL;
    while(starting_edge != NULL) {
        if(starting_edge->in_node->Get_Color() == 0) {
            last_inserted_node = DFS_Util(starting_edge->in_node, starting_node, last_inserted_node);
        }
        starting_edge = starting_edge->next;
    }
    node->Set_Color(2);
    return starting_node;
}

void Dynamic_Graph::DFS(Rooted_Tree* tree) const {
    Graph_Node* node = this->nodes.Get_Head();
    Tree_Node* left_sibling = NULL;
    while(node != NULL) {
        if(node->Get_Color() == 0) {
            left_sibling = DFS_Util(node, tree->Get_Root(), left_sibling);
        }
        node = node->next;
    }
    setNodesColorToWhite();
}

void Dynamic_Graph::setNodesColorToWhite() const{
    Graph_Node* temp = this->nodes.Get_Head();
    while(temp != NULL) {
        temp->Set_Color(0);
        temp = temp->next;
    }
}