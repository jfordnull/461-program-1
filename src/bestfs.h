#ifndef BESTFS_H
#define BESTFS_H

#include "util.h"

pair<vector<int>,int> bestFS(const vector<vector<int>>& adjList, const vector<pair<float,float>>& coordinates, int src, int dest);

#endif