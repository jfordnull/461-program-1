#include "graph.h"
#include "bfs.h"
#include "dfs.h"
#include "iddfs.h"
#include "bestfs.h"
#include "astar.h"

void printResults(const Graph& graph, pair<vector<int>,int> results, const string& algorithm){
    graph.printRoute(results.first);
    cout << algorithm << " execution time: " << results.second << " microseconds" << endl;
    cout << "Cost (node traversal): " << results.first.size() << endl;
}

int main(){
    string csvFile = "input/coordinates.csv";
    string adjFile = "input/Adjacencies.txt";
    Graph graph(csvFile, adjFile);
    const vector<vector<int>> adjList = graph.getAdjList();
    const vector<pair<float,float>> coords = graph.getCoordinates();
    int maxDepth = 10; // For IDDFS

    while(true){
        string cityA, cityB;
        int nodeA, nodeB;
        bool validInput = false;
        while(!validInput){
            try{
                cout << "Enter city A: ";
                cin >> cityA;
                nodeA = graph.getCityIndex(cityA);
                cout << "Enter city B: ";
                cin >> cityB;
                nodeB = graph.getCityIndex(cityB);
                validInput = true;
            }
            catch(const runtime_error& e){
                cout << e.what() << " Try again." << endl;
            }
        }

        validInput = false;
        int choice;
        while(!validInput){
            cout << "Select a search algorithm:" << endl;
            cout << "1. Breadth-First Search (BFS)" << endl;
            cout << "2. Depth-First Search (DFS)" << endl;
            cout << "3. Iterative Deepening DFS (IDDFS)" << endl;
            cout << "4. Best-First Search (BestFS)" << endl;
            cout << "5. A*" << endl;
            cout << "Enter your choice (1-5): ";
            cin >> choice;
            if (cin.fail() || choice < 1 || choice > 5) {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "Invalid choice. Please enter a number between 1 and 5.\n";
                continue;
            } else validInput = true;
            
            pair<vector<int>,int> results;
            switch(choice){
                case 1:
                    results = bfs(adjList, nodeA, nodeB);
                    printResults(graph, results, "Breadth-First Search");
                    break;
                case 2:
                    results = dfs(adjList, nodeA, nodeB);
                    printResults(graph, results, "Depth-First Search");
                    break;
                case 3:
                    results = iddfs(adjList, nodeA, nodeB, maxDepth);
                    printResults(graph, results, "Iterative Deepening Depth-First Search");
                    break;
                case 4:
                    results = bestFS(adjList, coords, nodeA, nodeB);
                    printResults(graph, results, "Best-First Search (Heuristic := Euclidean Distance)");
                    break;
                case 5:
                    results = aStar(adjList, coords, nodeA, nodeB);
                    printResults(graph, results, "A* (Heuristic := Euclidean Distance)");
                    break;
                default:
                    break;
            }
        }

        char repeat;
        cout << "Search again? (y/n)";
        cin >> repeat;
        if(repeat == 'n') break;
    }
}