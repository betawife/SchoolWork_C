#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

class Graph {
private:
    int numVertices;
    vector<list<int>> adjList;

public:
    Graph(int vertices) : numVertices(vertices), adjList(vertices) {}

    void addEdge(int src, int dest) {
        adjList[src].push_back(dest);
    }

    void removeEdge(int src, int dest) {
        adjList[src].remove(dest);
    }

    // DFS Recursive
    void DFSUtil(int v, vector<bool>& visited) {
        visited[v] = true;
        cout << v << " ";

        for (auto i = adjList[v].begin(); i != adjList[v].end(); ++i) {
            if (!visited[*i]) {
                DFSUtil(*i, visited);
            }
        }
    }

    void DFS(int startVertex) {
        vector<bool> visited(numVertices, false);
        DFSUtil(startVertex, visited);
    }

    // DFS Non-Recursive
    void DFSNonRecursive(int startVertex) {
        vector<bool> visited(numVertices, false);
        stack<int> stack;
        stack.push(startVertex);

        while (!stack.empty()) {
            int v = stack.top();
            stack.pop();

            if (!visited[v]) {
                cout << v << " ";
                visited[v] = true;
            }

            for (auto i = adjList[v].rbegin(); i != adjList[v].rend(); ++i) {
                if (!visited[*i]) {
                    stack.push(*i);
                }
            }
        }
    }

    // BFS Recursive (Using a helper function to handle recursion)
    void BFSUtil(int v, vector<bool>& visited, queue<int>& q) {
        visited[v] = true;
        cout << v << " ";
        q.push(v);

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (auto i = adjList[current].begin(); i != adjList[current].end(); ++i) {
                if (!visited[*i]) {
                    visited[*i] = true;
                    cout << *i << " ";
                    q.push(*i);
                }
            }
        }
    }

    void BFS(int startVertex) {
        vector<bool> visited(numVertices, false);
        queue<int> q;
        BFSUtil(startVertex, visited, q);
    }

    // BFS Non-Recursive
    void BFSNonRecursive(int startVertex) {
        vector<bool> visited(numVertices, false);
        queue<int> q;
        visited[startVertex] = true;
        q.push(startVertex);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for (auto i = adjList[v].begin(); i != adjList[v].end(); ++i) {
                if (!visited[*i]) {
                    visited[*i] = true;
                    q.push(*i);
                }
            }
        }
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(0, 5);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 5);
    g.addEdge(3, 2);
    g.addEdge(3, 5);
    g.addEdge(5, 4);
    g.addEdge(4, 3);

    cout << "DFS Recursive: ";
    g.DFS(0);
    cout << "\n";

    cout << "DFS Non-Recursive: ";
    g.DFSNonRecursive(0);
    cout << "\n";

    cout << "BFS: ";
    g.BFS(0);
    cout << "\n";

    cout << "BFS Non-Recursive: ";
    g.BFSNonRecursive(0);
    cout << "\n";

    return 0;
}