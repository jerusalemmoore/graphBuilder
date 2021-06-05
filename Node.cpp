#include "Node.h"
#include <stdio.h>
#include <iostream>
#include <stdexcept>
#define INT 0
#define  DOUBLE 1
#define  STRING 2
using std::string;
using std::endl;
using std::cout;
using std::get;
Node::Node(std::variant<int,double,string> data, string id){
  this->id = id;
  this->type = data.index();//this is to know what type of data type the value of the node will have
  switch(type){
    case INT:{
      int val = get<int>(data);
      this->intPtr = new int(val);
      break;
    }
    case DOUBLE:{
      double val = get<double>(data);
      this->doublePtr = new double(val);
      break;
    }
    case STRING:{
      string val = get<string>(data);
      this->stringPtr = new string(val);
      break;
    }
  }
}
string Node::getId(){

  return id;
}
void Node::printData(){
  if(type == INT){
    cout << "id: " << this->id << "; value: " << *this->intPtr << endl;
  }
  else if(type == DOUBLE){
    cout << "id: " << this->id << "; value: " <<  *this->doublePtr << endl;
  }
  else if (type == STRING){
    cout << "id: " << this->id << "; value: " <<  *this->stringPtr << endl;
  }
  else{
    cout << "Error, no valid type" << endl;
  }
}
