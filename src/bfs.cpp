#include "bfs.h"

pair<vector<int>,int> bfs(const vector<vector<int>>& adjList, int src, int dest){

    queue<int> q;
    vector<bool> visited(adjList.size(), false);
    vector<int> parent(adjList.size(), -1);
    visited[src]=true;
    q.push(src);
    auto start = high_resolution_clock::now();

    // BFS
    while(!q.empty()){
        int u = q.front();
        q.pop();

        // Reconstruct path when we reach dest
        if(u == dest){
            vector<int> path;
            for(int i = dest; i != -1; i = parent[i]) path.push_back(i);
            reverse(path.begin(), path.end());
            auto end = high_resolution_clock::now();
            int delta = duration_cast<microseconds>(end - start).count();
            return{path, delta};
        }

        // Explore neighbors
        for(int neighbor : adjList[u]){
            if(!visited[neighbor]){
                visited[neighbor] = true;
                parent[neighbor] = u;
                q.push(neighbor);
            }
        }
    }
    return{{},-1};
}