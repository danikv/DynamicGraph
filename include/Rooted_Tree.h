#include <ostream>


struct Tree_Node {
    unsigned int key;
    Tree_Node * left;
    Tree_Node * right;
};


class Rooted_Tree {

public:
    Rooted_Tree();
    ~Rooted_Tree();
    void Print_By_Layer(std::ostream& stream) const;
    void Preorder_Print(std::ostream& stream) const;

private:
    Tree_Node* root;
};