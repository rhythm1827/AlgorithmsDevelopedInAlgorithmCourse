//============================================================================
// Name        : new.cpp
// Author      : rhythm
// Version     : Final
// Copyright   : Private
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<bits/stdc++.h>
#define SIZE 500000
#define infinite 10000000
using namespace std;
long long mer[SIZE];
long long qui[SIZE];
long long bui[SIZE];
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
void Merge(int p,int q,int r)
{
    int n1,n2;
    n1=q-p+1;
    n2=r-q;
    int L[n1+1],R[n2+1],i,j,k;
    for(i=0;i<n1;i++)
        L[i]=mer[p+i];
    for(j=0;j<n1;j++)
        R[j]=mer[q+j+1];
    L[n1]=infinite;
    R[n2]=infinite;
    i=0;
    j=0;
    for(k=p;k<=r;k++)
    {
        if(L[i]<=R[j])
        {
            mer[k]=L[i];
            i++;
        }
        else
        {
            mer[k]=R[j];
            j++;
        }
    }
}
void merge_sort(int p, int r)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        q=abs(q);
        merge_sort(p,q);
        merge_sort(q+1,r);
        Merge(p,q,r);
    }
}
int main()
{
    long long i,time_begin,time_end,input,sub;
    srand(time(NULL));
    for(i=0; i<SIZE; i++)
    {
        input=rand()%999+1;
        mer[i]=input;
        qui[i]=input;
        bui[i]=input;
    }

    time_begin=clock();
    merge_sort(0,SIZE-1);
    time_end=clock();
    sub=time_end-time_begin;
    cout<<"Merge sort"<<endl<<endl;
    cout<<"      Ticks: "<<sub<<endl;
    cout<<"      Time in seconds: "<<(double)sub/(double)CLOCKS_PER_SEC<<endl<<endl<<endl;

    time_begin=clock();
    Randomized_quickSort(0,SIZE-1);
    time_end=clock();
    sub=time_end-time_begin;
    cout<<"Quick sort"<<endl<<endl;
    cout<<"      Ticks: "<<sub<<endl;
    cout<<"      Time in seconds: "<<(double)sub/(double)CLOCKS_PER_SEC<<endl<<endl<<endl;

    time_begin=clock();
    sort(bui,bui+SIZE);
    time_end=clock();
    sub=time_end-time_begin;
    cout<<"Built in sort"<<endl<<endl;
    cout<<"      Ticks: "<<sub<<endl;
    cout<<"      Time in seconds: "<<(double)sub/(double)CLOCKS_PER_SEC<<endl<<endl<<endl;
    return 0;
}


