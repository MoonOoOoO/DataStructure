#include "../include/MiniDistance.h"

bool s[MAX_VERTEX_NUM];//标志位

void Dijkstra(ALGraph G, int v, int path[][MAX_VERTEX_NUM], double D[][MAX_VERTEX_NUM]) {
    double minDis;
    int i, j, u;
    for (i = 0; i < G.vexNum; i++) {
        D[v][i] = G.weight[v][i]; //初始化距离
        s[i] = 0;
        if (G.weight[v][i] < INF)
            path[v][i] = v;
        else
            path[v][i] = -1;
    }
    s[v] = 1;
    path[v][v] = 0;
    for (i = 0; i < G.vexNum; i++) {//循环直到所有顶点的最短路径都求出
        minDis = INF;
        u = -1;
        for (j = 0; j < G.vexNum; j++) {//选取不在s中且具有最小距离的顶点u
            if (s[j] == 0 && D[v][j] < minDis) {
                u = j;
                minDis = D[v][j];
            }
        }
        if (u != -1) {//找到最小距离的顶点u,顶点u加入s中
            s[u] = 1;
            for (j = 0; j < G.vexNum; j++) {//修改不在s中的顶点距离
                if (s[j] == 0) {
                    if (G.weight[u][j] < INF && D[v][u] + G.weight[u][j] < D[v][j]) {
                        D[v][j] = D[v][u] + G.weight[u][j];//修改源点到vj的距离
                        path[v][j] = u;//保存当前最短路径中的前一个顶点编号
                    }
                }
            }
        }
    }
}

void ShortestPath(ALGraph G, int path[][MAX_VERTEX_NUM], double D[][MAX_VERTEX_NUM]) {
    int i;
    for (i = 0; i < G.vexNum; ++i) {
        Dijkstra(G, i, path, D);
    }
}

void OutputPath(ALGraph G, int path[][MAX_VERTEX_NUM], double D[][MAX_VERTEX_NUM], int start, int destination) {
    int m, n, pre;
    int tempPath[MAX_VERTEX_NUM];
    cout << endl;
    cout << G.adjList[start].name << "到" << G.adjList[destination].name;
    if (destination != start) {
        if (s[destination] == 1) {
            pre = destination;
            cout << "的最短路径是: ";
            m = 0;

            //倒序路径
            while (pre != start) {
                tempPath[m] = pre;
                m++;
                pre = path[start][pre];
            }

            //倒序输出
            tempPath[m] = pre;
            m = 0;
            while (tempPath[m] != start) {
                m++;
            }
            for (n = m; n >= 0; --n) {
                if (n != 0)
                    cout << G.adjList[tempPath[n]].name << "->";
                if (n == 0)
                    cout << G.adjList[tempPath[n]].name << endl;
            }
            cout << "最短路径长度为: " << D[start][destination] << "\t";
            cout << endl;
        } else {
            cout << "不存在路径" << endl;
        }
    } else {
        cout << "不存在路径" << endl;
    }
    cout << endl;
}