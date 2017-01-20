#include "../include/OutputGraph.h"

void OutputGraph(ALGraph &G) {//输出图的邻接表
    int i = 0, j = 0;
    cout << "\t";
    while (G.adjList[i].name != "") {
        cout << G.adjList[i].name << "\t";
        ++i;
    }
    i = 0, j = 0;
    cout << endl;
    while (G.adjList[i].name != "") {
        if (j == 0)
            cout << G.adjList[i].name << "\t";
        cout << G.weight[i][j] << "\t";
        ++j;
        if (G.adjList[j].name == "") {
            cout << endl;
            j = 0;
            ++i;
        }
    }
    cout << endl;
}