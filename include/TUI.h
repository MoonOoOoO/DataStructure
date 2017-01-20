#ifndef DATASTRUCTURE_UI_H
#define DATASTRUCTURE_UI_H

#include "DataStructure/Graph.h"
#include "LoadGraph.h"
#include "OutputGraph.h"
#include "TourGraph.h"
#include "MiniDistance.h"
#include "MiniSpanTree.h"
#include "SearchSpot.h"
#include "Sort.h"
#include "Parking.h"

void menu(ALGraph G, int path[][MAX_VERTEX_NUM], double D[][MAX_VERTEX_NUM], Stack<car> parking);

void parkingMenu(ALGraph G, int path[][MAX_VERTEX_NUM], double D[][MAX_VERTEX_NUM], Stack<car> parking);

void loadAuto(ALGraph &G);

void pressAnyKey();

#endif //DATASTRUCTURE_UI_H
