#ifndef DATASTRUCTURE_PARKING_H
#define DATASTRUCTURE_PARKING_H

#include "DataStructure/Stack.h"
#include "DataStructure/Queue.h"
#include "DataStructure/Car.h"

#define MAXIMUM 5

string getTime(time_t t);

vector<std::string> split(string str, string pattern);

void enterParking(Stack<car> &parking);

void quitParking(Stack<car> &parking, string quitCar);

void showParking(Stack<car> &parking);

void showRecord();

#endif //DATASTRUCTURE_PARKING_H
