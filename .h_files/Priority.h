#ifndef PRIORITY_H
#define PRIORITY_H
#include "Sched.h"

class Priority :public Sched
{
    public:
        Priority(vector<float>,vector<float>,vector<int>,string);
        vector<Process>simulate();
        float AverageWaitingTime();
        virtual ~Priority();
        vector<Process>simulate_nonpreemptive();
        vector<Process>simulate_preemptive();
    protected:

    private:
    vector<int>Priorities;
    string subop;
};

#endif // PRIORITY_H
