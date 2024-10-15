#include "iddfs.h"

pair<vector<int>,int> iddfs(const vector<vector<int>>& adjList, int src, int dest, int maxDepth){
    int V = adjList.size();
    auto start = high_resolution_clock::now();
    for(int depth = 0; depth <= maxDepth; depth++){
        vector<int> visited(V, false);
        vector<int> path;
        bool pathExists = dls(adjList, src, dest, depth, path, visited);
        if(pathExists){
            auto end = high_resolution_clock::now();
            int delta = duration_cast<microseconds>(end - start).count();
            return{path, delta};
        }
    }
    return{{},-1};
}

bool dls(const vector<vector<int>>& adjList, int u, int dest, int depth, vector<int>& path, vector<int>& visited){
    visited[u] = true;
    path.push_back(u);
    if(u == dest) return true;

    // Depth limit reached, backtrack
    if(depth == 0){
        path.pop_back();
        return false;
    }

    // Explore neighbors
    for(int neighbor: adjList[u]){
        if(!visited[neighbor]){
            if(dls(adjList, neighbor, dest, depth - 1, path, visited)) return true;
        }
    }

    // No solution at this depth, backtrack
    path.pop_back();
    return false;
}