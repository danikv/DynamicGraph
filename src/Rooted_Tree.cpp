#include "Rooted_Tree.h"

Rooted_Tree::Rooted_Tree(Graph_Node* _node)
{
    root = new Tree_Node();
    root->node = _node;
    root->left_child = NULL;
    root->parent = NULL;
    root->right_sibling = NULL;
}

void deleteNode(Tree_Node* node) {
    if(node == NULL)
        return;
    if(node->left_child != NULL) {
        if(node->right_sibling != NULL) {
            deleteNode(node->right_sibling);
        }
        deleteNode(node->left_child);
    }
    delete node;
}

Rooted_Tree::~Rooted_Tree() {
    deleteNode(root);
}

void Rooted_Tree::Print_By_Layer(std::ostream& stream) const {
    if(this->root->node == NULL)
        return;

    
    //recursive_print(stream, this->root->left_child);
}
    
void Rooted_Tree::Preorder_Print(std::ostream& stream) const {
    
}

Tree_Node* Rooted_Tree::Insert_Left_Child(Graph_Node* _node, Tree_Node* parent) const {
    Tree_Node* node = new Tree_Node();
    node->node = _node;
    node->parent = parent;
    node->left_child = NULL;
    node->right_sibling = NULL;
    return node;
}
    
Tree_Node* Rooted_Tree::Insert_Right_Sibling(Graph_Node* _node, Tree_Node* parent, Tree_Node* left_sibling) const {
    Tree_Node* node = new Tree_Node();
    node->node = _node;
    node->parent = parent;
    left_sibling->right_sibling = node;
    node->right_sibling = NULL;
    node->left_child = NULL;
    return node;
}

Tree_Node* Rooted_Tree::Get_Root() {
    return this->root;
}