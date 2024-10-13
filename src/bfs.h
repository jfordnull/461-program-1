#ifndef BFS_H
#define BFS_H
#include "graph.h"
#include <queue>
using std::queue;

pair<vector<int>,int> bfs(const vector<vector<int>>& adjList, int src, int dest);

#endif