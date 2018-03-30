#include<bits/stdc++.h>
#define SIZE 3
using namespace std;
long long mer[SIZE];
long partion(int p, int r)
{
    int x,i,j;
    x=mer[r];
    i=p-1;
    for(j=p;j<=r-1;j++)
    {
        if(mer[j]<=x)
        {
            i++;
            swap(mer[i],mer[j]);
        }
    }
    swap(mer[i+1],mer[r]);
    return i+1;
}
void quickSort(int p, int r)
{
    long q;
    if(p<r)
    {
        q=partion(p,r);
        quickSort(p,q-1);
        quickSort(q+1,r);
    }
}

int main()
{
    int i,input;
    cout<<"Before sort"<<endl;
    for(i=0; i<SIZE; i++)
    {
        input=rand()%9+1;
        cout<<input<<" ";
        mer[i]=input;
    }
    cout<<endl<<"After sort"<<endl;
    quickSort(0,SIZE-1);
    for(i=0; i<SIZE; i++)
    {
        cout<<mer[i]<<" ";
    }
    return 0;
}
