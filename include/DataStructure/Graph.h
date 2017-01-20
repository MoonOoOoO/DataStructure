
#ifndef DATASTRUCTURE_GRAPH_H
#define DATASTRUCTURE_GRAPH_H

#include <iostream>
#include <stdlib.h>

#define MAX_VERTEX_NUM 20
#define INF 32767

using namespace std;

typedef struct ArcNode {
    int index;
    //该边所达顶点的下标
    struct ArcNode *next;
    //指向下一条边的指针
    double weight;
    //权值
} ArcNode;//定义边信息

typedef struct VNode {
    string name;
    //景点名称
    int popularity;
    //景点欢迎度
    string info;
    //景点简介信息
    ArcNode *firstNode;
    //指向顶点连接的边
} VNode;//定义顶点信息

typedef VNode AdjList[MAX_VERTEX_NUM];
//定义邻接链表
typedef struct {
    AdjList adjList;
    //邻接链表保存顶点之间可达信息
    int vexNum;
    //图的顶点数
    int edgeNum;
    //图的边数
    double weight[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
} ALGraph;//定义图的信息

#endif //DATASTRUCTURE_GRAPH_H
