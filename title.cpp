//Colin Aslett, Heap, C++ Period 07
#include <iostream>
#include "heap.h"
#include <string.h>
#include <fstream>
using namespace std;

void fill(Heap &heap,char* link);
void print(Heap &heap);

int main(){
  while(true){
    Heap heap;
    char input;
    cout << "enter a option, 1: enter numbers, 2: file, 3: quit" << endl;
    cin >> input;
    //manual insertion
    if(input == '1'){
      cout << "enter a list" << endl;
      char numb[200];
      cin.ignore();
      cin.getline(numb,200);
      fill(heap,numb);
    }
    //file insertion
    else if(input == '2'){
      char name[32];
      cout << "enter file name" << endl;
      cin >> name;
      ifstream stream(name);
      if(stream.is_open()){
	char list[10000];
	stream.getline(list,10000,0);
	stream.close();
	fill(heap,list);
      }
      else{
	cout << "could not open" << endl;
	continue;
      }
    }
    //quitting
    else if(input == '3'){
      break;
    }
    else{
      cout << "????" << endl;
    }
    //ways to print out the tree
    cout << "options to print, 1: descending order, 2: just tree, 3: 1&2, 4: quit" << endl;
    cin >> input;
    if(input == '1'){
      print(heap);
    }
    else if(input == '2'){
      heap.print();
    }
    else if(input == '3'){
      cout << "tree:" << endl;
      heap.print();
      cout << "list:" << endl;
      print(heap);
    }
    else if(input == '4'){
      break;
    }
    else{
      cout << "????" << endl;
    }
  }
}
//filling the heap with numeros
void fill(Heap &heap, char* link){
  int i = 0;
  while(link[i]){
    if(isdigit(link[i])){
      int z = link[i] - '0';
      while(isdigit(link[++i])){
	z = 10*z + (link[i] - '0');
      }
      heap.add(z);
    }
    else{
      i++;
    }
  }
}
//printing out the tree
void print(Heap &heap){
  cout << heap.pop();
  while(!heap.empty()){
    cout << ", " << heap.pop();
  }
  cout << endl;
}
