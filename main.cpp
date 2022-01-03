// Breadth First Search
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// data structure to store graph edges
struct Edge {
    int src;
    int dest;
};

// class to represent a graph object
class Graph {
public:
    // construct a vector of vectors to represent an adjacency list
    vector<vector<int>> adjList;

    // Graph Constructor
    Graph(vector<Edge> &edges, int N) {
        // resize the vector to N elements of type vector<int>
        adjList.resize(N);

        // add edges to the undirected graph
        for (auto &edge: edges) {
            adjList[edge.src].push_back(edge.dest);
//            adjList[edge.dest].push_back(edge.src);
        }
    }
};

// Perform BFS on graph starting from vertex v
// BFS algorithm is referenced from https://www.geeksforgeeks.org/snake-ladder-problem-2/
int BFS(Graph &graph, int startV, vector<bool> &discovered) {
    for (int i = 0; i < 100; i++) {
        discovered[i] = false;
    }
    // create a queue used to do BFS
    queue<Edge> qu;

    // mark the starting vertex as discovered
    discovered[startV] = true;

    // push the starting vertex into queue
    qu.push({0, 0});

    Edge e;

    // loop till queue is empty
    while (!qu.empty()) {
        e = qu.front();
        int currentV = e.src;

        // If current vertex is the destination vertex
        // break the loop
        if (currentV == 99) {
            break;
        }

        // Pop first vertex from queue
        qu.pop();

        // process the adjacency list
        for (int adjV = currentV + 1; adjV <= (currentV + 6) && adjV < 100; adjV++) {
            if (!discovered[adjV]) {
                // mark as discovered and put it in the queue
                Edge f;
                f.dest = (e.dest + 1);
                discovered[adjV] = true;

                if (!graph.adjList[adjV].empty()) {
                    f.src = *graph.adjList[adjV].data();
                } else {
                    f.src = adjV;
                }
                qu.push(f);
            }
        }
    }

    return e.dest;
}

// Breadth First Search (BFS)
int main() {
    // vector of graph edges as per above diagram
    vector <Edge> edges = {
            {1, 24}, {19, 4}, {11, 33},
            {28, 10}, {38, 56}, {35, 21},
            {44, 52}, {45, 26}, {48, 71},
            {63, 40}, {58, 80}, {84, 66},
            {62, 95}, {90, 69}, {75, 86},
            {97,81}
    };

    // Number of vertices in the graph
    int N = 100;

    // create a graph from given edges
    Graph graph(edges, N);

    // stores vertex is visited or not
    vector <bool> discovered(N);

    cout << "The minimum number of rolls needed to reach the end of this game is "
         << BFS(graph, 0, discovered) << endl;

    return 0;
}
