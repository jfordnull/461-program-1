#include "graph.h"
#include <iostream>
using std::cout;
using std::endl;

int main(){
    string csvFile = "src/coordinates.csv";
    string adjFile = "src/Adjacencies.txt";
    Graph graph(csvFile, adjFile);
    graph.printGraph();
}