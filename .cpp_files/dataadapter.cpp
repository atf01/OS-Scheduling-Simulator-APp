#include "dataadapter.h"
#include<QWindow>
#include<QMessageBox>
#include "QtDebug"
#include<QRect>

DataAdapter::DataAdapter(QString a,QString b,QString c,string d,string e,int n,float q, QString s)
{
  this->a=a;
  this->b=b;
  this->n=n;
  this->qtime=q;
  this->op1=d;
  this->op2=e;
  this->c=c;
  this->timeunit=s;

if(DataAdapter::checkError())
{
  formalize();
}

}
bool DataAdapter::checkError()
{
    if(a.size()==0||b.size()==0)return false;
    if(DataAdapter::op1=="PR"&&c.size()==0)return false;

    if(DataAdapter::op1=="RR")
        if(qtime==0)
    {

        return false;
    }
    for(int i=0;i<DataAdapter::a.size();i++)
    {
     if(!a[i].isNumber()&&a[i]!=' '&a[i]!='.')
     {

         return false;

     }
    }
    for(int i=0;i<DataAdapter::b.size();i++)
    {
        if(!b[i].isNumber()&&b[i]!=' '&&b[i]!='.')
        {
            return false;
        }
    }
    for(int i=0;i<DataAdapter::c.size();i++)
    {
        if(!c[i].isNumber()&&c[i]!=' '&&c[i]!='.')
        {

            return false;
        }
    }

    return true;
}
float DataAdapter::getQuantumTime()
{return DataAdapter::qtime;}
vector<int> DataAdapter::getPriority()
{
    return DataAdapter::priorities;
}
void DataAdapter::simulation()
{
    Sched *scheduler;
        if(DataAdapter::op1=="FCFS"||op1=="RR")
     {
         if(op1=="FCFS")scheduler=new firstInFirstOut(DataAdapter::getArrivalTime(),DataAdapter::getBurstTime());
         else scheduler=new RR(DataAdapter::getArrivalTime(),DataAdapter::getBurstTime(),DataAdapter::getQuantumTime());
     }
     else if(DataAdapter::op1=="SJF")
     {
         string subop=op2;
         scheduler=new SJF(getArrivalTime(),getBurstTime(),subop);
     }
     else
     {
       string subop=op2;
       scheduler=new Priority(getArrivalTime(),getBurstTime(),getPriority(),subop);
     }
     vector<Process>sim=scheduler->simulate();
  float y=10;
  float x=0;
      vector<QRect>rectangles;
        float res=0;
  for(int i=0;i<sim.size();i++)
  {
      float len=sim[i].finish-sim[i].start;
      len=3*len+40;
     rectangles.push_back(QRect(x,y,len,50));
     x+=len;
  }
  output *out=new output;
   out->setRectangles(rectangles,scheduler->AverageWaitingTime(),sim,timeunit);
   out->show();

}

vector<float> DataAdapter::SetVec(QString st)
{
    int k;
    for(int i=0;i<st.size();i++)
    {
      if(st[i]!=' ')
      {
          k=i;
          break;
      }
    }

        vector<float>arr;
        int prev=0;
        for(int i=k;i<st.size();i++)
        {
         if(st[i]==' '&&st[i+1]!=' '&&i!=st.size()-1)
         {
          float x=st.mid(prev,i-prev).toFloat();
          arr.push_back(x);
          prev=i+1;
         }
        }
        int x=st.mid(prev,st.size()-prev).toInt();
        arr.push_back(x);
        return arr;

}
vector<int>DataAdapter::SetVector(QString st)
{
    int k;
    for(int i=0;i<st.size();i++)
    {
      if(st[i]!=' ')
      {
          k=i;
          break;
      }
    }

        vector<int>arr;
        int prev=0;
        for(int i=k;i<st.size();i++)
        {
         if(st[i]==' '&&st[i+1]!=' '&&i!=st.size()-1)
         {
          float x=st.mid(prev,i-prev).toFloat();
          arr.push_back(x);
          prev=i+1;
         }
        }
        int x=st.mid(prev,st.size()-prev).toInt();
        arr.push_back(x);
        return arr;
}

vector<float>DataAdapter::getBurstTime(){return this->BurstTime;}
vector<float>DataAdapter::getArrivalTime(){return this->ArrivalTime;}

void DataAdapter::formalize()
{
 DataAdapter::ArrivalTime=SetVec(a);
 DataAdapter::BurstTime=SetVec(b);
 DataAdapter::priorities=SetVector(c);
}
bool DataAdapter::checkInputError()
{
    return ArrivalTime.size()!=BurstTime.size();
}
