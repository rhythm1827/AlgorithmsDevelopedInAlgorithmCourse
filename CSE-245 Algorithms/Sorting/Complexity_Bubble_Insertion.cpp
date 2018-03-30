#include<bits/stdc++.h>
#define SIZE 200000
long long bub[SIZE];
long long ins[SIZE];
long long com_b=0;
long long com_i=0;
long long ex_b=0;
long long ex_i=0;
using namespace std;
void bubble_sort()
{
    int i,j,k,l,n=0,m=0;
    for(i=0; i<SIZE-1; i++)
    {
        for(j=SIZE-1; j>=i+1; j--)
        {
            if(bub[j]<bub[j-1])
            {
                swap(bub[j],bub[j-1]);
                ex_b++;
            }
            com_b++;
        }
    }
}
void insertion_sort()
{
    int i,j,k,l,n=0,m=0,key;
    for(j=1; j<SIZE; j++)
    {
        key=ins[j];
        i=j-1;
        while(i>=0&&ins[i]>key)
        {
            com_i++;
            if(ins[i]>key)
            {
                ins[i+1]=ins[i];
                ex_i++;
            }
            i--;
        }
        ins[i+1]=key;
    }
}
int main()
{
    long long i,time_begin,time_end,input,sub;
    srand(time(NULL));
    for(i=0; i<SIZE; i++)
    {
        input=rand();
        bub[i]=input;
        ins[i]=input;
    }

    time_begin=clock();
    bubble_sort();
    time_end=clock();
    sub=time_end-time_begin;
    cout<<"Bubble sort"<<endl<<endl;
    cout<<"      Ticks: "<<sub<<endl;
    cout<<"      Comparison: "<<com_b<<endl;
    cout<<"      Exchange: "<<ex_b<<endl;
    cout<<"      Time in seconds: "<<(double)sub/(double)CLOCKS_PER_SEC<<endl<<endl<<endl;

    time_begin=clock();
    insertion_sort();
    time_end=clock();
    sub=time_end-time_begin;
    cout<<"Insertion sort"<<endl<<endl;
    cout<<"      Ticks: "<<sub<<endl;
    cout<<"      Comparison: "<<com_i<<endl;
    cout<<"      Exchange: "<<ex_i<<endl;
    cout<<"      Time in seconds: "<<(double)sub/(double)CLOCKS_PER_SEC<<endl<<endl<<endl;
    return 0;
}


