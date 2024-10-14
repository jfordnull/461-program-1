#include "graph.h"
#include "bfs.h"
#include "dfs.h"

int main(){
    string csvFile = "src/coordinates.csv";
    string adjFile = "src/Adjacencies.txt";
    Graph graph(csvFile, adjFile);
    pair<vector<int>,int> bfsResults = bfs(graph.getAdjList(), graph.getCityIndex("Viola"), graph.getCityIndex("Sawyer"));
    graph.printRoute(bfsResults.first);
    cout << "Breadth-first execution time: " << bfsResults.second << " microseconds" << endl;
    pair<vector<int>,int> dfsResults = dfs(graph.getAdjList(), graph.getCityIndex("Viola"), graph.getCityIndex("Sawyer"));
    graph.printRoute(dfsResults.first);
    cout << "Depth-first execution time: " << dfsResults.second << " microseconds" << endl;
    graph.printGraph();

}