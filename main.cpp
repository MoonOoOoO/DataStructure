#include "include/TUI.h"

int main() {

    ALGraph G = ALGraph();//ͼ���ڽ�����
    Stack<car> parking(MAXIMUM);//ͣ����
    int path[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//�������·��
    double D[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//�������·������

    menu(G, path, D, parking);

    return 0;
}

