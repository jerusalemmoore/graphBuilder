#include "Node.h"
#include <iostream>
#include <stdexcept>
#define INT 0
#define  DOUBLE 1
#define  STRING 2
using std::string;
using std::endl;
using std::cout;
using std::get;
Node::Node(std::variant<int,double,string> data){
  this->type = data.index();
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
void Node::printData(){
  if(type == INT){
    cout << *this->intPtr << endl;
  }
  else if(type == DOUBLE){
    cout << *this->doublePtr << endl;
  }
  else if (type == STRING){
    cout << *this->stringPtr << endl;
  }
  else{
    cout << "Error, no valid type" << endl;
  }
}
