#include "RR.h"
struct Tpair
{
float arrival;
float burst;
};
bool com(Tpair a,Tpair b)
{
    return a.arrival<=b.arrival;
}
RR::RR(vector<float>AT,vector<float>BT,float QuantumTime):Sched(AT,BT)
{
    RR::QuantumTime=QuantumTime;
}
vector<Process> RR::simulate()
{
  vector<Tpair>process(ArrivalTime.size());
    for(int i=0; i<BurstTime.size(); i++)
    process[i].arrival=ArrivalTime[i],process[i].burst=BurstTime[i];
    sort(process.begin(),process.end(),com);
  Process dummy;
  if(process[0].arrival>0){dummy.start=0,dummy.finish=process[0].arrival;dummy.index=-1;sim.push_back(dummy);}
  float temp=QuantumTime;
  float timer=process[0].arrival;
 while(true)
  {
  bool terminate=true;
 for(int i=0;i<process.size();i++)
  {
  //cout<<process[i].burst<<" ";
  if(process[i].burst>0)
  {
   terminate=false;
   dummy.start=timer;
   dummy.index=i;
   timer+=min(temp,process[i].burst);
   dummy.finish=timer;
   process[i].burst-=min(temp,process[i].burst);
   temp-=min(temp,process[i].burst);
   sim.push_back(dummy);
     if(temp<process[i].burst)temp+=QuantumTime;
  }
  }
//temp=QuantumTime;
 if(terminate)return sim;
  }
  }
float RR::AverageWaitingTime()
{
 float result=0;
    vector<float>times(ArrivalTime.size());
    for(int i=0; i<times.size(); i++)
        times[i]=ArrivalTime[i];
    sort(times.begin(),times.end());
    for(int i=0; i<sim.size(); i++)
    {
        if(sim[i].index!=-1)
        {
            result+=max((float)0,sim[i].start-times[sim[i].index]);
            times[sim[i].index]=sim[i].finish;
        }
    }
    return result/times.size();

}
RR::~RR()
{
    //dtor
}
