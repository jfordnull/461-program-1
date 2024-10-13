#include "graph.h"
#include <stdexcept>
using std::runtime_error;

Graph::Graph(const string& csv, const string& adjacencies){
    parseCSV(csv);
    parseAdjacencies(adjacencies);
}

void Graph::addEdge(int u, int v){
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void Graph::parseCSV(const string& fileName){
    ifstream file(fileName);
    string line;
    int i = 0;
    if(!file.is_open()){return;}
    while(getline(file, line)){
        stringstream ss(line);
        string city;
        if(getline(ss, city, ',')){
            cityMap[city]=i++;
            indexToCity.push_back(city);
            adjList.push_back({});
        }
    }
    file.close();
}

void Graph::parseAdjacencies(const string& fileName){
    ifstream file(fileName);
    string line;
    if(!file.is_open()){return;}
    while(getline(file, line)){
        stringstream ss(line);
        string city1, city2;
        if(ss >> city1 >> city2){addEdge(cityMap[city1],cityMap[city2]);}
    }
    file.close();
}

void Graph::printGraph() const{
    for(int i = 0; i < adjList.size(); i++){
        cout << indexToCity[i] << " -> ";
        for(int neighbor : adjList[i]){cout << indexToCity[neighbor] << " ";}
        cout << endl;
    }
}

int Graph::getCityIndex(const string& city) const{
    auto it = cityMap.find(city);
    if(it!=cityMap.end()){return it->second;}
    else{throw runtime_error(city + " not found in map.");}
}

void Graph::printRoute(const vector<int>& route) const{
    for(int city : route){cout << indexToCity[city] << " -> ";}
    cout << "EOR" << endl;
}