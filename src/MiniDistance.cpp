#include "../include/MiniDistance.h"

bool s[MAX_VERTEX_NUM];//��־λ

void Dijkstra(ALGraph G, int v, int path[][MAX_VERTEX_NUM], double D[][MAX_VERTEX_NUM]) {
    double minDis;
    int i, j, u;
    for (i = 0; i < G.vexNum; i++) {
        D[v][i] = G.weight[v][i]; //��ʼ������
        s[i] = 0;
        if (G.weight[v][i] < INF)
            path[v][i] = v;
        else
            path[v][i] = -1;
    }
    s[v] = 1;
    path[v][v] = 0;
    for (i = 0; i < G.vexNum; i++) {//ѭ��ֱ�����ж�������·�������
        minDis = INF;
        u = -1;
        for (j = 0; j < G.vexNum; j++) {//ѡȡ����s���Ҿ�����С����Ķ���u
            if (s[j] == 0 && D[v][j] < minDis) {
                u = j;
                minDis = D[v][j];
            }
        }
        if (u != -1) {//�ҵ���С����Ķ���u,����u����s��
            s[u] = 1;
            for (j = 0; j < G.vexNum; j++) {//�޸Ĳ���s�еĶ������
                if (s[j] == 0) {
                    if (G.weight[u][j] < INF && D[v][u] + G.weight[u][j] < D[v][j]) {
                        D[v][j] = D[v][u] + G.weight[u][j];//�޸�Դ�㵽vj�ľ���
                        path[v][j] = u;//���浱ǰ���·���е�ǰһ��������
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
    cout << G.adjList[start].name << "��" << G.adjList[destination].name;
    if (destination != start) {
        if (s[destination] == 1) {
            pre = destination;
            cout << "�����·����: ";
            m = 0;

            //����·��
            while (pre != start) {
                tempPath[m] = pre;
                m++;
                pre = path[start][pre];
            }

            //�������
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
            cout << "���·������Ϊ: " << D[start][destination] << "\t";
            cout << endl;
        } else {
            cout << "������·��" << endl;
        }
    } else {
        cout << "������·��" << endl;
    }
    cout << endl;
}