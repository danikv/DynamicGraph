

class Graph_Node {

public:
    Graph_Node(unsigned int key);
    unsigned Get_out_Degree() const;
    unsigned Get_in_Degree() const;
    unsigned Get_key() const;

private:
    unsigned int key;
};