#ifndef STACK_H
#define STACK_H

#include "Linked_List.h"

struct SNode {
    void * data;
    SNode * next;
};

class Stack {
    
public:
    Stack();
    ~Stack();

    void* pop();
    void push(void * key);
    bool empty() const;

private:
    SNode * head;
};


#endif