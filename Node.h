#include <variant>
#include <string>
#include <cassert>
#include <iostream>

using std::string;
class Node{
  public:
    Node(int intPtr);
    Node(double doublePtr);
    Node(string stringPtr);
    void printData();
    ~Node();
  private:
    int* intPtr;
    double* doublePtr;
    string* stringPtr;
    string type;
};
