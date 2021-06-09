#include "Graph.h"
class GraphBuilder{
  public:
    GraphBuilder();
    ~GraphBuilder();
    void buildGraph();
    void runBuilder();
    void makeGraph();
    void addVertex();
    void removeVertex();
    void addNeighbor();
    void removeNeighbor();
    void printAllData();
    void listVertices();
    void printVertexInfo();
    //void runAlgorithm();
  private:
    std::unordered_map<string, Graph*> graphs;
    bool running;
    string currentGraph;
};
