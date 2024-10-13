#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
using std::vector;

class Graph {
private:
    vector<vector<int>> adjList;
public:
    Graph(int size);
    void addEdge(int src, int dest);
};

#endif GRAPH_H