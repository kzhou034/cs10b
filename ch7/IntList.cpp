#include "IntList.h"
#include <iostream>
using namespace std;

IntList::IntList() {
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList() {
    //IntNode *temp = head;
    while (head != nullptr) {
        pop_front();
    }
    //delete temp;
}

void IntList::push_front(int value) {
    IntNode *tmp = new IntNode(value);
    tmp->next = head;
    head = tmp;
    if (tail == nullptr) {
        tail = head;
    }
}

void IntList::pop_front() {
    IntNode *tempNext = nullptr;
    if (head != nullptr) {
        tempNext = head->next;
        head = nullptr;
        delete head;
        head = tempNext;
    }
    else if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
}

bool IntList::empty() const {
    bool status = false;
    if (head == nullptr) {
        status = true;
    }
    return status;
}

const int & IntList::front() const {
    return head->value;
}

const int & IntList::back() const {
    return tail->value;
}

ostream & operator<<(ostream &out, const IntList &list) {
    IntNode *temp = list.head;
    //IntNode *temp2 = list.tail;
    while (temp != nullptr) {
        if (temp->next != nullptr) {
            out << temp->value << " ";
        }
        else {
            out << temp->value;
        }        
        temp = temp->next;
    }
    return out;
}