//============================================================================
// Name        : AllSortComplexity.cpp
// Author      : rhythm
// Version     : Final
// Copyright   : Private
// Description : Hello World in C++, Ansi-style
//============================================================================

#include<bits/stdc++.h>
#define SIZE 5000
using namespace std;
long long M[SIZE];
long long Q[SIZE];
long long B[SIZE];
long long I[SIZE];
long long bui[SIZE];
void bubble_sort()
{
    int i,j,k,l,n=0,m=0;
    for(i=0; i<SIZE-1; i++)
    {
        for(j=SIZE-1; j>=i+1; j--)
        {
            if(B[j]<B[j-1])
            {
                swap(B[j],B[j-1]);
            }
        }
    }
}
void insertion_sort()
{
    int i,j,k,l,n=0,m=0,key;
    for(j=1; j<SIZE; j++)
    {
        key=I[j];
        i=j-1;
        while(i>=0&&I[i]>key)
        {
            I[i+1]=I[i];
            i--;
        }
        I[i+1]=key;
    }
}
long partion(int p, int r)
{
    int x,i,j;
    x=Q[r];
    i=p-1;
    for(j=p;j<=r-1;j++)
    {
        if(Q[j]<=x)
        {
            i++;
            swap(Q[i],Q[j]);
        }
    }
    swap(Q[i+1],Q[r]);
    return i+1;
}
int Randomized_partition(int p,int r)
{
    long i,g;
    g=r-p;
    i=p+rand()%g;
    swap(Q[r],Q[i]);
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
        L[i]=M[p+i];
    for(j=0;j<n1;j++)
        R[j]=M[q+j+1];
    L[n1]=LONG_LONG_MAX;
    R[n2]=LONG_LONG_MAX;
    i=0;
    j=0;
    for(k=p;k<=r;k++)
    {
        if(L[i]<=R[j])
        {
            M[k]=L[i];
            i++;
        }
        else
        {
            M[k]=R[j];
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
        M[i]=input;
        Q[i]=input;
        B[i]=input;
        I[i]=input;
        bui[i]=input;
    }
    time_begin=clock();
    bubble_sort();
    time_end=clock();
    sub=time_end-time_begin;
    cout<<"Bubble sort"<<endl<<endl;
    cout<<"      Ticks: "<<sub<<endl;
    cout<<"      Time in seconds: "<<(double)sub/(double)CLOCKS_PER_SEC<<endl<<endl<<endl;

    time_begin=clock();
    insertion_sort();
    time_end=clock();
    sub=time_end-time_begin;
    cout<<"Insertion sort"<<endl<<endl;
    cout<<"      Ticks: "<<sub<<endl;
    cout<<"      Time in seconds: "<<(double)sub/(double)CLOCKS_PER_SEC<<endl<<endl<<endl;

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


