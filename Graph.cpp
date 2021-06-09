#include "Graph.h"
#include <iostream>

Graph::~Graph(){
  for(auto& it: nodeTable){
    delete it.second;
  }
  // delete this;
}
//add nodes to graph, check if id exists and return false if so
bool Graph::addVertex(std::variant<int,double,string> data, string id){
 if(!nodeExists(id)){
    Node* newNode = new Node(data, id);

    std::vector<Node*> newVector;
    std::pair<Node*, std::vector<Node*>> adjListPair (newNode, newVector);
    adjList.push_back(adjListPair);
    std::pair<std::string,Node*> nodeTablePair (newNode->getId(), newNode);
    nodeTable.insert(nodeTablePair);
    std::cout << "Success, node built.\n";
    return true;
  }
  std::cout << "Error, node to add already exists\n";
  return false;
}
void Graph::removeFromNeighbors(Node* targetVertex){
  for(auto it = adjList.begin(); it != adjList.end(); it++){
    for(unsigned int i = 0; i < it->second.size(); i++){
      if(targetVertex == it->second[i]){
        it->second.erase(it->second.begin() + i);
      }
    }
  }
}
bool Graph::removeVertex(string id){
  if(nodeTable.find(id) == nodeTable.end()){
    std::cout << "Error, vertex to delete("<< id << ") does not exist\n";
    return false;
  }
  Node* targetVertex = nodeTable[id];
  removeFromNeighbors(targetVertex);
  for(auto it = adjList.begin(); it != adjList.end(); it++){
    if(targetVertex == it->first){
      adjList.erase(it);
      break;
    }
  }
  nodeTable.erase(id);
  return true;
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
    std::cout << "Error, vertex cannot be its own neighbor\n";
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
void Graph::removeEdge(string target, string neighbor){
  Node* targetVertex = nodeTable[target];
  Node* neighborVertex = nodeTable[neighbor];
  for(auto it = adjList.begin(); it != adjList.end(); it++){
    if(targetVertex == it->first){
      for(unsigned int i = 0; i < it->second.size(); i++){
        if(neighborVertex == it->second[i]){
          std::cout << "deleted\n";
          it->second.erase(it->second.begin() + i);
        }
      }
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
void Graph::listVertexIds(){
    for(auto it = adjList.begin(); it < adjList.end(); it++){
      std::cout << it->first->getId() << "\n";
    }
}
