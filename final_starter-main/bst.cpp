// bst.cpp
// CS24 Final Exam
// Implements class bst
// YOUR NAME(S), DATE
//Bochen Wang 06/06/2022

#include "bst.h"

#include <iostream>
using std::cout;



bst::bst(vector<int>&v){
    
        //if(root == nullptr){
        //    root = new bstNode(i);
        //}else{
        //insert(i, root);
        //}
        root = new bstNode;
        root->info = v[0];
        root->left = nullptr;
        root->right = nullptr;
        for (int i = 1; i < v.size(); i++) {
            insert(v[i]);
        }
}

bst::~bst(){
    clear(root);
}

void bst::clear(bstNode *n) {
    if(n == nullptr) return;
    clear(n->left);
    clear(n->right);
    delete n;
}


bool bst::insert(int value) {

    if (root == nullptr){
        root = new bstNode(value);
        return true;
    }else{
        return insert(value, root);
    }

    return false; 

}


// recursive helper for insert (assumes n is never 0)

bool bst::insert(int value, bstNode *n) {

    if(value < n->info){
        if(n->left == nullptr){
            n->left = new bstNode(value);
            n->left->parent = n;
            return true;
        } else {
            return insert(value, n->left);
        }
    } else if (value > n->info) {
        if (n->right == nullptr){
            n->right = new bstNode(value);
            n->right->parent = n;
            return true;
        } else {
            return insert(value, n->right);
        }
    } else {
        return false;
    }

}


void bst::deleteSubtree(int key){
    bstNode *n = getNodeFor(key, root);
    if(!n) return;
    //else if(n->left == nullptr && n->right == nullptr) return;
    else{
        if(n->parent != nullptr && n->right == n) getNodeFor(key, root)->parent->right = nullptr;
        if(n->parent != nullptr && n->left == n) getNodeFor(key, root)->parent->left = nullptr;
        clear(n);
        
    }
}
int bst::countLeaves(bstNode *n) const{
    if(!n) return 0;
    int nl = countLeaves(n->left);
    int nr = countLeaves(n->right);
    if(n->left == nullptr && n->right == nullptr){
        return 1 + nl + nr;
    }else{
        return nl + nr;
    }
}
int bst::countParentsWithTwoChildren(bstNode *n) const{
    if(!n) return 0;
    int nl = countParentsWithTwoChildren(n->left);
    int nr = countParentsWithTwoChildren(n->right);
    if(n->left != nullptr && n->right != nullptr){
        return 1 + nl + nr;
    }else{
        return nl + nr;
    }
}
int bst::height(bstNode *n) const{
    if(!n) return -1;
    //else if(n->left == nullptr && n->right == nullptr) return 0;
    else{
        int nl = 0 + height(n->left);
        int nr = 0 + height(n->right);
        if(nl >= nr){
            return nl + 1;
        }else{
            return nr +1;
        }
    }
}
void bst::outputPreOrder(bstNode *n, vector<int>& output) const{
    if(n == nullptr) return;
    output.push_back(n->info);
    outputPreOrder(n->left,output);
    outputPreOrder(n->right,output);
}
void bst::outputInOrder(bstNode *n, vector<int>& output) const{
   if(n == nullptr) return;
    
    outputInOrder(n->left,output);
    output.push_back(n->info);
    outputInOrder(n->right,output);
}

typename bst::bstNode* bst::getNodeFor(int value, bstNode* n) const{
    while (n != nullptr) {
        if (value == n->info) {
            return n; 
        }
        else if (value < n->info) {
            return getNodeFor(value, n->left);
        } else {
            return getNodeFor(value, n->right);
        }
    }
    return nullptr; // Node doesn't exist in tree
}
