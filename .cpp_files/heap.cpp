#include "heap.h"
const int INF=99999999;
heap::heap()
{
SIZE=0;
}
int heap::getSIZE(){return SIZE;}
int   heap::lefttChild(int i){return 2*i+1;}
int heap::rightChild(int i){return 2*i+2;}
int heap::parent(int i){return (i-1)/2;}

bool Compare(pair<int,float> a,pair<int,float>b)
{
return a.second<b.second;
}

    void heap::siftDown(int i)
    {
        while(1)
        {
            int maxindex=i;
            int l=lefttChild(i);
            int r=rightChild(i);
            if(Compare(value[l],value[maxindex])&&l<value.size())
            {
                maxindex=l;
            }
            if(Compare(value[r],value[maxindex])&&r<value.size())
            {
                maxindex=r;
            }
            if (i==maxindex)
                return;
            swap(value[i],value[maxindex]);

            i=maxindex;
        }
    }
    void heap::siftUp(int i)
    {
    while(value[i].second<value[parent(i)].second)
    {
    swap(value[i],value[parent(i)]);
    i=parent(i);
    }
    }
    bool heap::isEmpty()
{return SIZE==0;}

void heap::Insert(pair<int,float> val)
{
SIZE++;
value.push_back(val);
siftUp(value.size()-1);
}
pair<int,float> heap::top(){return value[0];}
void heap::deleteTop()
{
if(isEmpty())return;
else SIZE--;
value[0].second=INF;
siftDown(0);
}

