#include "Node.h"
#include <iostream>
#include <stdexcept>

using std::string;
using std::endl;
using std::cout;
Node::Node(int intPtr){
  this->intPtr = new int(intPtr);
  this->type = "integer";
}
Node::Node(double doublePtr){
  this->doublePtr = new double(doublePtr);
  this->type = "double";
}
Node::Node(string stringPtr){
  this->stringPtr = new string(stringPtr);
  this->type = "string";
}
void Node::printData(){
  if(type == "integer"){
    cout << *this->intPtr << endl;
  }
  else if(type == "string"){
    cout << *this->stringPtr << endl;
  }
  else if (type == "double"){
    cout << *this->doublePtr << endl;
  }
  else{
    cout << "Error, no valid type" << endl;
  }
}
