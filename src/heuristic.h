#ifndef HEURISTIC_H
#define HEURISTIC_H

#include "util.h"

float heuristic(int node, int dest, const vector<pair<float,float>>& coordinates);
vector<float> generateHeuristics(const vector<pair<float,float>>& coordinates, int dest);

struct Node{
    int vertex;
    double heursticValue;

    bool operator > (const Node& other) const{
        return heursticValue > other.heursticValue;
    }
};

#endif