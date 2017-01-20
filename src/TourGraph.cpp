#include "../include/TourGraph.h"
#include "../include/LoadGraph.h"

bool visited[MAX_VERTEX_NUM];

bool isAllVisited(ALGraph G, bool visited[]) { //判断所有顶点是否被访问过
    int i = 0;
    while (i < G.vexNum) {
        if (!visited[i])
            return false;
        else
            i++;
    }
    return true;
}

void DFSCore(ALGraph G, string v) { //寻找要查找顶点位置
    ArcNode *temp = nullptr;
    int i;
    cout << v << "->";
    for (i = 0; i < G.vexNum; ++i) {
        if (v == G.adjList[i].name) {
            visited[i] = true;
            temp = G.adjList[i].firstNode;
        }
    }
    while (temp) {
        if (!visited[temp->index]) {
            DFSCore(G, G.adjList[temp->index].name);
            if (isAllVisited(G, visited)) {
                return;
            }
            cout << v << "->";
        }
        temp = temp->next;
    }
}

void CreateTourGraph(ALGraph G) { //图的深度遍历
    int i;
    for (i = 0; i < MAX_VERTEX_NUM; ++i) {
        visited[i] = false;
    }
    string v = "";
    cout << "请输入起点: ";
    cin >> v;
    cout << endl;
    if (LocateVex(G, v) == -1) {
        cout << "无输入的景点" << endl;
    } else {
        for (i = LocateVex(G, v); i < G.vexNum; ++i) {
            if (!visited[i]) {
                DFSCore(G, G.adjList[i].name);
            }
        }
        cout << "结束";
    }
    cout << endl;
    cout << endl;
}

