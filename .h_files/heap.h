#ifndef HEAP_H
#define HEAP_H
#include<vector>
using std::vector;
using std::pair;
class heap
{
    public:
        heap();
        int getSIZE();
        bool isEmpty();
        void siftUp(int);
        void siftDown(int);
void Insert(pair<int,float>);
pair<int,float> top();
void deleteTop();
    private:
vector<pair<int,float> >value;
int lefttChild(int);
int rightChild(int);
int parent(int);
int SIZE;
};

#endif // HEAP_H
