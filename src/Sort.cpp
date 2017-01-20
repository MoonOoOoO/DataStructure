#include "../include/Sort.h"

void sortByPopularity(ALGraph G) {
    int i, sort[2][MAX_VERTEX_NUM];
    for (i = 0; i < MAX_VERTEX_NUM; ++i) {
        sort[0][i] = sort[1][i] = -1;
    }
    for (i = 0; i < G.vexNum; ++i) {
        sort[0][i] = i;
        sort[1][i] = G.adjList[i].popularity;
    }
    quickSort(sort, -1, G.vexNum - 1);//快速排序
    cout << "-------- 快速排序算法 --------" << endl;
    for (i = G.vexNum - 1; i >= 0; --i) {
        cout << "      " << G.adjList[sort[0][i]].name << "\t欢迎度: ";
        cout << sort[1][i] << endl;
    }
    cout << "------------------------------" << endl;
    cout << endl;
}

void sortByCrossing(ALGraph G) {
    int i, j, sort[2][MAX_VERTEX_NUM];
    int crossing = 0;
    for (i = 0; i < MAX_VERTEX_NUM; ++i) {
        sort[0][i] = sort[1][i] = -1;
    }
    for (i = 0; i < G.vexNum; ++i) {
        sort[0][i] = i;
        for (j = 0; j < G.vexNum; ++j) {
            if (G.weight[i][j] != INF && G.weight[i][j] != 0) {
                crossing++;
            }
        }
        sort[1][i] = crossing;
        crossing = 0;
    }
    //冒泡排序
    for (i = 0; i < G.vexNum; ++i) {
        for (j = i; j < G.vexNum; ++j) {
            if (sort[1][i] > sort[1][j]) {
                swap(sort, i, j);
            }
        }
    }
    cout << "-------- 冒泡排序算法 --------" << endl;
    for (i = G.vexNum - 1; i >= 0; --i) {
        cout << "      " << G.adjList[sort[0][i]].name << "\t岔路数: ";
        cout << sort[1][i] << endl;
    }
    cout << "------------------------------" << endl;
    cout << endl;
}

//交换两行
void swap(int array[][MAX_VERTEX_NUM], int i, int j) {
    int index, popularity;
    index = array[0][i];
    popularity = array[1][i];
    array[0][i] = array[0][j];
    array[1][i] = array[1][j];
    array[0][j] = index;
    array[1][j] = popularity;
}

int partition(int array[][MAX_VERTEX_NUM], int l, int r) {
    int i = l, j = r;    //初始化
    while (i < j) {
        while (i < j && array[1][i] < array[1][j])//右侧扫描
            j--;
        if (i < j) {
            swap(array, i, j);//将较小记录交换到前面
            i++;
        }
        while (i < j && array[1][i] < array[1][j])
            i++;//左侧扫描
        if (i < j) {
            swap(array, j, i);//将较大记录交换到后面
            j--;
        }
    }
    return i;   // i位轴值记录的最终位置
}

void quickSort(int array[][MAX_VERTEX_NUM], int p, int r) {
    if (p < r) {
        int q = partition(array, p, r);
        quickSort(array, p, q - 1);
        quickSort(array, q + 1, r);
    }
}