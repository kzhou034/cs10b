#include "IntList.h"
#include <iostream>
using namespace std;

IntList::IntList() {
    head = nullptr;
    tail = nullptr;
}

IntList::~IntList() {
    //IntNode *temp = head;
  /*  while (head != nullptr) {
        pop_front();
    } */
    //delete temp;
    clear();  //basically does what destructor does
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
    //IntNode *temp = head;
    if (head == tail) {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else if (head != nullptr) {
        head = head->next;
    }
    //delete temp;
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

//the copy constructor. Make sure this performs deep copy.
IntList::IntList(const IntList &cpy) {
    //IntList copyOfCpy;
    head = nullptr;
    tail = nullptr;
    IntNode *temp = nullptr;
    for (temp = cpy.head; temp != nullptr; temp = temp->next) {
        //copyOfCpy.push_back(temp->value);
        push_back(temp->value);
    }
}

/*the overloaded assignment operator. 
Make sure this performs deep copy.*/
IntList & IntList::operator=(const IntList &rhs) {
    if (this != &rhs) {
        head = nullptr;
        tail = nullptr; 
        IntNode *temp;
        for (temp = rhs.head; temp != nullptr; temp = temp->next) {
            push_back(temp->value);
        }
    }
    else { //if this == &rhs, does nothing --> ends the function
        return *this;
    }
    return *this;
}

/*Inserts a data value (within a new node) 
at the back end of the list.*/
void IntList::push_back(int value) {
    /*  from push_front:
        IntNode *tmp = new IntNode(value);
        tmp->next = head;
        head = tmp;
        if (tail == nullptr) {
            tail = head;
        } */
    IntNode *temp = new IntNode(value);
    if (head == nullptr) {
        /*head = temp; //if head == nullptr, it is an empty list, so one new node(value) is added
        tail = head; //therefore head and tail are the same*/
        push_front(value);
    }
    else {
        tail->next = temp; //sets what is after the tail to the new node(value)
        tail = tail->next; //sets tail to the next value; last value is new tail
    }
}

/*Removes (deallocates) all IntNodes in the IntList. 
Don't forget to set both head and tail to appropriate 
values for an empty list. DO NOT leave them dangling!*/
void IntList::clear() {
    while (head != nullptr) {
        pop_front();
    }
}

/*Sorts the integers in the list into ascending order. 
Do NOT move the nodes, just the integers.*/
void IntList::selection_sort() { //sorts ints lowest to highest
    IntNode *temp = head;
    for (temp = head; temp != nullptr; temp = temp->next) { //loops through nodes until nullptr
        IntNode *temp2 = temp->next; //below starts at node after temp
        for (temp2 = temp->next; temp2 != nullptr; temp2 = temp2->next) { //loops through nodes until nullptr 
            if (temp->value > temp2->value) { //checks if value of node stored in temp is greater than the one stored in temp2
                int switchInt = temp->value; //temp stored in switchInt. temp > temp2
                temp->value = temp2->value; //if temp > temp2, temp is assigned temp2
                temp2->value = switchInt; //new value of temp2 is switchInt
            }
        }
    }
}

/*Inserts a data value (within a new node) in an ordered list. 
Assumes the list is already sorted in ascending order 
(i.e., Do not sort the list first, assume the 
list is already is sorted.) This function loops through 
the list until if finds the correct position for the new 
data value and then inserts the new IntNode in that location. 
This function may NOT ever sort the list.*/
void IntList::insert_ordered(int value) {
    /* push_front: //shifts evething over by one
    IntNode *tmp = new IntNode(value);
    tmp->next = head;
    head = tmp;
    if (tail == nullptr) {
        tail = head;
    }
    */
    bool listEmpty = empty(); //function returns if list is empty or not
    if (listEmpty == true) {
        push_front(value); //if list is empty, insert the value into the front
    }
    else if (tail == head) {
        if (value > head->value) {
            push_back(value); //if list has one node, and int value is greater than node, insert @ end
        }
        else {
            push_front(value); //if list has one node, and int value is less than node, insert @ front
        }
    }
    else if (value <= head->value) {
        push_front(value); //if value < tail, insert @ front
    }
    else if (value >= tail->value){
        push_back(value); //if value > tail, insert @ end
    }
    else {
        //cout << endl << "helo" << endl << endl;
        IntNode *newNode = new IntNode(value); 
        //temp is lower bound, temp2 is higher bound
        IntNode *temp = head;
        IntNode *temp2 = temp->next;
        for (temp2 = temp->next; temp2 != nullptr; temp2 = temp2->next) { //loop starts w/ node after head
            //cout << "testing" << endl;
            if ((newNode->value > temp->value) && (newNode->value <= temp2->value)) {
                //cout << "testing2" << endl;
                //IntNode *saveNode = temp2;
                temp->next = newNode; //node after temp is assigned newNode
                newNode->next = temp2; //what is after newNode is temp2
            }
            temp = temp->next; //iterates temp
        }
        //cout << endl << "helooooo" << endl << endl;
    }
}

/*Removes all duplicate data values (actually removes the nodes that 
contain the values) within the list. Always remove just the 
later value within the list when a duplicate is found. 
This function may NOT ever sort the list.*/

void IntList::remove_duplicates() { //30 10 20 10 -> 30 10 20
    IntNode *i; 
    IntNode *j; 
    IntNode *b4J;
    /*if (head == tail && head->next == nullptr) {
        return;
    }*/
    i = head;
    //j = i->next;
    while (i != nullptr) {
        //cout << "testing - " << endl;
        b4J = i;
        //cout << "test" << endl;
        j = i->next;
        while (j != nullptr) {
            //cout << "test2" << endl;
            if (i->value == j->value) {
                //cout << "test3" << endl;
                //cout << "j: " << j << " tail: " << tail << endl;
                if (j != tail) {
                    b4J->next = j->next;
                    //cout << "hi" << endl;
                    delete j;
                    //cout << "hi2" << endl;
                    j = b4J;
                    //cout << "hi3" << endl;
                }
                else {
                    tail = b4J;
                    
                    delete j;
                    j = nullptr;
                    b4J->next = nullptr;
                }               
            }
            else {
                b4J = b4J->next;
            }
            /*if (j != nullptr) {
                j = j->next;
            }*/
            j = b4J->next;
        }
        /*if (i != nullptr) {
            i = i->next;
        }*/
        i = i->next;
    }
}
    
    /*for (i = head; i != nullptr; i = i->next) { //loop starts at head
        comp = i->value; //node to be compared is whatever i is
        b4J = i;
        cout << "testing" << endl;
        for (j = i->next; j != nullptr; j = j->next) { //j starts at node after i aka comp
            cout << "test j" << endl;
            cout << "comp value: " << comp << endl;
            if (comp == (j->value) && j == tail) {//if comp->val is the same as j->val
                cout << "test1" << endl;
            }
        }
    }*/

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

// Used by selection_sort function.
// Just have this function return nullptr if you don't use this function. 
IntNode * min(IntNode *n) {
    return nullptr;
}

// Used by copy constructor and/or copy assignment operator.
// Just implement an empty function if you don't use this function.
void copy(const IntList &l) {
    
}