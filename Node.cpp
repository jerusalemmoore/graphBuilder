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
Node::~Node(){
  switch(type){
    case INT:{
      delete this->intPtr;

      break;
    }
    case DOUBLE:{
      delete this->doublePtr;
      break;
    }
    case STRING:{
      delete this->stringPtr;
      break;
    }
  }
}
string Node::getId(){

  return id;
}
string Node::getData(){
  if(type == INT){
    return "id: " + this->id + "; value: " + std::to_string(*this->intPtr);
  }
  else if(type == DOUBLE){
    return "id: " + this->id + "; value: " +  std::to_string(*this->doublePtr);
  }
  else if (type == STRING){
    return "id: " + this->id + "; value: " +  *this->stringPtr;
  }
  else{
    return "Error, no valid type";
  }
}
