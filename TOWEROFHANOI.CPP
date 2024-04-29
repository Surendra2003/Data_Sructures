#include <iostream>

using namespace std;
void towerofhanoi( int start,int end,char source,char aux,char destination)
{
    if (start>end)
    {
        return;
    }
    towerofhanoi(start,end-1,source,destination,aux);
    cout<<"move disc "<<end<<" from"<< source<<" to"<< destination<<endl;
    towerofhanoi(start,end-1,aux,source,destination);
}

int main()
{
     towerofhanoi(1,3,'A','B','C');
    

    return 0;
}