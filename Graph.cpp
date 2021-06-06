#include "Graph.h"
#include <iostream>

Graph::~Graph(){
  for(auto& it: nodeTable){
    delete it.second;
  }
  // delete this;
}
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
bool Graph::alreadyNeighbor(string neighborId, std::vector<Node*> v){
  Node* neighborNode = nodeTable[neighborId];
  for(auto it = v.begin(); it < v.end(); it++){
    if((*it)->getId() == neighborId){
      return true;//neighbor already in vector
    }
  }
  return false;

}
void Graph::addEdge(string start, string end){
  bool startDone = false;
  bool endDone = false;
  if(start == end){
    std::cout << "Error, vertex cannot be its own neighbor";
    return;
  }
  Node* startNode = nodeTable[start];
  Node* endNode = nodeTable[end];
  for(auto it = adjList.begin(); it < adjList.end(); it++){
    if(it->first->getId() == startNode->getId()){
      if(!alreadyNeighbor(end, it->second)){
        it->second.push_back(endNode);
        startDone = true;
      }
      else{
        std::cout << "Error, " << start << " already neighbors with " << end << std::endl;
      }

    }
    if(it->first->getId() == endNode->getId()){
      if(!alreadyNeighbor(start, it->second)){
        it->second.push_back(startNode);
        endDone = true;
      }
      else{
        std::cout << "Error, " << end << " already neighbors with " << start << std::endl;
      }
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
    std::cout << it->first->getData() << std::endl;
    if(!it->second.empty()){
      std::cout << "Neighbors:\n";
      for(unsigned int i = 0; i < it->second.size(); i++){
        std::cout << "\t" << it->second[i]->getData();
        std::cout << "\n";
      }
      std::cout<<"\n";
    }
  }
}
