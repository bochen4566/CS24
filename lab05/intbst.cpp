// intbst.cpp
// Implements class IntBST
// YOUR NAME(S), DATE
//Bochen Wang 5/8/2022



// constructor sets up empty tree
template <class T> 
IntBST<T>::IntBST() { 
    root = nullptr;
}

// destructor deletes all nodes
template <class T> 
IntBST<T>::~IntBST() {
    clear(root);
}

// recursive helper for destructor
template <class T> 
void IntBST<T>::clear(Node *n) {
    if(n == nullptr) return;
    clear(n->left);
    clear(n->right);
    delete n;
}

// insert value in tree; return false if duplicate
template <class T> 
bool IntBST<T>::insert(T value) {
    return insert(value, root); // REPLACE THIS NON-SOLUTION
}

// recursive helper for insert (assumes n is never 0)
template <class T> 
bool IntBST<T>::insert(T value, Node *n) {
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
template <class T> 
void IntBST<T>::printPreOrder() const {
    //cout << "IMPLEMENT printPreOrder public method";; // IMPLEMENT HERE
    printPreOrder(root);
}

// recursive helper for printPreOrder()
template <class T> 
void IntBST<T>::printPreOrder(Node *n) const {
    //cout << "IMPLEMENT printPreOrder private helper method"; // IMPLEMENT HERE
    if(n == nullptr) return;
    cout << n->info << " ";
    printPreOrder(n->left);
    printPreOrder(n->right);
}

// print tree data in-order, with helper
template <class T> 
void IntBST<T>::printInOrder() const {
    //cout << "IMPLEMENT printInOrder public method"; // IMPLEMENT HERE
    printInOrder(root);
}

template <class T> 
void IntBST<T>::printInOrder(Node *n) const {
    if(n == nullptr) return;
    printInOrder(n->left);
    cout << n->info<< " ";//"IMPLEMENT IMPLEMENT printInOrder private helper method"; // IMPLEMENT HERE
    printInOrder(n->right);
}

// prints tree data post-order, with helper
template <class T> 
void IntBST<T>::printPostOrder() const {
    printPostOrder(root);
    //cout << "IMPLEMENT printPostOrder public method"; // IMPLEMENT HERE
}

template <class T> 
void IntBST<T>::printPostOrder(Node *n) const {
    if(n == nullptr) return;
    printPostOrder(n->left);
    printPostOrder(n->right);
    cout << n->info<< " ";//"IMPLEMENT printPostOrder private helper method";// IMPLEMENT HERE
}

// return sum of values in tree
//int IntBST::sum() const {
//    return sum(root); // REPLACE THIS NON-SOLUTION
//}
//
//// recursive helper for sum
//int IntBST::sum(Node *n) const {
//    if(n == nullptr) return 0;
//    //if(n->left == nullptr && n->right == nullptr) return n->info; 
//    return n->info + sum(n->left)+sum(n->right);// REPLACE THIS NON-SOLUTION
//}

// return count of values
template <class T> 
int IntBST<T>::count() const {
    return count(root); // REPLACE THIS NON-SOLUTION
}

// recursive helper for count
template <class T> 
int IntBST<T>::count(Node *n) const {
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

template <class T> 
typename IntBST<T>::Node* IntBST<T>::getNodeFor(T value, Node* n) const{
    if(n == nullptr) return NULL;
    else if(n->info == value) return n;
    else if(n->info > value)return getNodeFor(value, n->left);
    else if(n->info < value)return getNodeFor(value, n->right);
    else return nullptr;
//return NULL; // REPLACE THIS NON-SOLUTION
}

// returns true if value is in the tree; false if not
template <class T> 
bool IntBST<T>::contains(T value) const {
    if(getNodeFor(value, root) == NULL) return false;
    else return true; // REPLACE THIS NON-SOLUTION
}

// returns the Node containing the predecessor of the given value
template <class T> 
typename IntBST<T>::Node* IntBST<T>::getPredecessorNode(T value) const{
    Node* m = getNodeFor(value, root);
    if(m == nullptr) return NULL;
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
template <class T> 
T IntBST<T>::getPredecessor(T value) const{
    if(getPredecessorNode(value) != NULL)return getPredecessorNode(value)->info; 
    else return T();// REPLACE THIS NON-SOLUTION
}

// returns the Node containing the successor of the given value
template <class T> 
typename IntBST<T>::Node* IntBST<T>::getSuccessorNode(T value) const{
    Node* m = getNodeFor(value, root);
    if(m == nullptr) return NULL;
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
template <class T> 
T IntBST<T>::getSuccessor(T value) const{
    if(getSuccessorNode(value) != NULL) return getSuccessorNode(value)->info;
    else return T() ;// REPLACE THIS NON-SOLUTION
}

// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
template <class T> 
bool IntBST<T>::remove(T value){
    Node* n = getNodeFor(value, root);
    if(n == NULL) return false;
    else{
        if((n->parent == nullptr) && n->left == nullptr && n->right == nullptr){
            delete n;
            root = nullptr;
            return true;
        }
        if(((n->parent == nullptr) && (n->left != nullptr)) && (n->right == nullptr)){
            root = n->left;
            n->left->parent = nullptr;
            delete n;
            return true;
        }
        if(((n->parent == nullptr) && (n->left == nullptr)) && (n->right != nullptr)){
            root = n->right;
            n->right->parent = nullptr;
            delete n;
            return true;
        }
        if(((n->parent == nullptr) && (n->left != nullptr)) && (n->right != nullptr)){
            Node* m = getPredecessorNode(value);
            if(m == nullptr){
                m = getSuccessorNode(value);
            }
            T temp = m->info;
            remove(m->info);
            n->info = temp;
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
            T temp = m->info;
            remove(m->info);
            n->info = temp;
            return true;
                
        }   
    }
}

