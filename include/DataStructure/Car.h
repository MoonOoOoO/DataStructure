#ifndef DATASTRUCTURE_CAR_H_H
#define DATASTRUCTURE_CAR_H_H

#include <iostream>
#include <ctime>
#include <vector>

using namespace std;

typedef struct {
    string number;
    //车牌号
    time_t a_time;
    //汽车进场时间
} car;

#endif //DATASTRUCTURE_CAR_H_H
