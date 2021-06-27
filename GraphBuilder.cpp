//#include "Node.h"
#include <stdlib.h>
#include<unistd.h>

#include "GraphBuilder.h"
#define BACK "b"
using std::cout;
using std::cin;
using std::endl;
using std::string;
const int ESC = 27;

GraphBuilder::GraphBuilder(){
  running = true;

}
GraphBuilder::~GraphBuilder(){
  for(auto& it: graphs){
    delete it.second;
  }
}
bool GraphBuilder::confirmEntry(string entry){
  system("clear");//clear terminal before outputting view
  string input;
  bool interaction = true;
  //cin.clear();
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
void GraphBuilder::duplicateGraphError(string dupGraphName){
  string decision;
  cout << "Error, you already have a graph with the same name("<< dupGraphName << ")\n";
  cout << "Press any key to go back\n";
  cin >> decision;
}//YOU WERE WORKING ON THIS

/*
  Ask for name of graph
  Confirm name is correct
  Store name/graph into graphs map
*/
void GraphBuilder::buildGraphPage(){
  system("clear");
  string input;
  cout << "Please enter a unique name for the graph(press ESC, then ENTER to go back):\n";
  cin >> input;
  if(input.find(27) != std::string::npos){//check if ESC is entered
    return;
  }
  if(confirmEntry(input)){
    while(graphs.count(input)){//if graph already exists with entered name
      duplicateGraphError(input);
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

void GraphBuilder::getVertexData(string id){
  string data;
  cout << "Please enter  data for vertex(string, double, int).\n";
  cin >> data;
  if(confirmEntry(data)){
    graphs[currentGraph]->addVertex(data, id);
    usleep(1000000 * 1);
  }
  else{
    return getVertexData(id);
  }
}
void GraphBuilder::noGraphsError(){
  string input;
  cout << "Error, there are currently no graphs to add vertices to. Please build a graph first...\n";
  cout << "Press any key to go back\n";
  cin >> input;
  // if(id == BACK){
  //   return;
  // }
}
void GraphBuilder::duplicateVertexError(string vertName, string currGraphName){
  string input;
  cout << "Error, you already have a vertex named "<< vertName << " in graph named " << currGraphName << "\n";
  cout << "Press any key to go back\n";
  cin >> input;
}

/*
  Ask for id of vertex
  Confirm id is corrrect
  enter data into vertex
  confirm data is correct
*/
void GraphBuilder::addVertexPage(){
  system("clear");
  string id;
  while(currentGraph.empty()){//if graph builder isn't assigned it means there aren't any graphs built by user yet
    // cout << "Error, there are currently no graphs to add vertices to. Please build a graph first...\n";
    // cout << "Press b to go back\n";
    // cin >> id;
    // if(id == BACK){
    //   return;
    // }
    noGraphsError();
    return;
  }
  cout << "Please enter a unique name for a new vertex(press ESC, then ENTER to go back):\n";
  cin >> id;
  if(id.find(27) != std::string::npos){//check if ESC is entered
    return;
  }
  if(confirmEntry(id)){
    string decision;
    while(graphs[currentGraph]->nodeExists(id)){
      duplicateVertexError(id, currentGraph);
      return addVertexPage();

    }
    //graphs[input] = new Graph();
    //cout << "Success, new graph built\n";
    //this->currentGraph = input;
    getVertexData(id);
  }
  else{
    return addVertexPage();
  }

}
/*
  get id of vertex to delete
  run remove
  if true success
  if false error
*/
void GraphBuilder::removeVertexPage(){

  Graph* currGraph = graphs[currentGraph];
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
  char input;
  while(running){
    system("clear");
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
