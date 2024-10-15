#ifndef ASTAR_H
#define ASTAR_H

#include "util.h"

pair<vector<int>, int> aStar(const vector<vector<int>>& adjList, const vector<pair<float,float>>& coordinates, int src, int dest);

#endif