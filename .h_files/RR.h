#ifndef RR_H
#define RR_H
#include "Sched.h"


class RR :public Sched
{
public:
    RR(vector<float>AT,vector<float>BT,float Qt);
    virtual ~RR();
    vector<Process>simulate();
    float AverageWaitingTime();
protected:

private:
    float QuantumTime;
};

#endif // RR_H
