#include "intbst.h"

#include <iostream>
using namespace std;



// creates two trees (one of which is empty),
// and does some simple tests of tree methods
int main() {

    IntBST bst1;

    // insert data to bst1
    bst1.insert(64);
    bst1.insert(128);
    bst1.insert(8);
    bst1.insert(512);
    bst1.insert(256);
    bst1.insert(32);
    bst1.insert(16);
    bst1.insert(4);

    bst1.remove(4);
    bst1.printInOrder();
    cout << endl;
    bst1.printPostOrder();

    return 0;
}