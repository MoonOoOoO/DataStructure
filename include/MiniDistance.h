
#ifndef DATASTRUCTURE_MINIDISTANCE_H
#define DATASTRUCTURE_MINIDISTANCE_H

#include "DataStructure/Graph.h"

void Dijkstra(ALGraph G, int v, int path[][MAX_VERTEX_NUM], double D[][MAX_VERTEX_NUM]);

void ShortestPath(ALGraph G, int path[][MAX_VERTEX_NUM], double D[][MAX_VERTEX_NUM]);

void OutputPath(ALGraph G, int path[][MAX_VERTEX_NUM], double dist[][MAX_VERTEX_NUM], int start, int j);

#endif //DATASTRUCTURE_MINIDISTANCE_H
