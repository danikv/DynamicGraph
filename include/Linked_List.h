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
        while(this->head->next != NULL) {
            Node* temp = this->head;
            this->head = this->head->next;
            delete temp;
        }
        delete this->head;
    }
    
    Node* Get_Head() {
        return head;
    }

    Node* Insert() {
        Node* new_node = new Node();
        new_node->next = head;
        new_node->prev = NULL;
        if(this->head != NULL) {
            this->head->prev = new_node;
        }
        head = new_node;
    }

    void Delete_Node(Node* node) {
        if(node->prev != NULL && node->next != NULL) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete node;
        }
        else if(node->prev != NULL) {
            //end of the list
            node->prev->next = NULL;
            delete node;
        }
        else {
            //begining of the list(no prev)
            node->next->prev = NULL;
            head = node->next;
            delete node;
        }
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

private:
    Node * head;
};

#endif