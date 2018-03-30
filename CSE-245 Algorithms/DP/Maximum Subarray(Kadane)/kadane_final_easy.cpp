#include<bits/stdc++.h>
using namespace std;
struct kadane
{
    int max;
    int min;
    int begin_index_max;
    int end_index_max;
    int begin_index_min;
    int end_index_min;
};
struct kadane MaxSubArray(int SIZE,int a[])
{
    kadane obj;
    int max_so_far = a[0],min_so_far = a[0];
    int max_ending_here = a[0],min_ending_here = a[0] ;
    int begin=0,begin_temp=0,end=0,begin1=0,begin_temp1=0,end1=0;
    for(int i=1; i<SIZE; i++)
    {
        max_ending_here+=a[i];
        min_ending_here+=a[i];
        if(max_ending_here<a[i])
        {
            max_ending_here = a[i];
            begin_temp=i;
        }
        if(max_so_far<max_ending_here)
        {
            max_so_far = max_ending_here;
            end=i;
            begin=begin_temp;
        }
        if(min_ending_here>a[i])
        {
            min_ending_here=a[i];
            begin_temp1=i;
        }
        if(min_so_far>min_ending_here)
        {
            begin1=begin_temp1;
            min_so_far=min_ending_here;
            end1=i;
        }

    }
    obj.max=max_so_far;
    obj.min=min_so_far;
    obj.begin_index_max=begin+1;
    obj.end_index_max=end+1;
    obj.begin_index_min=begin1+1;
    obj.end_index_min=end1+1;
    return obj;
}
int main()
{
    int SIZE,a[100];
    kadane rex;
    while(cin>>SIZE&&SIZE!=0)
    {

        for(int i=0; i<SIZE; i++)
        {
            cin>>a[i];
        }
        rex=MaxSubArray(SIZE,a);
        cout<<rex.max<<" (Day:"<<rex.begin_index_max<<",Day:"<<rex.end_index_max<<")"<<endl;
        cout<<rex.min<<" (Day:"<<rex.begin_index_min<<",Day:"<<rex.end_index_min<<")"<<endl<<endl;
    }
    return 0;
}

