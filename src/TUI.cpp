#include <cstdio>
#include "../include/TUI.h"

bool flag = 0;

void menu(ALGraph G, int path[][MAX_VERTEX_NUM], double D[][MAX_VERTEX_NUM], Stack<car> parking) {
    string choice;
    string start, end;
    do {
        cout << "===========================================" << endl;
        cout << "          ��ӭʹ�þ�����Ϣ����ϵͳ" << endl;
        cout << "             *** ��ѡ��˵� ***" << endl;
        cout << "===========================================" << endl;
        cout << "      1��������������ֲ�ͼ" << endl << endl;
        cout << "      2�������������ֲ�ͼ" << endl << endl;
        cout << "      3���������·��ͼ" << endl << endl;
        cout << "      4�����������������·������̾���" << endl << endl;
        cout << "      5�������·�޽��滮ͼ" << endl << endl;
        cout << "      6���ؼ�������������Ϣ" << endl << endl;
        cout << "      7�������㻶ӭ������" << endl << endl;
        cout << "      8���������·������" << endl << endl;
        cout << "      9��ͣ��������������¼��Ϣ" << endl << endl;
        cout << "      0���˳�ϵͳ" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "��ѡ��: ";
        cin.clear();
        cin >> choice;
        if (choice == "1") {
            cout << endl;
            if (!flag) {
                cout << "�����ֲ�ͼ..." << endl;
                CreateGraph(G);
                flag = 1;
            } else {
                cout << "�Ѵ����ֲ�ͼ" << endl;
                cout << endl;
            }
            pressAnyKey();
        } else if (choice == "2") {
            cout << endl;
            loadAuto(G);
            OutputGraph(G);
            pressAnyKey();
        } else if (choice == "3") {
            cout << endl;
            loadAuto(G);
            CreateTourGraph(G);
            pressAnyKey();
        } else if (choice == "6") {
            cout << endl;
            loadAuto(G);
            search(G);
            pressAnyKey();
        } else if (choice == "4") {
            cout << endl;
            loadAuto(G);
            ShortestPath(G, path, D);
            do {
                cin.clear();
                cout << "���������: ";
                cin >> start;
                cout << "�������յ�: ";
                cin >> end;
                if (LocateVex(G, start) == -1 || LocateVex(G, end) == -1) {
                    cout << "���붥����Ϣ��������������" << endl;
                    cout << endl;
                }
            } while (LocateVex(G, start) == -1 || LocateVex(G, end) == -1);

            if (LocateVex(G, start) == LocateVex(G, end)) {
                cout << "�������ͬһ�ص�" << endl;
                cout << endl;
            } else {
                OutputPath(G, path, D, LocateVex(G, start), LocateVex(G, end));
            }
            pressAnyKey();
        } else if (choice == "5") {
            cout << endl;
            loadAuto(G);
            miniSpanTree(G);
            pressAnyKey();
        } else if (choice == "7") {
            cout << endl;
            loadAuto(G);
            sortByPopularity(G);
            pressAnyKey();
        } else if (choice == "8") {
            cout << endl;
            loadAuto(G);
            sortByCrossing(G);
            pressAnyKey();
        } else if (choice == "9") {
            cout << endl;
            parkingMenu(G, path, D, parking);
        } else if (choice == "0") {
            cout << "�˳�ϵͳ��ллʹ��" << endl;
            exit(0);
        } else if (choice != "1" || choice != "2" || choice != "3" || choice != "4" || choice != "5" || choice != "6" ||
                   choice != "7" || choice != "8" || choice != "9" || choice != "0") {
            cout << endl;
            cout << "�����������������" << endl;
            cout << endl;
            pressAnyKey();
        }
    } while (choice != "1" || choice != "2" || choice != "3" || choice != "4" || choice != "5" || choice != "6" ||
             choice != "7" || choice != "8" || choice != "9" || choice != "0");
}

void parkingMenu(ALGraph G, int path[][MAX_VERTEX_NUM], double D[][MAX_VERTEX_NUM], Stack<car> parking) {
    string choice;
    string quitCar;
    do {
        system("cls");
        cout << endl;
        cout << "==============================" << endl;
        cout << "         ͣ�����������" << endl;
        cout << "        ***��ѡ��˵�***" << endl;
        cout << "==============================" << endl;
        cout << "       1����������ͣ����" << endl << endl;
        cout << "       2�������˳�ͣ����" << endl << endl;
        cout << "       3���鿴ͣ��������Ϣ" << endl << endl;
        cout << "       4���鿴ͣ�����շѼ�¼" << endl << endl;
        cout << "       0���������˵�" << endl;
        cout << "------------------------------" << endl;
        cout << "��ѡ��: ";
        cin.clear();
        cin.sync();
        cin >> choice;
        if (choice == "1") {
            cout << endl;
            enterParking(parking);
            pressAnyKey();
        } else if (choice == "2") {
            cout << endl;
            cin.clear();
            cout << "�����복�ƺ�: ";
            cin >> quitCar;
            cout << endl;
            quitParking(parking, quitCar);
            pressAnyKey();
        } else if (choice == "3") {
            cout << endl;
            showParking(parking);
            pressAnyKey();
        } else if (choice == "4") {
            cout << endl;
            showRecord();
            pressAnyKey();
        } else if (choice == "0") {
            system("cls");
            menu(G, path, D, parking);
        } else if (choice != "1" || choice != "2" || choice != "3" || choice != "4" || choice != "0") {
            cout << endl;
            cout << "�����������������" << endl;
            cout << endl;
            pressAnyKey();
        }
    } while (choice != "1" || choice != "2" || choice != "3" || choice != "4" || choice != "0");
}

void loadAuto(ALGraph &G) {
    if (!flag) {
        cout << "�Զ������ֲ�ͼ..." << endl;
        CreateGraph(G);
        flag = 1;
    }
}

void pressAnyKey() {
    cout << "�밴���������...";
    cin.clear();
    cin.sync();
    getchar();
    cin.clear();
    cin.sync();
    system("cls");
}