#include "Rooted_Tree.h"
#include "Queue.h"

Rooted_Tree::Rooted_Tree() 
: root(NULL)
{
}

void deleteNode(Tree_Node* node) {
    if(node == NULL)
        return;
    if(node->left != NULL) {
        deleteNode(node->left);
        delete node->right;
    }
    if(node->right != NULL) {
        deleteNode(node->right);
        delete node->right;
    }
    delete node;
}

Rooted_Tree::~Rooted_Tree() {
    deleteNode(root);
}

void Rooted_Tree::Print_By_Layer(std::ostream& stream) const {
    if(root == NULL)
        return;
    
    Queue q;
    q.push(root); 
  
    while (q.empty() == false) 
    { 
        // Print front of queue and remove it from queue 
        Tree_Node *node = (Tree_Node*) q.pop();
        stream << node->key << " "; 
        q.pop(); 
  
        /* Enqueue left child */
        if (node->left != NULL) 
            q.push(node->left); 
  
        /*Enqueue right child */
        if (node->right != NULL) 
            q.push(node->right); 
    } 
}
    
void Rooted_Tree::Preorder_Print(std::ostream& stream) const {
    
}