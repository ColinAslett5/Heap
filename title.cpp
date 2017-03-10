//Colin Aslett, Heap, C++ Period 07
#include <iostream>
using namespace std;
struct Heap{
  int node;
  int size;//number of nodes in the heap
};
void iden(char* input);
void add(int secnum);
int main(){
  //settings for the heap
  Heap->size = 0;
  //input
  char input[200];
  cout << "enter a series of numbers seperated by spaces" << endl;
  //cin.ignore(); probably dont need this unless you start with a space
  cin.getline(input,150);
  iden(input);
}
//about to put something on the heap, but first gotta identify the number
void iden(char* input){
  int num = 0;
  while(input[num] != '\0'){//might be wrong
    if(isdigit(input[num])){
      //int secnum = 0;
      int secnum = input[num] - '0';
      while(isdigit(input[++num])){
	secnum = 10*secnum + (input[num] - '0');
      }
      add(secnum);
    }
    else{
      num++;
    }
  }
}
//adding to the heap
void add(int secnum){
  cout << secnum << endl;
}
