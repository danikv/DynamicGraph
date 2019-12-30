#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <cstddef>

template<typename Node>
class Linked_List {

public:
    Linked_List()
    : head(NULL)
    {
    }

    ~Linked_List() {
        while(this->head != NULL) {
            Node* temp = this->head;
            this->head = this->head->next;
            delete temp;
        }
    }
    
    Node* Get_Head() const {
        return head;
    }

    Node* Insert() {
        Node* new_node = new Node();
        new_node->next = this->head;
        new_node->prev = NULL;
        if(this->head != NULL) {
            this->head->prev = new_node;
        }
        this->head = new_node;
        return new_node;
    }

    void Delete_Node(Node* node) {
        if(node->prev != NULL) {
            node->prev->next = node->next;
        }
        else {
            this->head = node->next;
        }

        if(node->next != NULL) {
            node->next->prev = node->prev;
        }
        delete node;
    }

    unsigned int Size() const {
        Node* temp = this->head;
        unsigned int size = 0;
        while(temp != NULL) {
            size++;
            temp = temp->next;
        }
        return size;
    }

    bool isEmpty() {
        return this->head == NULL;
    }

private:
    Node * head;
};

#endif