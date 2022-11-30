// heap.cpp
// Diba Mirza
//Bochen Wang
#include "heap.h"
#include <iostream>
using std::cout;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  int i = vdata.size();
  vdata.push_back(value);
  while(i > 0){
    if(vdata[(i -1)/2] > value){
      vdata[i] = vdata[(i -1)/2];
      vdata[(i -1)/2] = value;
      i = (i -1)/2;
    }
    else break;
  }


  //if(vdata.empty()) vdata.push_back(value);
  //else{
  //  if(vdata.size() == 1 && vdata[0] > value){
  //    vdata.push_back(vdata[0]);
  //    vdata[0] = value;
  //  }
  //  if(vdata.size() == 1 && vdata[0] <= value) vdata.push_back(value);
  //  if(vdata.size() == 2 && vdata[0] > value){
  //    vdata.push_back(vdata[0]);
  //    vdata[0] = value;
  //  }
  //  if(vdata.size() == 2 && vdata[0] <= value) vdata.push_back(value);
  //  if(vdata.size() > 2){
  //    int i = 0;
  //    while(i < vdata.size()){
  //      if(vdata[i] <= value){
  //        if((2*i + 1) >= vdata.size()) {
  //          vdata.push_back(value);
  //          break;
  //        }
  //        else{
  //          if((2*i + 2) >= vdata.size()){
  //            vdata.push_back(value);
  //            break;
  //          }
  //          else{
  //            if(vdata[2*i +1] > vdata[2*i + 2]) i = 2 * i + 2;
  //            else i = 2*i + 1;
  //          } 
  //        }
  //      }
  //      else{
  //        
  //      }
  //    }
  //  }
//
//
  //}
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  vdata[0] = vdata[vdata.size() - 1];
  int temp = vdata[vdata.size() - 1];
  vdata.pop_back();
  int i = 0;
  while((2 * i + 1) < vdata.size()){//have left child
    if((2 * i + 2) < vdata.size()){//have right child
      
      if(vdata[2*i + 1] < vdata[2*i +2]){//left is min
        if(vdata[2*i + 1] < temp){
          vdata[i] = vdata[i*2 +1];
          vdata[i*2 +1] = temp;
          i = i*2 +1;
        }else break;
      }else{//right is min
        if(vdata[2*i + 2] < temp){
          vdata[i] = vdata[i*2 +2];
          vdata[i*2 +2] = temp;
          i = i*2 +2;
        }else break;
      }

    }else{
      if(vdata[2*i + 1] < temp){
          vdata[i] = vdata[i*2 +1];
          vdata[i*2 +1] = temp;
          i = i*2 +1;
        }else break;
    }
  }
}

// Returns the minimum element in the heap
int Heap::top(){
  if(vdata.empty())return 0;
  else return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  if(vdata.empty())return true;
  else return false;
}
    