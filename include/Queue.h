
struct QNode { 
    void* key; 
    QNode* next; 
}; 
  
// The queue, front stores the front node 
// of LL and rear stores the last node of LL 
class Queue {

public:

    Queue();
    void push(void* k);
    QNode* pop();
    bool empty() const;

private: 

    QNode* newNode(void* k) const;
    QNode *front, *rear; 
};