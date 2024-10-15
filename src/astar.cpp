#include "astar.h"
#include "heuristic.h"

pair<vector<int>, int> aStar(const vector<vector<int>>& adjList, const vector<pair<float,float>>& coordinates, int src, int dest){
    int V = adjList.size();
    vector<float> h = generateHeuristics(coordinates, dest); // h(x)
    vector<float> g(V, INT_MAX); // g(x)
    vector<int> parent(V, -1);       
    vector<bool> visited(V, false);
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    g[src] = 0;
    pq.push({src, h[src]});

    auto start = high_resolution_clock::now();
    while (!pq.empty()) {
        Node currentNode = pq.top();
        pq.pop();
        int u = currentNode.vertex;

        // Solution found, reconstruct path
        if (u == dest) {
            vector<int> path;
            for (int i = dest; i != -1; i = parent[i]) path.push_back(i);
            reverse(path.begin(), path.end());
            auto end = high_resolution_clock::now(); 
            int delta = duration_cast<microseconds>(end - start).count();
            return{path, delta};
        }

        if (visited[u]) continue;
        visited[u] = true;

        // Explore neighbors
        for (int neighbor : adjList[u]) {
            float gNew = g[u] + 1.0f;  // Assuming uniform cost of 1
            if (gNew < g[neighbor]) {
                parent[neighbor] = u;
                g[neighbor] = gNew;
                pq.push({neighbor, g[neighbor] + h[neighbor]}); // f(x) = g(x) + h(x)
            }
        }
    }

    return{{}, -1};
}