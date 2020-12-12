#ifndef FIRSTINFIRSTOUT_H
#define FIRSTINFIRSTOUT_H
#include "Sched.h"
class firstInFirstOut :public Sched
{
    public:
        firstInFirstOut(vector<float>AT,vector<float>BT);
        virtual ~firstInFirstOut();
          float AverageWaitingTime();
          vector<Process>simulate() ;
          vector<Process>getSim();
    private:
};

#endif // FIRSTINFIRSTOUT_H
