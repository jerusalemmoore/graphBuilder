//#include "Node.h"
#include "Graph.h"
int main(){
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
  bool running = true;
  while(running == true){
    std::cout << "Choose an option 1, 2, 3, 4...\n";
    std::cout << "1. Make a vertex\n";
    std::cout << "2. Add a neighbor to a vertex\n";
    std::cout << "3. Print graph info\n";
    std::cout << "4. Quit\n";
    std::cin >> input;
    if(input == '1'){
      string id;
      string data;
      std::cout << "Enter an id for vertex";
      std::cin >> id;
      std::cout << "Enter data for vertex";
      std::cin >> data;
      newGraph.buildNode(data,id);

    }
    else if(input == '2'){

    }
    else if(input == '3'){
      newGraph.printGraph();
    }
    else if(input == '4'){
      running = false;
    }
    else{
      std::cout << "Error, not a valid option.\n\n";
    }
  }

  // newGraph.buildNode(data, "node1");
  // newGraph.buildNode(data2, "node2");
  // newGraph.buildNode(data3, "node3");
  // newGraph.buildNode(data4, "node4");
  // newGraph.addEdge("node1", "node2");
  // newGraph.addEdge("node1", "node2");
  // newGraph.addEdge("node1", "node3");
  // newGraph.addEdge("node1", "node4");
  // newGraph.addEdge("node1" , "node1");
  //
  // newGraph.printGraph();
  //delete newGraph;
}
