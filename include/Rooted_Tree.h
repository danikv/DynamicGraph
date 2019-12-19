#include <iostream>


class Rooted_Tree {

public:
    Rooted_Tree();
    ~Rooted_Tree();
    void Print_By_Layer(std::ostream& stream) const;
    void Preorder_Print(std::ostream& stream) const;

};