#ifndef IDDFS_H
#define IDDFS_H

#include "util.h"

pair<vector<int>,int> iddfs(const vector<vector<int>>& adjList, int src, int dest, int maxDepth);
bool dls(const vector<vector<int>>& adjList, int u, int dest, int depth, vector<int>& path, vector<int>& visited);

#endif 