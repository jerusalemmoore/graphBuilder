#include <variant>
#include <string>
#include <cassert>
#include <iostream>

using std::string;
class Node{
  public:
    Node(std::variant<int,double,string> data);
    void printData();
    ~Node();
  private:
    int* intPtr;
    double* doublePtr;
    string* stringPtr;
    int type;
};
