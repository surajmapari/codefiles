#include <iostream>
#include <vector>
#include <queue>
#include <omp.h>

using namespace std;

//g++ prac1.cpp -o prac1 -fopenmp

class Graph {
    int V;
    vector<vector<int>> adjListArray;

public:
    Graph(int V) {
        this->V = V;
        adjListArray.resize(V);
    }

    void addEdge(int src, int dest) {
        adjListArray[src].push_back(dest);
        adjListArray[dest].push_back(src);
    }

    void BFS(int s) {
        vector<bool> visited(V, false);
        queue<int> queue;
        visited[s] = true;
        queue.push(s);

        while (!queue.empty()) {
            s = queue.front();
            queue.pop();
            cout << s << " ";

            #pragma omp parallel for
            for (auto u : adjListArray[s]) {
                if (!visited[u]) {
                    visited[u] = true;
                    queue.push(u);
                }
            }
        }
    }

    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (auto u : adjListArray[v]) {
            if (!visited[u]) {
                DFSUtil(u, visited);
            }
        }
    }

    void DFS(int v) {
        vector<bool> visited(V, false);
        DFSUtil(v, visited);
    }
};

int main() {
    int V = 5;
    Graph graph(V);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);

    cout << "BFS:" << endl;
    graph.BFS(0);

    cout << "\nDFS:" << endl;
    graph.DFS(0);

    return 0;
}
