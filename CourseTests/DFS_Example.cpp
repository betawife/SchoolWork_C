#include <iostream>
#include <vector>
using namespace std;

// 定义图的结构
class Graph {
    int V; // 顶点的数量
    vector<vector<int>> adj; // 邻接表
public:
    Graph(int V); // 构造函数
    void addEdge(int v, int w); // 添加边
    void DFS(int v); // 从顶点v开始进行DFS
    void DFSUtil(int v, vector<bool>& visited); // 辅助函数，用于递归调用
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); // 将w添加到v的列表中
}

void Graph::DFSUtil(int v, vector<bool>& visited) {
    // 标记当前节点为已访问
    visited[v] = true;
    cout << v << " ";

    // 递归访问所有未被访问的邻居
    for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
        if (!visited[*i]) {
            DFSUtil(*i, visited);
        }
    }
}

void Graph::DFS(int v) {
    // 初始化所有顶点为未访问状态
    vector<bool> visited(V, false);

    // 从顶点v开始DFS
    DFSUtil(v, visited);
}

int main() {
    // 创建一个图实例
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Depth First Traversal starting from vertex 2:" << endl;
    g.DFS(2);

    return 0;
}