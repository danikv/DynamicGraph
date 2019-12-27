#ifndef QUEUE_H
#define QUEUE_H


struct QNode { 
    void* key; 
    QNode* next; 
}; 

class Queue {

public:

    Queue();
    ~Queue();
    void push(void* k);
    void* pop();
    bool empty() const;

private: 

    QNode* newNode(void* k) const;
    QNode *front, *rear; 
};

#endif 
