//#include "Node.h"
#include "GraphBuilder.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;
GraphBuilder::GraphBuilder(){
  running = true;

}
GraphBuilder::~GraphBuilder(){

}
bool GraphBuilder::confirmEntry(string entry){
  string input;
  bool interaction = true;
  while(interaction){
  cout << "Is this information correct: y/n\n" << entry << endl;
  cin >> input;
  if(input == "n"){
    return false;
  }
  else if(input =="y"){
    return true;
  }
  else{
    cout << "Invalid entry...\n";
  }
}
return false;
}
/*
  Ask for name of graph
  Confirm name is correct
  Store name/graph into graphs map
*/
void GraphBuilder::buildGraphPage(){
  string input;
  cout << "Please enter a unique name for the graph:\n";
  cin >> input;
  if(confirmEntry(input)){
    if(graphs.count(input)){
      cout << "Error, you already have a graph with the same name\n";

      return buildGraphPage();
    }
    graphs[input] = new Graph();
    cout << "Success, new graph built\n";
    this->currentGraph = input;
  }
  else{
    return buildGraphPage();
  }


}
/*
  Ask for id of vertex
  Confirm id is corrrect
  enter data into vertex
  confirm data is correct
*/
void GraphBuilder::addVertexPage(){

}
/*
  get id of vertex to delete
  run remove
  if true success
  if false error
*/
void GraphBuilder::removeVertexPage(){

}
/*
  get start id  and end id
*/
void GraphBuilder::addNeighborPage(){

}
void GraphBuilder::removeNeighborPage(){

}
void GraphBuilder::printCurrentGraph(){

}
void GraphBuilder::listCurrentVertices(){

}
void GraphBuilder::printVertexInfoPage(){

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
      buildGraphPage();
      // string id;
      // string data;
      // std::cout << "Enter an id for vertex";
      // std::cin >> id;
      // std::cout << "Enter data for vertex";
      // std::cin >> data;
      // newGraph.buildVertex(data,id);


    }
    else if(input == '2'){
      addVertexPage();
    }
    else if(input == '3'){
      removeVertexPage();
    }
    else if(input == '4'){
      addNeighborPage();
    }
    else if(input == '5'){
      removeNeighborPage();
    }
    else if(input == '6'){
      printCurrentGraph();
    }
    else if(input == '7'){
      listCurrentVertices();
    }
    else if(input == '8'){
      printVertexInfoPage();
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
