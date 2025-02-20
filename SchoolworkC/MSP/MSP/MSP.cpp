#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100  // 最大顶点数
#define INF 1000000000  // 表示无穷大的权值

typedef struct {
    int u, v;      // 边的两个顶点
    int weight;    // 边的权值（高铁长度或造价）
} Edge;

typedef struct {
    int vertexNum;  // 顶点数
    int edgeNum;    // 边数
    Edge edges[MAX];  // 存储边的信息
    char cityNames[MAX][50];  // 城市名称
} Graph;

int parent[MAX];  // 并查集数组

// 并查集初始化
void initUnionFind(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

// 并查集查找
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// 并查集合并
void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
        parent[rootX] = rootY;
    }
}

// 比较函数，用于边权值的升序排序
int compareEdges(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    return edgeA->weight - edgeB->weight;
}

// Kruskal算法求最小生成树
void kruskal(Graph* g) {
    int totalWeight = 0;  // 最小生成树总权值
    int edgeCount = 0;  // 已加入生成树的边数

    // 初始化并查集
    initUnionFind(g->vertexNum);

    // 按权值升序排序边
    qsort(g->edges, g->edgeNum, sizeof(Edge), compareEdges);

    printf("最小生成树的边如下：\n");
    for (int i = 0; i < g->edgeNum; i++) {
        Edge e = g->edges[i];
        if (find(e.u) != find(e.v)) {
            unionSets(e.u, e.v);
            printf("<%s, %s, 造价: %d亿元>\n", g->cityNames[e.u], g->cityNames[e.v], e.weight);
            totalWeight += e.weight;
            edgeCount++;
            if (edgeCount == g->vertexNum - 1) {
                break;
            }
        }
    }

    printf("最小生成树的总造价为：%d亿元\n", totalWeight);
}

// 从文件读取图数据
void readGraphFromFile(Graph* g, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("无法打开文件");
        exit(EXIT_FAILURE);
    }

    fscanf(file, "%d %d", &g->vertexNum, &g->edgeNum);

    // 读取城市名称
    for (int i = 0; i < g->vertexNum; i++) {
        fscanf(file, "%s", g->cityNames[i]);
    }

    // 读取边信息
    for (int i = 0; i < g->edgeNum; i++) {
        char city1[50], city2[50];
        int weight;
        fscanf(file, "%s %s %d", city1, city2, &weight);

        // 查找城市对应的编号
        int u = -1, v = -1;
        for (int j = 0; j < g->vertexNum; j++) {
            if (strcmp(city1, g->cityNames[j]) == 0) {
                u = j;
            }
            if (strcmp(city2, g->cityNames[j]) == 0) {
                v = j;
            }
        }

        if (u != -1 && v != -1) {
            g->edges[i].u = u;
            g->edges[i].v = v;
            g->edges[i].weight = weight;
        }
        else {
            fprintf(stderr, "城市名称错误：%s 或 %s\n", city1, city2);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
}

// 主函数
int main() {
    Graph g;

    char filename[100];
    printf("请输入数据文件名：\n");
    scanf("%s", filename);

    // 从文件读取图数据
    readGraphFromFile(&g, "C:/data/graph.txt");


    // 执行Kruskal算法
    kruskal(&g);

    return 0;
}
