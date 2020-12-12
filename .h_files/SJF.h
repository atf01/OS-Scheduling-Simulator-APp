#ifndef SJF_H
#define SJF_H

#include "Sched.h"
#include "heap.h"
using std::vector;

class SJF :public Sched

{
public:
    SJF(vector<float>AT,vector<float>BT,string subop);
    float AverageWaitingTime();
    virtual ~SJF();
    vector<Process>simulate();
protected:

private:
    vector<Process>simulate_nonpreemptive();
    vector<Process> simulate_preemptive();
    string subop;
};

#endif
