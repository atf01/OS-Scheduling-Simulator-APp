#ifndef DATAADAPTER_H
#define DATAADAPTER_H
#include<vector>
#include<QRect>
#include<QString>
#include "ui_mainwindow.h"
#include "Sched.h"
#include "output.h"
#include "firstInFirstOut.h"
#include "RR.h"
#include "SJF.h"
#include "Priority.h"
#include<QMessageBox>
#include<QMainWindow>
using namespace  std;
class DataAdapter
{
private:
    vector<float>ArrivalTime;
    vector<float>BurstTime;
    string op1,op2;
    QString a,b,c,timeunit;
    int n;
    float qtime=0;
    vector<int>priorities;
public:
    DataAdapter(QString a,QString b,QString c,string d,string e,int n,float q, QString s);
    void formalize();
    bool checkError();
    bool checkInputError();
    vector<float>SetVec(QString);
    vector<int>SetVector(QString);
    vector<float>getArrivalTime();
    vector<float>getBurstTime();
    void simulation();
    float getQuantumTime();
    vector<int>getPriority();
};

#endif // DATAADAPTER_H
