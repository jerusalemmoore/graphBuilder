#include "Graph.h"
#include <iostream>

//add nodes to graph, check if id exists and return false if so
bool Graph::buildNode(std::variant<int,double,string> data, string id){
 if(!nodeExists(id)){
    Node* newNode = new Node(data, id);

    std::vector<Node*> newVector;
    std::pair<Node*, std::vector<Node*>> adjListPair (newNode, newVector);
    adjList.push_back(adjListPair);
    std::pair<std::string,Node*> nodeTablePair (newNode->getId(), newNode);
    nodeTable.insert(nodeTablePair);

    return true;
  }
  std::cout << "Error, node to add already exists\n";
  return false;
}
void Graph::addEdge(string start, string end){
  bool startDone = false;
  bool endDone = false;
  Node* startNode = nodeTable[start];
  Node* endNode = nodeTable[end];
  for(auto it = adjList.begin(); it < adjList.end(); it++){
    if(it->first->getId() == startNode->getId()){
      it->second.push_back(endNode);
      startDone = true;
    }
    if(it->first->getId() == endNode->getId()){
      it->second.push_back(startNode);
      endDone = true;
    }
    if(startDone && endDone){
      break;
    }
  }

}
//check if node id exists in graph and return true if it does
bool Graph::nodeExists(string id){
  for(auto it = adjList.begin(); it < adjList.end(); it++){
    if(it->first->getId() == id){
      return true;
    }
  }
  return false;
}
void Graph::printGraph(){
  for(auto it = adjList.begin(); it < adjList.end(); it++){
    it->first->printData();
    if(!it->second.empty()){
      std::cout << "Neighbors:\n";
      for(unsigned int i = 0; i < it->second.size(); i++){
        it->second[i]->printData();
      }
    }
  }
}
