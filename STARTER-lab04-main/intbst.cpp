// intbst.cpp
// Implements class IntBST
// YOUR NAME(S), DATE
//Bochen Wang 5/8/2022
#include "intbst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
IntBST::IntBST() { 
    root = nullptr;
}

// destructor deletes all nodes
IntBST::~IntBST() {
    clear(root);
}

// recursive helper for destructor
void IntBST::clear(Node *n) {
    if(n == nullptr) return;
    clear(n->left);
    clear(n->right);
    delete n;
}

// insert value in tree; return false if duplicate
bool IntBST::insert(int value) {
    return insert(value, root); // REPLACE THIS NON-SOLUTION
}

// recursive helper for insert (assumes n is never 0)
bool IntBST::insert(int value, Node *n) {
    Node* m = new Node;
    m->info = value;
    if(n == nullptr){
        root = m;
        return true;
    }
    if(n->info == value) return false;
    if(n->info > value && n->left != nullptr) return insert(value, n->left);
    if(n->info < value && n->right != nullptr) return insert(value, n->right);
    if(n->left == nullptr && n->info > value){
            n->left = m;
            m->parent = n;
            return true;
        }
    if(n->info < value && n->right == nullptr){
            n->right = m;
            m->parent = n;
            return true;
        }
}
    //return true;
     // REPLACE THIS NON-SOLUTION
    //if(n == nullptr){
    //    Node* m = new Node;
    //    m->info = value;
    //    return true;
    //}
    //if(n->info == value) return false;
    //if(n->info > value) return insert(value, n->left);


// print tree data pre-order
void IntBST::printPreOrder() const {
    //cout << "IMPLEMENT printPreOrder public method";; // IMPLEMENT HERE
    printPreOrder(root);
}

// recursive helper for printPreOrder()
void IntBST::printPreOrder(Node *n) const {
    //cout << "IMPLEMENT printPreOrder private helper method"; // IMPLEMENT HERE
    if(n == nullptr) return;
    cout << n->info << " ";
    printPreOrder(n->left);
    printPreOrder(n->right);
}

// print tree data in-order, with helper
void IntBST::printInOrder() const {
    //cout << "IMPLEMENT printInOrder public method"; // IMPLEMENT HERE
    printInOrder(root);
}
void IntBST::printInOrder(Node *n) const {
    if(n == nullptr) return;
    printInOrder(n->left);
    cout << n->info<< " ";//"IMPLEMENT IMPLEMENT printInOrder private helper method"; // IMPLEMENT HERE
    printInOrder(n->right);
}

// prints tree data post-order, with helper
void IntBST::printPostOrder() const {
    printPostOrder(root);
    //cout << "IMPLEMENT printPostOrder public method"; // IMPLEMENT HERE
}

void IntBST::printPostOrder(Node *n) const {
    if(n == nullptr) return;
    printPostOrder(n->left);
    printPostOrder(n->right);
    cout << n->info<< " ";//"IMPLEMENT printPostOrder private helper method";// IMPLEMENT HERE
}

// return sum of values in tree
int IntBST::sum() const {
    return sum(root); // REPLACE THIS NON-SOLUTION
}

// recursive helper for sum
int IntBST::sum(Node *n) const {
    if(n == nullptr) return 0;
    //if(n->left == nullptr && n->right == nullptr) return n->info; 
    return n->info + sum(n->left)+sum(n->right);// REPLACE THIS NON-SOLUTION
}

// return count of values
int IntBST::count() const {
    return count(root); // REPLACE THIS NON-SOLUTION
}

// recursive helper for count
int IntBST::count(Node *n) const {
    if(n == nullptr) return 0; 
    //return 1+sum(n->left);
    return 1+count(n->left)+count(n->right);// REPLACE THIS NON-SOLUTION
}

// IMPLEMENT THIS FIRST: returns the node for a given value or NULL if none exists
// Parameters:
// int value: the value to be found
// Node* n: the node to start with (for a recursive call)
// Whenever you call this method from somewhere else, pass it
// the root node as "n"
IntBST::Node* IntBST::getNodeFor(int value, Node* n) const{
    if(n == nullptr) return NULL;
    if(n->info == value) return n;
    if(n->info > value)return getNodeFor(value, n->left);
    if(n->info < value)return getNodeFor(value, n->right);
//return NULL; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the tree; false if not
bool IntBST::contains(int value) const {
    if(getNodeFor(value, root) == NULL) return false;
    else return true; // REPLACE THIS NON-SOLUTION
}

// returns the Node containing the predecessor of the given value
IntBST::Node* IntBST::getPredecessorNode(int value) const{
    Node* m = getNodeFor(value, root);
    if(m->left != nullptr){
        if(m->left->right == nullptr) return m->left;
        else{
            m = m->left->right;
            while(m->right){
                m = m->right;
            }
            return m;
        }
    }
    else{
        if(m->parent == nullptr) return NULL;
        m = m->parent;
        while(m->info > value){
            m = m->parent;
            if(m == nullptr) return NULL;
        }
        return m;
        
    }// REPLACE THIS NON-SOLUTION
}

// returns the predecessor value of the given value or 0 if there is none
int IntBST::getPredecessor(int value) const{
    if(getPredecessorNode(value) != NULL)return getPredecessorNode(value)->info; 
    else return 0;// REPLACE THIS NON-SOLUTION
}

// returns the Node containing the successor of the given value
IntBST::Node* IntBST::getSuccessorNode(int value) const{
    Node* m = getNodeFor(value, root);
    if(m->right != nullptr){
        if(m->right->left == nullptr) return m->right;
        else{
            m = m->right->left;
            while(m->left){
                m = m->left;
            }
            return m;
        }
    }
    else{
        if(m->parent == nullptr) return NULL;
        m = m->parent;
        while(m->info < value){
            m = m->parent;
            if(m == nullptr) return NULL;
        }
        return m;
        }
     // REPLACE THIS NON-SOLUTION
}

// returns the successor value of the given value or 0 if there is none
int IntBST::getSuccessor(int value) const{
    if(getSuccessorNode(value) != NULL) return getSuccessorNode(value)->info;
    else return 0;// REPLACE THIS NON-SOLUTION
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
bool IntBST::remove(int value){
    Node* n = getNodeFor(value, root);
    if(n == NULL) return false;
    else{
        if((n->parent == nullptr) && n->left == nullptr && n->right == nullptr){
            delete n;
            root = nullptr;
            return true;
        }
        if(n->left == nullptr && n->right == nullptr){//case with no child
            if(n->parent->left == n){
                n->parent->left = nullptr;
                delete n;
                return true;
            }else{
                n->parent->right = nullptr;
                delete n;
                return true;
            }

        }
        //case with one child
        if(n->left != nullptr && n->right == nullptr){
            if(n->parent->left == n){
                n->parent->left = n->left;
                n->left->parent = n->parent;
                delete n;
                return true;
            }else{
                n->parent->right = n->left;
                n->left->parent = n->parent;
                delete n;
                return true;
            }            
        }
        if(n->left == nullptr && n->right != nullptr){
            if(n->parent->left == n){
                n->parent->left = n->right;
                n->right->parent = n->parent;
                delete n;
                return true;
            }else{
                n->parent->right = n->right;
                n->right->parent = n->parent;
                delete n;
                return true;
            }            
        }
        //case with two child do it recersively in case there is preddecessor or successor with child
        if(n->left != nullptr && n->right != nullptr){
            Node* m = getPredecessorNode(n->info);
            if(m == nullptr){
                m = getSuccessorNode(n->info);
            }
                int temp = m->info;
                remove(m->info);
                n->info = temp;
                return true;
            //Node* x = getSuccessorNode(n->info);
            //n->info = m->info;
            //if(m->parent->left == m){
            //    m->parent->left = nullptr;
            //    delete m;
            //    return true; 
            //}else{
            //    m->parent->right = nullptr;
            //    delete m;
            //    return true;
            //}
            //if(n->parent->left == n){
            //    n->parent->left = n->left;
            //    n->left->parent = n->parent;
            //    n->right->parent = m;
            //    m->right = n->right;
            //    delete n;
            //    return true;                
            //}
            //if(n->parent->right == n){
            //    n->parent->right = n->left;
            //    n->left->parent = n->parent;
            //    n->right->parent = m;
            //    m->right = n->right;
            //    delete n;
            //    return true;                
            //}            
        }   // REPLACE THIS NON-SOLUTION
    }
}

//void IntBST::equal() const{
//    if(getNodeFor(8, root) == root->left) cout<< "nb" << endl;
//    if(getNodeFor(2, root) == NULL) cout << "666" << endl;
//}