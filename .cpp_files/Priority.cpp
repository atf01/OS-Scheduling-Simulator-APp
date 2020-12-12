#include "Priority.h"
struct Prior
{
    float arrival;
    float burst;
    int priority;
    int index;
};
bool comprar(Prior a, Prior b)
{
    return a.priority<=b.priority;
}
bool compar(Prior a,Prior b)
{
return a.arrival<=b.arrival;
}
Priority::Priority(vector<float>ArrivalTime,vector<float>BurstTime,vector<int>Prior,string Sub):Sched(ArrivalTime,BurstTime)
{
    Priority::Priorities=Prior;
    subop=Sub;
}
vector<Process> Priority::simulate()
{
 return Priority::subop=="preemptive"?simulate_preemptive():simulate_nonpreemptive();
}

vector<Process> Priority::simulate_preemptive()
{
    vector<Prior>process(Priorities.size());
    for(int i=0; i<Priorities.size(); i++)
    {
        process[i].arrival=ArrivalTime[i];
        process[i].burst=BurstTime[i];
        process[i].priority=Priorities[i];
    }
    sort(process.begin(),process.end(),compar);
    vector<float>ART(ArrivalTime.size());
    for(int i=0; i<ART.size(); i++)
        ART[i]=process[i].burst;
    heap hp;
    float timer=process[0].arrival;
    pair<int,float>f;
    f.first=0;
    f.second=process[0].priority;
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
        fs.second=process[i].priority;
        hp.Insert(fs);
    }
    while(!hp.isEmpty())
    {
        pair<int,float>fd=hp.top();
        Process sd;
        sd.start=timer;
        sd.finish=timer+ART[hp.top().first];
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
float Priority::AverageWaitingTime()
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
vector<Process>Priority::simulate_nonpreemptive()
{
    vector<Prior>process(ArrivalTime.size());
    for(int i=0; i<process.size(); i++)
    {
        process[i].arrival=ArrivalTime[i],process[i].burst=BurstTime[i];
        process[i].priority=Priorities[i];
    }
    vector<Prior>timen;
    sort(process.begin(),process.end(),compar);
        for(int i=0; i<process.size(); i++)
        {
        Prior number;
        number.index=i;
        number .priority=process[i].priority;
        number.burst=process[i].burst;
        timen.push_back(number);
        }
        sort(timen.begin(),timen.end(),comprar);

        float timer=0;
        for(int i=0; i<timen.size(); i++)
        {
            Process sd;
            sd.start=timer;
            timer+=timen[i].burst;
            sd.finish=timer;
            sd.index=timen[i].index;
            sim.push_back(sd);
        }
        return sim;

}

Priority::~Priority()
{
    //dtor
}
