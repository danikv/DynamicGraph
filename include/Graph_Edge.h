

class Graph_Edge {

public:
    Graph_Edge(unsigned int from, unsigned int to);
    unsigned get_from();
    unsigned get_to();

private:
    unsigned from;
    unsigned to;
};