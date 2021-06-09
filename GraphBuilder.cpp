//#include "Node.h"
#include "GraphBuilder.h"
GraphBuilder::GraphBuilder(){
  running = true;

}
GraphBuilder::~GraphBuilder(){

}
void GraphBuilder::buildGraph(){

}
void GraphBuilder::makeGraph(){

}
void GraphBuilder::addVertex(){

}
void GraphBuilder::removeVertex(){

}
void GraphBuilder::addNeighbor(){

}
void GraphBuilder::removeNeighbor(){

}
void GraphBuilder::printAllData(){

}
void GraphBuilder::listVertices(){

}
void GraphBuilder::printVertexInfo(){

}
void GraphBuilder::runBuilder(){
  //NODE TESTING
  int data = 26;
  // Node* newNode = new Node(data, "node1");
  double data2 = 26.23;
  // Node* newNode2 = new Node(data2, "node2");
  string data3 = "hello string";
  double data4 = 49.66698;
  // Node* newNode3 = new Node(data3, "node3");
  // newNode->printData();
  // newNode2->printData();
  // newNode3->printData();
  //GRAPH TESTING
  Graph newGraph = Graph();
  char input;
  while(running){
    if(graphs.empty()){
      std::cout << "Current Graph: No graphs built\n\n";
    }
    else{
      std::cout << "Current Graph: " << currentGraph << "\n\n";
    }
    std::cout << "Choose an option 1, 2, 3, 4...\n";
    std::cout << "1. Make a Graph\n";
    std::cout << "2. Make a vertex\n";
    std::cout << "3. Remove a vertex\n";
    std::cout << "4. Add a neighbor to a vertex\n";
    std::cout << "5. Remove a neighbor from a vertex\n";
    std::cout << "6. Print graph info\n";
    std::cout << "7. List all vertice id's\n";
    std::cout << "8. Print vertex info\n";
    std::cout << "9. Quit\n";
    std::cin >> input;
    if(input == '1'){
      makeGraph();
      // string id;
      // string data;
      // std::cout << "Enter an id for vertex";
      // std::cin >> id;
      // std::cout << "Enter data for vertex";
      // std::cin >> data;
      // newGraph.buildVertex(data,id);


    }
    else if(input == '2'){
      addVertex();
    }
    else if(input == '3'){
      removeVertex();
    }
    else if(input == '4'){
      addNeighbor();
    }
    else if(input == '5'){
      removeNeighbor();
    }
    else if(input == '6'){
      printAllData();
    }
    else if(input == '7'){
      listVertices();
    }
    else if(input == '8'){
      printVertexInfo();
    }
    else if(input == '9'){
        running = false;
    }
    else{
      std::cout << "Error, not a valid option.\n\n";
    }
  }

  // newGraph.addVertex(data, "node1");
  // newGraph.addVertex(data2, "node2");
  // newGraph.addVertex(data3, "node3");
  // newGraph.addVertex(data4, "node4");
  // newGraph.addEdge("node1", "node2");
  // newGraph.addEdge("node1", "node2");
  // newGraph.addEdge("node1", "node3");
  // newGraph.addEdge("node1", "node4");
  // newGraph.addEdge("node1" , "node1");
  // newGraph.printGraph();
  // newGraph.removeEdge("node4", "node1");
  // newGraph.printGraph();

}

int main(){
  GraphBuilder builder;
  builder.runBuilder();
}
