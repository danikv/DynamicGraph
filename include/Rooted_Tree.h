#ifndef ROOTED_TREE_H
#define ROOTED_TREE_H

#include "Graph_Node.h"
#include <ostream>

struct Tree_Node {
    Graph_Node* node;
    Tree_Node * parent;
    Tree_Node * left_child;
    Tree_Node * right_sibling;
};


class Rooted_Tree {

public:
    Rooted_Tree(Graph_Node* _node);
    ~Rooted_Tree();
    void Print_By_Layer(std::ostream& stream) const;
    void Preorder_Print(std::ostream& stream) const;
    Tree_Node* Insert_Left_Child(Graph_Node* _node, Tree_Node* parent) const;
    Tree_Node* Insert_Right_Sibling(Graph_Node* _node, Tree_Node* parent, Tree_Node* left_sibling) const;
    Tree_Node* Get_Root();

private:
    Tree_Node* root;
};

#endif