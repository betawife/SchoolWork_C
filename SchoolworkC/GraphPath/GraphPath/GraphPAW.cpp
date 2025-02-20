#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int V; // 顶点数
    vector<vector<int>> adj; // 邻接表

public:
    // 构造函数
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    // 添加边
    void addEdge(int v, int w) {
        adj[v].push_back(w); // 将 w 添加到 v 的列表中
    }

    // 计算每个顶点的入度
    vector<int> inDegree() {
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (int j : adj[i]) {
                indegree[j]++;
            }
        }
        return indegree;
    }

    // 计算每个顶点的出度
    vector<int> outDegree() {
        vector<int> outdegree(V, 0);
        for (int i = 0; i < V; i++) {
            outdegree[i] = adj[i].size();
        }
        return outdegree;
    }

    // 计算出度为0的顶点数
    int countZeroOutDegree() {
        int count = 0;
        for (int i = 0; i < V; i++) {
            if (adj[i].empty()) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    Graph g(5); // 创建一个有5个顶点的图
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    vector<int> indegrees = g.inDegree();
    vector<int> outdegrees = g.outDegree();
    int zeroOutDegrees = g.countZeroOutDegree();

    cout << "\n每个点的入度依次为：";
    for (int d : indegrees) {
        cout << d << " ";
    }
    cout << "\n每个点的出度依次为： ";
    for (int d : outdegrees) {
        cout << d << " ";
    }
    cout << "\n出度为零的顶点数：" << zeroOutDegrees << endl;

    return 0;
}
