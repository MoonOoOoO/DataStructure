#include "../include/MiniSpanTree.h"

int graph[MAX_VERTEX_NUM][MAX_VERTEX_NUM];

void miniSpanTree(ALGraph G) {
    int lowCost[MAX_VERTEX_NUM];
    int mst[MAX_VERTEX_NUM];
    int i, j, min, minId;
    for (i = 0; i < G.vexNum; i++) {
        for (j = 0; j < G.vexNum; j++) {
            graph[i + 1][j + 1] = (int) G.weight[i][j];
        }
    }
    for (i = 2; i <= G.vexNum; i++) {
        lowCost[i] = graph[1][i];
        mst[i] = 1;
    }
    mst[1] = 0;
    for (i = 2; i <= G.vexNum; i++) {
        min = INF;
        minId = 0;
        for (j = 2; j <= G.vexNum; j++) {
            if (lowCost[j] < min && lowCost[j] != 0) {
                min = lowCost[j];
                minId = j;
            }
        }
        cout << " 从 " << G.adjList[mst[minId] - 1].name << " -> " << G.adjList[minId - 1].name << " 修一条路" << endl;
        lowCost[minId] = 0;
        for (j = 2; j <= G.vexNum; j++) {
            if (graph[minId][j] < lowCost[j]) {
                lowCost[j] = graph[minId][j];
                mst[j] = minId;
            }
        }
    }
    cout << endl;
}