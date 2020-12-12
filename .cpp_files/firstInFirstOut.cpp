#include "firstInFirstOut.h"
#include "Sched.h"
#include<algorithm>
firstInFirstOut::firstInFirstOut(vector<float>AT,vector<float>BT):Sched(AT,BT)
{
    //ctor
}

firstInFirstOut::~firstInFirstOut()
{
    //dtor
}
struct Tpair
{
float Arrival,Burst;
};
bool compare(Tpair a,Tpair b){return a.Arrival<=b.Arrival;}
vector<Process> firstInFirstOut::simulate()
{
vector<Tpair>proc(ArrivalTime.size());
for(int i=0;i<ArrivalTime.size();i++)
{
proc[i].Arrival=ArrivalTime[i];
proc[i].Burst=BurstTime[i];
}
 sort(proc.begin(),proc.end(),compare);
 Process p;
 p.start=proc[0].Arrival;
 p.finish=proc[0].Arrival+proc[0].Burst;
 p.index=0;
 if(proc[0].Arrival!=0)
 {
 Process s;
 s.start=(float)0.0,s.index=-1,s.finish=proc[0].Arrival;
 sim.push_back(s);
 }
 sim.push_back(p);
for(int i=1;i<proc.size();i++)
{
if(p.finish<proc[i].Arrival)
{
Process s;
s.start=p.finish;
s.finish=p.start;
s.index=-1;
sim.push_back(s);
}
p.start=max(p.finish,proc[i].Arrival);
p.finish=p.start+proc[i].Burst;
p.index=i;
sim.push_back(p);
}
for(int i=0;i<sim.size();i++)
{
//cout<<sim[i].start<<" "<<sim[i].index<<" "<<sim[i].finish<<endl;
}
return sim;
}
float firstInFirstOut::AverageWaitingTime()
{
sort(ArrivalTime.begin(),ArrivalTime.end());
float result=0;
for(int i=0;i<sim.size();i++)
{
if(sim[i].index>-1)
{
result+=sim[i].start-ArrivalTime[sim[i].index];
}
}
return result/ArrivalTime.size();
}

