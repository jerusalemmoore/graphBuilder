#include <functional>
#include "Graph.h"
class GraphBuilder{
  public:
    GraphBuilder();
    ~GraphBuilder();
    void clearScreen();
    void buildGraphPage();
    void runBuilder();
    void addVertexPage();
    void getVertexData(string id);
    void removeVertexPage();
    void addNeighborPage();
    void removeNeighborPage();
    void printCurrentGraph();
    void listCurrentVertices();
    void printVertexInfoPage();
    void listAllGraphs();
    //Note: Error functions work like a simple view to notify user of problem and return after taking any input
    void duplicateGraphError(string dupGraphName);
    void duplicateVertexError(string vertName, string currGraphName);//LAST THING YOU DID, DO REMOVE VERTEX VIEW NEXT
    void noGraphsError();


    bool confirmEntry(string entry);

    //void runAlgorithm();
  private:
    std::unordered_map<string, Graph*> graphs;
    //build doubly linked list for traversing graphs
    bool running;
    string currentGraph;
};
