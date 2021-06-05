//#include "Node.h"
#include "Graph.h"
int main(){
  //NODE TESTING
  int data = 26;
  // Node* newNode = new Node(data, "node1");
  double data2 = 26.23;
  // Node* newNode2 = new Node(data2, "node2");
  string data3 = "hello string";
  // Node* newNode3 = new Node(data3, "node3");
  // newNode->printData();
  // newNode2->printData();
  // newNode3->printData();
  //GRAPH TESTING
  Graph* newGraph = new Graph();
  newGraph->buildNode(data, "node1");
  newGraph->buildNode(data2, "node2");
  newGraph->addEdge("node1", "node2");
  newGraph->printGraph();
}
