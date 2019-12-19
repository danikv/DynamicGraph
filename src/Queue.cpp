#include "Queue.h"

Queue::Queue() 
: rear(NULL)
, front(NULL)
{
}

// A utility function to create 
// a new linked list node. 
QNode* Queue::newNode(void* node) const { 
    QNode* temp = new QNode(); 
    temp->key = node;
    temp->next = NULL;
    return temp; 
}
  
// The function to add a key k to q 
void Queue::push(void* k) { 
    // Create a new LL node 
    QNode* temp = newNode(k); 
  
    // If queue is empty, then 
    // new node is front and rear both 
    if (this->rear == NULL) { 
        this->front = this->rear = temp; 
        return; 
    } 
  
    // Add the new node at 
    // the end of queue and change rear 
    this->rear->next = temp; 
    this->rear = temp; 
} 
  
// Function to remove 
// a key from given queue q 
QNode* Queue::pop() {
    // If queue is empty, return NULL. 
    if (this->front == NULL)
        return NULL; 
  
    // Store previous front and 
    // move front one node ahead 
    QNode* temp = this->front; 
    this->front = this->front->next; 
  
    // If front becomes NULL, then 
    // change rear also as NULL 
    if (this->front == NULL) 
        this->rear = NULL; 
    return temp; 
} 

bool Queue::empty() const {
    return this->front != NULL;
}