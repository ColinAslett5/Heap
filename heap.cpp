#include <iostream>
#include <cmath>
#include "heap.h"

using namespace std;

Heap::Heap(){
  count = 0;//number of nodes
  size = 128;
  node = new int[size];
  for(int i = 0;i < size;i++){
    node[1] = 0;
  }
}
Heap::~Heap(){
  delete[] node;
}
int Heap::peek(){
  return node[0];
}
//is it empty or not?
bool Heap::empty(){
  if(node[0] == 0){
    return true;
  }
  else{
    return false;
  }
}
void Heap::add(int n){
  //if our array is big enough we dont need to increase it
  if(count < size){
    node[count] = n;
    siftup(count);
    count++;
  }
  //array not big enough! We need to change somethings
  else{
    int* nodex = new int[2*size];
    for(int i = 0;i < size;i++){
      nodex[i] = node[i];
    }
    for(int a = 0;a < 2*size;a++){
      nodex[a] = 0;
    }
    int* temp = node;
    node = nodex;
    delete[] temp;
    size *= 2;
    add(n);
  }
}
int Heap::pop(){
  int head = node[0];
  node[0] = node[count-1];
  node[count-1] = 0;
  count--;
  siftdown(0);
  return head;
}
//sorting upwards
void Heap::siftup(int x){
  if(x <= 0){
    return;
  }
  int parent = (x-2)/2;
  if(x % 2 == 1){
    parent = (x-1)/2;
  }
  if(node[x] > node[parent]){
    int temp = node[parent];
    node[parent] = node[x];
    node[x] = temp;
    siftup(parent);
  }
}
//sorting downwards
void Heap::siftdown(int x){
  if(node[x] < node[2*x+1] || node[x] < node[2*x+2]){
    int m = 2*x + 2;
    if(node[2*x + 1] > node[2*x + 2]){
      m = 2*x + 1;
    }
    int temp = node[x];
    node[x] = node[m];
    node[m] = temp;
    siftdown(m);
  }
}
//printing out the tree
void Heap::print(){
    int numLevels = ceil(log2(count + 1));
    int index = 0;
    for(int l=1; l <= numLevels; l++){
        for(int i=0; i < pow(2, numLevels-l)-1; i++){
            cout << ' ';
        }
        for(int n=0; n < pow(2, l-1); n++){
            if(node[index] != 0){
                cout << node[index++]; // Node
            }
            else{
                break;
            }
            for(int i=0; i < pow(2, numLevels - l + 1) - 1; i++){
                cout << ' ';
            }
        }
        cout << endl;
    }
}
