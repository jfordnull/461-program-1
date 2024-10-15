#include "heuristic.h"

// Heuristic := Euclidean distance
float heuristic(int node, int dest, const vector<pair<float,float>>& coordinates){
    float dx = coordinates[node].first - coordinates[dest].first;
    float dy = coordinates[node].second - coordinates[dest].second;
    return static_cast<float>(sqrt(dx * dx + dy * dy));
}

vector<float> generateHeuristics(const vector<pair<float,float>>& coordinates, int dest){
    vector<float> heuristics(coordinates.size());
    for(int i = 0; i < coordinates.size(); i++) heuristics[i] = heuristic(i, dest, coordinates);
    return heuristics;
}