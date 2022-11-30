// intlist.cpp
// Implements class IntList
// YOUR NAME(S), AND DATE
// Bochen Wang, 04/27/2022

#include "intlist.h"

#include <iostream>
using std::cout;

// copy constructor
IntList::IntList(const IntList& source) {
    //IMPLEMENT THIS
    if(source.first == nullptr) {
        this->first = nullptr;
        return;
    }
    //this->first = source.first;//Traversal
    //this->first = nullptr;
    Node* t = source.first;
    Node* one = new Node;
    this->first = one;
    Node* t2 = this->first;
    this->first->info = t->info;
    t = t->next;
    while(t){
        Node* n = new Node;
        //n->info = t->info;
        //if(this->first == nullptr) this->first = n;
        t2->next = n;
        t2->next->info = t->info;
        t = t->next;
        t2 = t2->next;
    }
    t2->next = nullptr;
}

// destructor deletes all nodes
IntList::~IntList() {
    //IMPLEMENT THIS
    //delete first;
    
    Node* p = this->first;
    while(p){
        this->first = this->first->next;
        delete p;
        p = this->first;
    }
}


// return sum of values in list
int IntList::sum() const {
    int sum = 0;
    Node *n = first;
    while (n) {
        sum += n->info;
        n = n->next;
    }
    return sum; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the list; false if not
bool IntList::contains(int value) const {
    bool res = false;
    Node *n = first;
    while(n){
        if(n->info == value){
            res = true;
            break;
        }
        n = n->next;
    }
    return res; // REPLACE THIS NON-SOLUTION
}

// returns maximum value in list, or 0 if empty list
int IntList::max() const {
    Node* n = first;
    int max = 0;
    if(n){
    max = first->info;
    while(n){
        if(n->info >= max){
            max = n->info;
        }
        n = n->next;
    }
    }
    return max; // REPLACE THIS NON-SOLUTION
}

// returns average (arithmetic mean) of all values, or
// 0 if list is empty
double IntList::average() const {
    double res = 0;
    int c = 0;
    Node* n = first;
    
    while(n){
        c++;
        res += n->info;
        n = n->next;
    }
    if(c == 0) return 0;
    else return res/c; // REPLACE THIS NON-SOLUTION
}

// inserts value as new node at beginning of list
void IntList::insertFirst(int value) {
    // IMPLEMENT
    Node *res = new Node;
    res->next = first;
    res->info = value;
    this->first = res;

}

//Assignment operator should copy the list from the source
//to this list, deleting/replacing any existing nodes
IntList& IntList::operator=(const IntList& source){
    //IMPLEMENT
    //this->first = source.first;
    if(source.first == nullptr)this->first = nullptr;
    else{
        Node* p = this->first;
        while(p){
        this->first = this->first->next;
        delete p;
        p = this->first;
        }
        Node* t = source.first;
        Node* one = new Node;
        this->first = one;
        Node* t2 = this->first;
        this->first->info = t->info;
        t = t->next;
        while(t){
        Node* n = new Node;
        //n->info = t->info;
        //if(this->first == nullptr) this->first = n;
        t2->next = n;
        t2->next->info = t->info;
        t = t->next;
        t2 = t2->next;
        }
        t2->next = nullptr;
    }
    return *this;
}



// DO NOT CHANGE ANYTHING BELOW (READ IT THOUGH)

// constructor sets up empty list
IntList::IntList() : first(0) { }


// append value at end of list
void IntList::append(int value) {
    if (first == 0) { // empty list
        first = new Node;
        first->info = value;
        first->next = 0;
    }
    else {
        Node *n = first;
        while (n->next) // not last node yet
            n = n->next;
        n->next = new Node;
        n->next->info = value;
        n->next->next = 0;
    }
}

// print values enclose in [], separated by spaces
void IntList::print() const {
    Node *n = first;
    cout << '[';
    while (n) {
        cout << n->info;
        if (n->next)
            cout << " ";
        n = n->next;
    }
    cout << ']';
}

// return count of values
int IntList::count() const {
    int result = 0;
    Node *n = first;
    while (n) {
        ++result;
        n = n->next;
    }
    return result;
}
