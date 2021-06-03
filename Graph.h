#include "Node.h"
#include <vector>
#include <iostream>
#include <stdexcept>
class Graph{
public:
  Graph(){};
  void buildNode(std::variant<int,double,string> data, string id);
  void addEdge(Node* start, Node* end);
  void printGraph();
  bool nodeExists(string id);
private:
  std::vector<std::pair<Node*,std::vector<Node*>>> adjList;
};
