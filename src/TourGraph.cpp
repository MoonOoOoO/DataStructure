#include "../include/TourGraph.h"
#include "../include/LoadGraph.h"

bool visited[MAX_VERTEX_NUM];

bool isAllVisited(ALGraph G, bool visited[]) { //�ж����ж����Ƿ񱻷��ʹ�
    int i = 0;
    while (i < G.vexNum) {
        if (!visited[i])
            return false;
        else
            i++;
    }
    return true;
}

void DFSCore(ALGraph G, string v) { //Ѱ��Ҫ���Ҷ���λ��
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

void CreateTourGraph(ALGraph G) { //ͼ����ȱ���
    int i;
    for (i = 0; i < MAX_VERTEX_NUM; ++i) {
        visited[i] = false;
    }
    string v = "";
    cout << "���������: ";
    cin >> v;
    cout << endl;
    if (LocateVex(G, v) == -1) {
        cout << "������ľ���" << endl;
    } else {
        for (i = LocateVex(G, v); i < G.vexNum; ++i) {
            if (!visited[i]) {
                DFSCore(G, G.adjList[i].name);
            }
        }
        cout << "����";
    }
    cout << endl;
    cout << endl;
}

