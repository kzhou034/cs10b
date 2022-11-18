#include <iostream>
#include "IntList.h"
#include "SortedSet.h"

using namespace std;

SortedSet::SortedSet() {

}

SortedSet::SortedSet(const SortedSet &cpy) {
    // from IntList
    head = nullptr;
    tail = nullptr;
    IntNode *temp = nullptr;
    for (temp = cpy.head; temp != nullptr; temp = temp->next) {
        //copyOfCpy.push_back(temp->value);
        push_back(temp->value);
    }
}

/*A constructor that is passed an IntList instead of a SortedSet. 
It should initialize the set using the values in the IntList. 
Again, you can use the IntList copy constructor and then 
remove all of the duplicates and sort the remaining values. */
SortedSet::SortedSet(const IntList &list) : IntList(list) {
    //From IntList
    //head = nullptr;
    //tail = nullptr;
    /*IntNode *temp = this->head;
    for (temp; temp != nullptr; temp = temp->next) {
        //copyOfCpy.push_back(temp->value);
        push_back(temp->value);
    }*/
    //IntList(list);
    remove_duplicates();
    selection_sort();
}

SortedSet::~SortedSet() {

}

//This function returns true if the value passed in is 
//a member of the set, otherwise false.
bool SortedSet::in(int value) const {
    bool isMember = false;
    if (empty()) {
        return isMember;
    }
    else {
        IntNode *temp = nullptr;
        for (temp = head; temp != nullptr; temp = temp->next) {
            if (value == temp->value) {
                isMember = true;
            }
        }
    }
    return isMember;
}

/*operator|: This function returns a SortedSet object that is 
the union of 2 SortedSet objects, the left and right operands of 
this binary operator. A union of 2 sets is a set that consists of all 
of the distinct elements of both sets combined. That is, all of the values 
that are in the left operand or in the right operand or in both operands.
sset1 = sset2 | sset3;*/
SortedSet SortedSet::operator|(const SortedSet &sset) const {
    SortedSet returnedSet; //set that is returned
    IntNode *temp = nullptr;
    if (head == nullptr && tail == nullptr) { //if left is empty
        returnedSet = sset;
        return returnedSet;
    } 
    else {
        for (temp = head; temp != nullptr; temp = temp->next) {
            returnedSet.push_back(temp->value);
        }
        IntNode *temp2 = nullptr;
        for (temp2 = sset.head; temp2 != nullptr; temp2 = temp2->next) {
            if (sset.in(temp2->value) != in(temp2->value)) {
                returnedSet.push_back(temp2->value);
            }
        }
        returnedSet.remove_duplicates(); //removes duplicates in case
    }
    return returnedSet;
}

/*operator&: This function returns a SortedSet object that is the intersection 
of 2 SortedSet objects, the left and right operands of this binary operator. An 
intersection of 2 sets is a set of all elements that are in both sets. That is, 
all of the values that are both in the left operand and in the right operand.
sset1 = sset2 & sset3;*/
SortedSet SortedSet::operator&(const SortedSet &sset) const {
    SortedSet returnedSet; //set that is returned @ end of function
    IntNode *temp = nullptr;
    if (head == nullptr && tail == nullptr) { //if left is empty
        return returnedSet;
    }
    else {
        for (temp = head; temp != nullptr; temp = temp->next) {
            if (sset.in(temp->value) == in(temp->value)) { //if sset.in and in find the same value, both returns true
                returnedSet.push_back(temp->value); //since they both share temp->value, insert the value into the new set
            }
        }
    }
    return returnedSet;
}

//no remove_duplicates or selection_sort
void SortedSet::add(int value) {
    if (in(value)) {
        return;
    }
    else {
        IntList::insert_ordered(value);
    }
}

//does what add does
void SortedSet::push_front(int value) {
    if (in(value)) {
        return;
    }
    else {
        add(value);
    }
}

//same as push_front
void SortedSet::push_back(int value) {
    if (in(value)) {
        return;
    }
    else {
        add(value);
    }
}

//same specs for push_front
void SortedSet::insert_ordered(int value) {
    add(value);
}

/* operator|=: This function is the union-assign operator function. 
It returns a union of the left and right operands, but also sets the left operand's 
value to be that union as well. In other words, sset1 |= sset2 is equivalent to 
sset1 = sset1 | sset2.

Hint: Take advantage of functions you have already written and you know work. */
SortedSet SortedSet::operator|=(SortedSet &sset){
    SortedSet returnedSet; //set that is returned @ end of function
    if (head == nullptr && tail == nullptr) { //if left is empty
        returnedSet = sset;
        *this = returnedSet;
        return *this;
    }
    else if (sset.head == nullptr && sset.tail == nullptr) { //if right is empty
        
        return *this; //returns left
    }
    else {
        IntNode *temp = nullptr;
        for (temp = sset.head; temp != nullptr; temp = temp->next) {
            this->push_back(temp->value);
        }
        return *this;
    }
    //return *this;
}

/* operator&=: This function is the intersection-assign operator function. 
It returns an intersection of the left and right operands, but also sets the left 
operand's value to be that intersection as well. In other words, sset1 &= sset2 is 
equivalent to sset1 = sset1 & sset2.

Hint: Take advantage of functions you have already written and you know work. */
SortedSet SortedSet::operator&=(SortedSet &sset){
    SortedSet returnedSet; //set that is returned @ end of function
    if ((head == nullptr && tail == nullptr) || (sset.head == nullptr && sset.tail == nullptr)) { //if lhs OR rhs are empty
        //returnedSet = operator&(sset);
        this->clear();
        return *this;
    }
    else {
        IntNode *temp = nullptr;
        for (temp = sset.head; temp != nullptr; temp = temp->next) {
            if (in(temp->value) && sset.in(temp->value)) {
                returnedSet.push_back(temp->value);
            }
        }
        *this = returnedSet;
        return *this;
    }
    return *this;
}