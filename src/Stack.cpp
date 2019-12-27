#include "Stack.h"

Stack::Stack() 
: head(NULL)
{
}
    
Stack::~Stack() {
    while(this->head != NULL) {
        SNode* temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
}

void* Stack::pop() {
    if(this->head == NULL) {
        return NULL;
    }

    void* return_value = this->head->data;
    SNode* temp = this->head;
    this->head = this->head->next;
    delete temp;
    return return_value;
}
    
void Stack::push(void * _data) {
    SNode* node = new SNode();
    node->data = _data;
    node->next = this->head;
    this->head = node;
}
    
bool Stack::empty() const {
    return this->head == NULL;
}
