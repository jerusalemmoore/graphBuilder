#include "Graph.h"
class GraphBuilder{
  public:
    GraphBuilder();
    ~GraphBuilder();
    void buildGraphPage();
    void runBuilder();
    void addVertexPage();
    void removeVertexPage();
    void addNeighborPage();
    void removeNeighborPage();
    void printCurrentGraph();
    void listCurrentVertices();
    void printVertexInfoPage();
    void listAllGraphs();
    bool confirmEntry(string entry);

    //void runAlgorithm();
  private:
    std::unordered_map<string, Graph*> graphs;
    //build doubly linked list for traversing graphs
    bool running;
    string currentGraph;
};
