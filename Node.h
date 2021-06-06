#include <variant>
#include <string>
#include <cassert>
#include <iostream>

using std::string;
class Node{
  public:
    Node(std::variant<int,double,string> data, string id);//allows a node to hold multiple types of data
    string getId();
    string getData();//print data inside of node
    ~Node();
  private:
    string id;
    int* intPtr;
    double* doublePtr;
    string* stringPtr;
    int type;
};
