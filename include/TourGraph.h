
#ifndef DATASTRUCTURE_CREATTOURGRAPH_H
#define DATASTRUCTURE_CREATTOURGRAPH_H

#include "DataStructure/Graph.h"

bool isAllVisited(ALGraph G, bool visited[]);

//Ѱ��Ҫ���Ҷ���λ��
void DFSCore(ALGraph G, string v);

//ͼ����ȱ���
void CreateTourGraph(ALGraph G);


#endif //DATASTRUCTURE_CREATTOURGRAPH_H
