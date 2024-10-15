#include "graph.h"
#include "bfs.h"
#include "dfs.h"
#include "iddfs.h"
#include "bestfs.h"
#include "astar.h"

int main(){
    string csvFile = "input/coordinates.csv";
    string adjFile = "input/Adjacencies.txt";

    Graph graph(csvFile, adjFile);

    const vector<vector<int>> adjList = graph.getAdjList();
    int cityA = graph.getCityIndex("Augusta");
    int cityB = graph.getCityIndex("Zenda");

    pair<vector<int>,int> bfsResults = bfs(adjList, cityA, cityB);
    graph.printRoute(bfsResults.first);
    cout << "Breadth-first execution time: " << bfsResults.second << " microseconds" << endl;

    pair<vector<int>,int> dfsResults = dfs(adjList, cityA, cityB);
    graph.printRoute(dfsResults.first);
    cout << "Depth-first execution time: " << dfsResults.second << " microseconds" << endl;

    int maxDepth = 10;
    pair<vector<int>,int> iddfsResults = iddfs(adjList, cityA, cityB, maxDepth);
    graph.printRoute(iddfsResults.first);
    cout << "IDDFS execution time (max depth := " << maxDepth << " ): " << iddfsResults.second << " microseconds" << endl;

    const vector<pair<float,float>> coord = graph.getCoordinates();
    pair<vector<int>,int> bestfsResults = bestFS(adjList, coord, cityA, cityB);
    graph.printRoute(bestfsResults.first);
    cout << "BestFS execution time: " << bestfsResults.second << " microseconds" << endl;

    pair<vector<int>,int> astarResults = aStar(adjList, coord, cityA, cityB);
    graph.printRoute(astarResults.first);
    cout << "A* execution time: " << astarResults.second << " microseconds" << endl;
}