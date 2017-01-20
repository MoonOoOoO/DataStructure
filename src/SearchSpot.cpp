#include "../include/SearchSpot.h"

void search(ALGraph G) {
    string keyword;
    int index, amount = 0;
    bool flag = 0;
    cout << "请输入搜索内容: ";
    cin >> keyword;
    cout << "------------------------------" << endl;
    index = LocateVex(G, keyword);
    if (index != -1) {
        flag = 1;
        cout << "景点名称: " << G.adjList[index].name << endl;
        cout << "景点热度: " << G.adjList[index].popularity << endl;
        cout << "景点简介: " << G.adjList[index].info << endl;
        cout << "------------------------------" << endl;
        cout << "共找到" << ++amount << "条相关景点" << endl;
        cout << endl;
    } else {
        for (int i = 0; i < G.vexNum; ++i) {
            if (G.adjList[i].info.find(keyword) != string::npos) {
                flag = 1;
                amount++;
                cout << "景点名称: " << G.adjList[i].name << endl;
                cout << "景点热度: " << G.adjList[i].popularity << endl;
                cout << "景点简介: " << G.adjList[i].info << endl;
                cout << "------------------------------" << endl;
            }
        }
        if (amount != 0) {
            cout << "共找到" << amount << "条相关景点" << endl;
            cout << endl;
        }
    }
    if (!flag) {
        cout << "抱歉，未找到相关景点信息" << endl;
        cout << endl;
    }
}