#include<bits/stdc++.h>
#define SIZE 7
using namespace std;
long long qui[SIZE];
long partion(int p, int r)
{
    int x,i,j;
    x=qui[r];
    i=p-1;
    for(j=p;j<=r-1;j++)
    {
        if(qui[j]<=x)
        {
            i++;
            swap(qui[i],qui[j]);
        }
    }
    swap(qui[i+1],qui[r]);
    return i+1;
}
int Randomized_partition(int p,int r)
{
    long i,g;
    g=r-p;
    i=p+rand()%g;
    cout<<qui[i]<<" ";
    swap(qui[r],qui[i]);
    return partion(p,r);
}
void Randomized_quickSort(int p, int r)
{
    long q;
    if(p<r)
    {
        q=Randomized_partition(p,r);
        Randomized_quickSort(p,q-1);
        Randomized_quickSort(q+1,r);
    }
}

int main()
{
    int i,input;
    srand(time(NULL));
    cout<<"Before sort"<<endl;
    for(i=0; i<SIZE; i++)
    {
        input=rand()%9+1;
        cout<<input<<" ";
        qui[i]=input;
    }
    cout<<endl<<endl<<"pivot: ";
    Randomized_quickSort(0,SIZE-1);
    cout<<endl<<endl<<"After sort"<<endl;
    for(i=0; i<SIZE; i++)
    {
        cout<<qui[i]<<" ";
    }
    return 0;
}

