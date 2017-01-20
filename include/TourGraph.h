
#ifndef DATASTRUCTURE_CREATTOURGRAPH_H
#define DATASTRUCTURE_CREATTOURGRAPH_H

#include "DataStructure/Graph.h"

bool isAllVisited(ALGraph G, bool visited[]);

//寻找要查找顶点位置
void DFSCore(ALGraph G, string v);

//图的深度遍历
void CreateTourGraph(ALGraph G);


#endif //DATASTRUCTURE_CREATTOURGRAPH_H
