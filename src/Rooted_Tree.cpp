#include "Rooted_Tree.h"
#include "Queue.h"

Rooted_Tree::Rooted_Tree(Graph_Node* _node)
{
    this->root = new Tree_Node();
    this->root->node = _node;
    this->root->left_child = NULL;
    this->root->parent = NULL;
    this->root->right_sibling = NULL;
    this->root->layer = 0;
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
    if(node->node->Get_key() == 0)
        delete node->node;
    delete node;
}

Rooted_Tree::~Rooted_Tree() {
    deleteNode(root);
}

void Rooted_Tree::Print_By_Layer(std::ostream& stream) const {
    if(this->root->node == NULL)
        return;

    Queue queue;
    queue.push(this->root);
    int last_layer = 0;

    while(!queue.empty()) {
        Tree_Node* node = (Tree_Node*)queue.pop();
        if(last_layer < node->layer) {
            stream << '\n';
            last_layer = node->layer;
        }
        else if(last_layer != 0) {
            stream << ',';
        }
        while(node != NULL) {
            stream << node->node->Get_key();
            if(node->left_child != NULL) {
                queue.push(node->left_child);
            }
            if(node->right_sibling != NULL) {
                stream << ',';
            }
            node = node->right_sibling;
        }
    }
}

void Print_Recursive(std::ostream& stream, Tree_Node* root) {
    if(root->node == NULL) {
        return;
    }

    while(root != NULL) {
        stream << root->node->Get_key();
        if(root->left_child != NULL) {
            stream << ',';
            Print_Recursive(stream, root->left_child);
        }
        root = root->right_sibling;
        if(root != NULL) {
            stream << ',';
        }
    }
}
    
void Rooted_Tree::Preorder_Print(std::ostream& stream) const {
    Print_Recursive(stream, this->root);
    stream << '\n';
}

Tree_Node* Rooted_Tree::Insert_Left_Child(Graph_Node* _node, Tree_Node* parent) {
    Tree_Node* node = new Tree_Node();
    node->node = _node;
    node->parent = parent;
    node->left_child = NULL;
    node->right_sibling = NULL;
    parent->left_child = node;
    node->layer = parent->layer + 1;
    return node;
}
    
Tree_Node* Rooted_Tree::Insert_Right_Sibling(Graph_Node* _node, Tree_Node* parent, Tree_Node* left_sibling) {
    Tree_Node* node = new Tree_Node();
    node->node = _node;
    node->parent = parent;
    left_sibling->right_sibling = node;
    node->right_sibling = NULL;
    node->left_child = NULL;
    node->layer = left_sibling->layer;
    return node;
}

Tree_Node* Rooted_Tree::Get_Root() {
    return this->root;
}