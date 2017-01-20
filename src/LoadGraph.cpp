#include <fstream>
#include <sstream>
#include "../include/LoadGraph.h"

void CreateGraph(ALGraph &G) {//创建图的邻接表存储
    int i = 0, j = 0;
    string temp;
    ifstream spotIn, spotMsg;
    spotIn.open("spot.txt");
    if (!spotIn) {
        cout << "打开文件出错" << endl;
        return;
    }
    while (!spotIn.eof()) {
        getline(spotIn, temp);
        istringstream in(temp);
        in >> G.adjList[i].name >> G.adjList[i].popularity >> G.adjList[i].info;
        G.adjList[i].firstNode = NULL;
        ++i;
    }
    G.vexNum = i;

    string node1, node2;
    double w;
    int m, n;
    spotMsg.open("spotMsg.txt");
    if (!spotMsg) {
        cout << "打开文件出错" << endl;
        return;
    }
    i = 0;
    while (!spotMsg.eof()) {
        spotMsg >> node1 >> node2 >> w;
        m = LocateVex(G, node1);
        n = LocateVex(G, node2);

        ArcNode *p1 = (ArcNode *) malloc(sizeof(ArcNode));
        ArcNode *p2 = (ArcNode *) malloc(sizeof(ArcNode));
        p1->index = m;
        p1->weight = w;
        p1->next = G.adjList[n].firstNode;
        G.adjList[n].firstNode = p1;

        p2->index = n;
        p2->weight = w;
        p2->next = G.adjList[m].firstNode;
        G.adjList[m].firstNode = p2;
        i++;
    }
    G.edgeNum = i;

    //邻接矩阵存储用于显示
    ArcNode *node;
    for (i = 0; i < MAX_VERTEX_NUM; ++i) {
        for (j = 0; j < MAX_VERTEX_NUM; ++j) {
            G.weight[i][j] = INF;
        }
    }
    i = 0;
    while (G.adjList[i].name != "") {
        G.weight[i][i] = 0;
        node = G.adjList[i].firstNode;
        do {
            G.weight[i][node->index] = node->weight;
            node = node->next;
        } while (node != NULL);
        ++i;
    }

    cout << "创建成功!" << endl;
    cout << endl;
    spotIn.close();
}

int LocateVex(ALGraph &G, string v) {
    for (int i = 0; i < G.vexNum; ++i) {
        if (v == G.adjList[i].name)
            return i;
    }
    return -1;
}