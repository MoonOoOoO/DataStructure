#ifndef DATASTRUCTURE_SORT_H
#define DATASTRUCTURE_SORT_H

#include "DataStructure/Graph.h"

void swap(int array[][MAX_VERTEX_NUM], int i, int j);

int partition(int array[][MAX_VERTEX_NUM], int l, int r);

void quickSort(int array[][MAX_VERTEX_NUM], int p, int r);

void sortByPopularity(ALGraph G);

void sortByCrossing(ALGraph G);

#endif //DATASTRUCTURE_SORT_H
