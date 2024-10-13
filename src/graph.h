#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
using std::vector;
using std::string;
using std::unordered_map;

class Graph {
private:
    vector<vector<int>> adjList;
    unordered_map<string,int> cityMap;
    void addEdge(int src, int dest);
    void parseCSV(const string& fileName);
    void parseAdjacencies(const string& fileName);
    vector<string> indexToCity;
public:
    Graph(const string& csv, const string& adjacencies);
    void printGraph();
};

#endif GRAPH_H