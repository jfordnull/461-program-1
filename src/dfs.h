#ifndef DFS_H
#define DFS_H

#include "util.h"

pair<vector<int>,int> dfs(const vector<vector<int>>& adjList, int src, int dest);
bool rescursiveDFS(const vector<vector<int>>& adjList, int u, int dest, vector<int>& path, vector<bool>& visited);

#endif