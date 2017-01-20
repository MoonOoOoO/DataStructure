#include "include/TUI.h"

int main() {

    ALGraph G = ALGraph();//图的邻接链表
    Stack<car> parking(MAXIMUM);//停车场
    int path[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//保存最短路径
    double D[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//保存最短路径长度

    menu(G, path, D, parking);

    return 0;
}

