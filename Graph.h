#include "Node.h"
#include <vector>
#include <iostream>
#include <stdexcept>
#include <unordered_map>

//currently an undirected graph implementation
class Graph{
public:
  Graph(){};
  ~Graph();
  bool buildNode(std::variant<int,double,string> data, string id);
  void addEdge(string start,  string end);
  void printGraph();
  bool alreadyNeighbor(string neighborId, std::vector<Node*> v);
  bool nodeExists(string id);
private:
  std::unordered_map<string,Node*> nodeTable;//lookup for all existing nodes of graph
  std::vector<std::pair<Node*,std::vector<Node*>>> adjList;//vector of pointers to nodes and a vector of the nodes pointers
};
