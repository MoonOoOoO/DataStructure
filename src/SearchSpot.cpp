#include "../include/SearchSpot.h"

void search(ALGraph G) {
    string keyword;
    int index, amount = 0;
    bool flag = 0;
    cout << "��������������: ";
    cin >> keyword;
    cout << "------------------------------" << endl;
    index = LocateVex(G, keyword);
    if (index != -1) {
        flag = 1;
        cout << "��������: " << G.adjList[index].name << endl;
        cout << "�����ȶ�: " << G.adjList[index].popularity << endl;
        cout << "������: " << G.adjList[index].info << endl;
        cout << "------------------------------" << endl;
        cout << "���ҵ�" << ++amount << "����ؾ���" << endl;
        cout << endl;
    } else {
        for (int i = 0; i < G.vexNum; ++i) {
            if (G.adjList[i].info.find(keyword) != string::npos) {
                flag = 1;
                amount++;
                cout << "��������: " << G.adjList[i].name << endl;
                cout << "�����ȶ�: " << G.adjList[i].popularity << endl;
                cout << "������: " << G.adjList[i].info << endl;
                cout << "------------------------------" << endl;
            }
        }
        if (amount != 0) {
            cout << "���ҵ�" << amount << "����ؾ���" << endl;
            cout << endl;
        }
    }
    if (!flag) {
        cout << "��Ǹ��δ�ҵ���ؾ�����Ϣ" << endl;
        cout << endl;
    }
}