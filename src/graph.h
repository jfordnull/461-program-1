#ifndef GRAPH_H
#define GRAPH_H

#include "util.h"

class Graph {
private:
    vector<vector<int>> adjList;
    unordered_map<string,int> cityMap;
    void addEdge(int src, int dest);
    void parseCSV(const string& fileName);
    void parseAdjacencies(const string& fileName);
    vector<string> indexToCity;
    vector<pair<float,float>> coordinates;
public:
    Graph(const string& csv, const string& adjacencies);
    int getCityIndex(const string& city) const;
    const vector<vector<int>>& getAdjList() {return adjList;}
    const pair<float,float> getCoordinates(int v) {return coordinates[v];}
    void printGraph() const;
    void printRoute(const vector<int>& route) const;
};

#endif