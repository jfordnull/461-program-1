#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <sstream>
using std::vector;
using std::string;
using std::unordered_map;
using std::ifstream;
using std::stringstream;
using std::cout;
using std::endl;
using std::pair;

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
    int getCityIndex(const string& city) const;
    const vector<vector<int>>& getAdjList() {return adjList;}
    void printGraph() const;
    void printRoute(const vector<int>& route) const;
};

#endif