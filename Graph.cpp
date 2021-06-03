#include "Graph.h"
#include <iostream>

void Graph::buildNode(std::variant<int,double,string> data, string id){
//  if(!nodeExists(id)){
  Node* newNode = new Node(data, id);
  std::vector<Node*> newVector;
  std::pair<Node*, std::vector<Node*>> adjListPair (newNode, newVector);
  adjList.push_back(adjListPair);
  // }
  // else{
  //   std::cout << "Error, node to add already exists\n";
  // }
}
void Graph::addEdge(Node* start, Node* end){

}
bool Graph::nodeExists(string id){
  for(auto i = adjList.begin(); i < adjList.end(); i++){
    std::cout << "node\n";
  }
  return true;
}
void Graph::printGraph(){
  for(auto i = adjList.begin(); i < adjList.end(); i++){
    std::cout << "node\n";
  }
}
