#include "Queue.h"
#include <cstddef>

Queue::Queue() 
: rear(NULL)
, front(NULL)
{
}

Queue::~Queue() {
    while(this->front != NULL) {
        QNode* temp = this->front;
        this->front = this->front->next;
        delete temp;
    }
}

QNode* Queue::newNode(void* node) const { 
    QNode* temp = new QNode(); 
    temp->key = node;
    temp->next = NULL;
    return temp; 
}

void Queue::push(void* k) {  
    QNode* temp = newNode(k); 

    if (this->rear == NULL) { 
        this->front = this->rear = temp; 
        return; 
    } 

    this->rear->next = temp; 
    this->rear = temp; 
} 

void* Queue::pop() {
    if (this->front == NULL)
        return NULL; 

    QNode* temp = this->front; 
    this->front = this->front->next;

    if (this->front == NULL) 
        this->rear = NULL; 
    void* key = temp->key;
    delete temp;
    return key; 
} 

bool Queue::empty() const {
    return this->front == NULL;
}