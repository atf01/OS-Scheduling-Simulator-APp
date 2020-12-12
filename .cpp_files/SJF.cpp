#include "SJF.h"
SJF::SJF(vector<float> AT,vector<float> BT,string subp):Sched(AT,BT)
{
    SJF::subop=subp;
}
struct Tpair
{
    float arrival,burst;
};

bool compr(Tpair a,Tpair b)
{
    return a.arrival<=b.arrival;
}
bool comr(pair<int,float>a,pair<int,float>b)
{
    return a.second<=b.second;
}
vector<Process> SJF::simulate_preemptive()
{
    vector<Tpair>process(ArrivalTime.size());
    for(int i=0; i<BurstTime.size(); i++)
        process[i].arrival=ArrivalTime[i],process[i].burst=BurstTime[i];
    sort(process.begin(),process.end(),compr);
        vector<float>ART(process.size());
        for(int i=0;i<ART.size();i++)ART[i]=process[i].burst;
    heap hp;
    float timer=process[0].arrival;
    pair<int,float>f;
    f.first=0;
    f.second=process[0].burst;
     hp.Insert(f);
    Process faf;
    if(process[0].arrival>0)
    {
        faf.start=0;
        faf.index=-1;
        faf.finish=process[0].arrival;
        sim.push_back(faf);
    }
      for(int i=1; i<process.size(); i++)
    {
//timer=process[i-1].arrival;
        Process sd;
     while(timer<process[i].arrival&&ART[hp.top().first]>0)
        {
            sd.start=timer;
            sd.index=hp.top().first;
            sd.finish=min(hp.top().second+timer,process[i].arrival);
            sim.push_back(sd);
            float temp=hp.top().second;
            ART[hp.top().first]=ART[hp.top().first]-min(ART[hp.top().first],process[i].arrival-timer);
            timer+=min(temp,process[i].arrival-timer);
            if(ART[hp.top().first]<=0)
            {
                hp.deleteTop();
            }
        }
        if(timer<process[i].arrival)
        {
            Process sd;
            sd.start=timer;
            sd.index=-1;
            sd.finish=process[i].arrival;
            sim.push_back(sd);
            timer=process[i].arrival;
        }
        pair<int,float>fs;
        fs.first=i;
        fs.second=process[i].burst;
        hp.Insert(fs);
    }
    while(!hp.isEmpty())
    {
        pair<int,float>fd=hp.top();
        Process sd;
        sd.start=timer;
        sd.finish=timer+hp.top().second;
        sd.index=hp.top().first;
        sim.push_back(sd);
        timer+=ART[hp.top().first];
        hp.deleteTop();
    }
    vector<Process>rsim;
    rsim.push_back(sim[0]);
    for(int i=1; i<sim.size(); i++)
    {
        if(rsim[rsim.size()-1].index!=sim[i].index&&rsim[rsim.size()-1].finish<sim[i].start)
        {
            Process sd;
            sd.start=rsim[rsim.size()-1].finish;
            sd.finish=sim[i].start;
            sd.index=-1;
            rsim.push_back(sd);
        }
        if(rsim[rsim.size()-1].index==sim[i].index)
            rsim[rsim.size()-1].finish=sim[i].finish;
        else
            rsim.push_back(sim[i]);
    }
    return rsim;
}
float SJF::AverageWaitingTime()
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
vector<Process>SJF::simulate_nonpreemptive()
{
    vector< pair<int,float> >proc;
    vector<Tpair>process(ArrivalTime.size());
    for(int i=0; i<process.size(); i++)
    {
        process[i].arrival=ArrivalTime[i],process[i].burst=BurstTime[i];
    }

    sort(process.begin(),process.end(),compr);
    for(int i=0; i<process.size(); i++)
    {
        pair<int,float>f;
        f.first=i;
        f.second=process[i].burst;
        proc.push_back(f);
    }
    sort(proc.begin(),proc.end(),comr);

    float timer=0;
    for(int i=0; i<proc.size(); i++)
    {
        Process sd;
        sd.start=timer;
        timer+=proc[i].second;
        sd.finish=timer;
        sd.index=proc[i].first;
        sim.push_back(sd);
    }
    return sim;
}
vector <Process> SJF::simulate()
{
    return SJF::subop=="preemptive"?SJF::simulate_preemptive():SJF::simulate_nonpreemptive();
}
SJF::~SJF()
{
    //dtor
}
