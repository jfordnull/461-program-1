#include "graph.h"

Graph::Graph(int size) : adjList(vector<vector<int>>(size)){}

void Graph::addEdge(int u, int v){
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}