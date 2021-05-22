#include "Node.h"
int main(){
  int data = 26;
  Node* newNode = new Node(data);
  double data2 = 26.23;
  Node* newNode2 = new Node(data2);
  string data3 = "hello string";
  Node* newNode3 = new Node(data3);
  newNode->printData();
  newNode2->printData();
  newNode3->printData();
}
