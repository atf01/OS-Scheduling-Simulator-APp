#ifndef SCHED_H
#define SCHED_H

#include<vector>
#include<iostream>
#include<algorithm>
#include<cmath>
#include "heap.h"
using namespace std;
struct Process
{
    float start,finish;
    int index;
};
class Sched
{
public:
    Sched(vector<float>AT,vector<float>BT);
    virtual ~Sched();

    virtual  vector<Process>simulate()=0;
    virtual  float AverageWaitingTime()=0;
    //vector<Process> getSim();
protected:
    vector<float>ArrivalTime;
    vector<float>BurstTime;
    vector<Process>sim;
};
#endif
