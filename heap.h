//header file for Heap, Colin Aslett, C++ Period 07
#ifndef HEAP_H
#define HEAP_H

Class Heap{
 Public:
  Heap();
  ~Heap();
  int peek();
  int pop();
  void add(int n);
  void siftup(int x);
  void siftdown(int x);
  void print();
  bool empty();
 private:
  int size;
  int* node;
  int count;
}
