#include "graph.h"
#include "bfs.h"
#include "dfs.h"
#include "iddfs.h"

int main(){
    string csvFile = "src/coordinates.csv";
    string adjFile = "src/Adjacencies.txt";

    Graph graph(csvFile, adjFile);

    pair<vector<int>,int> bfsResults = bfs(graph.getAdjList(), graph.getCityIndex("Augusta"), graph.getCityIndex("Cheney"));
    graph.printRoute(bfsResults.first);
    cout << "Breadth-first execution time: " << bfsResults.second << " microseconds" << endl;

    pair<vector<int>,int> dfsResults = dfs(graph.getAdjList(), graph.getCityIndex("Augusta"), graph.getCityIndex("Cheney"));
    graph.printRoute(dfsResults.first);
    cout << "Depth-first execution time: " << dfsResults.second << " microseconds" << endl;

    int maxDepth = 10;
    pair<vector<int>,int> iddfsResults = iddfs(graph.getAdjList(), graph.getCityIndex("Augusta"), graph.getCityIndex("Cheney"), maxDepth);
    graph.printRoute(iddfsResults.first);
    cout << "IDDFS execution time (max depth := " << maxDepth << " ): " << iddfsResults.second << " microseconds" << endl;
}