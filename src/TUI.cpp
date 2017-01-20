#include <cstdio>
#include "../include/TUI.h"

bool flag = 0;

void menu(ALGraph G, int path[][MAX_VERTEX_NUM], double D[][MAX_VERTEX_NUM], Stack<car> parking) {
    string choice;
    string start, end;
    do {
        cout << "===========================================" << endl;
        cout << "          欢迎使用景区信息管理系统" << endl;
        cout << "             *** 请选择菜单 ***" << endl;
        cout << "===========================================" << endl;
        cout << "      1、创建景区景点分布图" << endl << endl;
        cout << "      2、输出景区景点分布图" << endl << endl;
        cout << "      3、输出导游路线图" << endl << endl;
        cout << "      4、求两个景点间的最短路径和最短距离" << endl << endl;
        cout << "      5、输出道路修建规划图" << endl << endl;
        cout << "      6、关键字搜索景点信息" << endl << endl;
        cout << "      7、按景点欢迎度排序" << endl << endl;
        cout << "      8、按景点岔路数排序" << endl << endl;
        cout << "      9、停车场车辆进出记录信息" << endl << endl;
        cout << "      0、退出系统" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "请选择: ";
        cin.clear();
        cin >> choice;
        if (choice == "1") {
            cout << endl;
            if (!flag) {
                cout << "创建分布图..." << endl;
                CreateGraph(G);
                flag = 1;
            } else {
                cout << "已创建分布图" << endl;
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
                cout << "请输入起点: ";
                cin >> start;
                cout << "请输入终点: ";
                cin >> end;
                if (LocateVex(G, start) == -1 || LocateVex(G, end) == -1) {
                    cout << "输入顶点信息有误，请重新输入" << endl;
                    cout << endl;
                }
            } while (LocateVex(G, start) == -1 || LocateVex(G, end) == -1);

            if (LocateVex(G, start) == LocateVex(G, end)) {
                cout << "输入的是同一地点" << endl;
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
            cout << "退出系统，谢谢使用" << endl;
            exit(0);
        } else if (choice != "1" || choice != "2" || choice != "3" || choice != "4" || choice != "5" || choice != "6" ||
                   choice != "7" || choice != "8" || choice != "9" || choice != "0") {
            cout << endl;
            cout << "输入错误，请重新输入" << endl;
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
        cout << "         停车场管理程序" << endl;
        cout << "        ***请选择菜单***" << endl;
        cout << "==============================" << endl;
        cout << "       1、汽车进入停车场" << endl << endl;
        cout << "       2、汽车退出停车场" << endl << endl;
        cout << "       3、查看停留车辆信息" << endl << endl;
        cout << "       4、查看停车场收费记录" << endl << endl;
        cout << "       0、返回主菜单" << endl;
        cout << "------------------------------" << endl;
        cout << "请选择: ";
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
            cout << "请输入车牌号: ";
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
            cout << "输入错误，请重新输入" << endl;
            cout << endl;
            pressAnyKey();
        }
    } while (choice != "1" || choice != "2" || choice != "3" || choice != "4" || choice != "0");
}

void loadAuto(ALGraph &G) {
    if (!flag) {
        cout << "自动创建分布图..." << endl;
        CreateGraph(G);
        flag = 1;
    }
}

void pressAnyKey() {
    cout << "请按任意键继续...";
    cin.clear();
    cin.sync();
    getchar();
    cin.clear();
    cin.sync();
    system("cls");
}