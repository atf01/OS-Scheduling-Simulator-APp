#include "Sched.h"
#include <algorithm>
Sched::Sched(vector<float>AT,vector<float>BT)
{
    Sched::ArrivalTime=AT;
    Sched::BurstTime=BT;
}
Sched::~Sched()
{
    ArrivalTime.clear();
    BurstTime.clear();
    sim.clear();
}
vector<Process> Sched::simulate()
{
     vector<Process>dd;
    return dd;
}

float Sched::AverageWaitingTime()
{
vector<float>WaitingTime(Sched::ArrivalTime.size());
for(int i=0;i<WaitingTime.size();i++)
{
WaitingTime[i]=-1*Sched::BurstTime[i];
}
for(int i=0;i<Sched::sim.size();i++)
{
WaitingTime[Sched::sim[i].index]+=(Sched::sim[i].finish-Sched::sim[i].start);
}
float WaitingTotal=0;
for(int i=0;i<WaitingTime.size();i++)
{
WaitingTotal+=(WaitingTime[i]*1.0);
}
 return WaitingTotal/WaitingTime.size();
}


