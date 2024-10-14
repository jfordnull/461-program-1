#include "dfs.h"

pair<vector<int>,int> dfs(const vector<vector<int>>& adjList, int src, int dest){
    vector<bool> visited (adjList.size(), false);
    vector<int> path;
    auto start = high_resolution_clock::now();
    bool pathExists = rescursiveDFS(adjList, src, dest, path, visited);
    auto end = high_resolution_clock::now();
    int delta = duration_cast<microseconds>(end - start).count();
    if(pathExists) return {path, delta};
    else return {{},-1};
}

bool rescursiveDFS(const vector<vector<int>>& adjList, int u, int dest, vector<int>& path, vector<bool>& visited){
    visited[u] = true;
    path.push_back(u);
    if(u == dest) return true;

    // Explore neighbors
    for(int neighbor : adjList[u]){
        if(!visited[neighbor]){
            if(rescursiveDFS(adjList, neighbor, dest, path, visited)) return true;
        }
    }

    // Backtrack
    path.pop_back();
    return false;
}