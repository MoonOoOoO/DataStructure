
#ifndef DATASTRUCTURE_GRAPH_H
#define DATASTRUCTURE_GRAPH_H

#include <iostream>
#include <stdlib.h>

#define MAX_VERTEX_NUM 20
#define INF 32767

using namespace std;

typedef struct ArcNode {
    int index;
    //�ñ����ﶥ����±�
    struct ArcNode *next;
    //ָ����һ���ߵ�ָ��
    double weight;
    //Ȩֵ
} ArcNode;//�������Ϣ

typedef struct VNode {
    string name;
    //��������
    int popularity;
    //���㻶ӭ��
    string info;
    //��������Ϣ
    ArcNode *firstNode;
    //ָ�򶥵����ӵı�
} VNode;//���嶥����Ϣ

typedef VNode AdjList[MAX_VERTEX_NUM];
//�����ڽ�����
typedef struct {
    AdjList adjList;
    //�ڽ������涥��֮��ɴ���Ϣ
    int vexNum;
    //ͼ�Ķ�����
    int edgeNum;
    //ͼ�ı���
    double weight[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
} ALGraph;//����ͼ����Ϣ

#endif //DATASTRUCTURE_GRAPH_H
