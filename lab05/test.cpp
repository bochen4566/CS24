#include "intbst.h"

#include <iostream>
using namespace std;



// creates two trees (one of which is empty),
// and does some simple tests of tree methods
int main() {

    IntBST<string> bst1;

    // insert data to bst1
    bst1.insert("bz");
    bst1.insert("az");
    bst1.insert("dz");
    ////bst1.insert(512);
    ////bst1.insert(256);
    ////bst1.insert(32);
    ////bst1.insert(16);
    ////bst1.insert(4);
//
    ////bst1.remove(4);
    bst1.printInOrder();
    cout << endl;
    bst1.printPostOrder();
    //string a = "az";
    //string b = "bz";
    //if(a < b) cout << "?" << endl;
    return 0;
}