#include "graph.h"
#include "bfs.h"
#include <iostream>
using std::cout;
using std::endl;

int main(){
    string csvFile = "src/coordinates.csv";
    string adjFile = "src/Adjacencies.txt";
    Graph graph(csvFile, adjFile);
    pair<vector<int>,int> bfsResults = bfs(graph.getAdjList(), graph.getCityIndex("Kiowa"), graph.getCityIndex("Hillsboro"));
    graph.printRoute(bfsResults.first);
    cout << "Breadth-first execution time: " << bfsResults.second << " microseconds" << endl;
}