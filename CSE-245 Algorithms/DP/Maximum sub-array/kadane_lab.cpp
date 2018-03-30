//============================================================================
// Name        : Lab 04
// Author      : S. M. Ruhul Kabir Howlader (2014-2-60-089)
// Version     : Final
// Copyright   : Private
// Description : Maximum sub-array with begin and end index.
//============================================================================

#include <bits/stdc++.h>
int *arrays;
using namespace std;
struct kadanes_struct
{
    int max;
    int begin_index;
    int end_index;
};
struct kadanes_struct_neg
{
    int max;
    int begin_index;
    int end_index;
};
struct kadanes_struct kadane(int size)
{
    kadanes_struct obj;
    int p,q,i,begin_temp=0,begi=0,ending=0;
    int max_so_far = 0;
    int max_ending_here = 0;
    for(i=0; i<size; i++)
    {
        max_ending_here+=arrays[i];
        if(max_ending_here<0)
        {
            begin_temp=i+1;
            max_ending_here = 0;
        }
        if(max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            begi=begin_temp;
            ending=i;
        }
    }
    p=begi;
    q=ending;
    obj.begin_index=p;
    obj.end_index=q;
    obj.max=max_so_far;
    return obj;
}

struct kadanes_struct_neg kadane_neg(int size)
{
    kadanes_struct_neg obj;
    int p,q,i,begin_temp=0,begi=0,ending=0;
    int max_so_far = 0;
    int max_ending_here = 0;
    for(i=0; i<size; i++)
    {
        max_ending_here+=arrays[i];
        if(max_ending_here>0)
        {
            begin_temp=i+1;
            max_ending_here = 0;
        }
        if(max_so_far > max_ending_here)
        {
            max_so_far = max_ending_here;
            begi=begin_temp;
            ending=i;
        }
    }
    p=begi;
    q=ending;
    obj.begin_index=p;
    obj.end_index=q;
    obj.max=max_so_far;
    return obj;
}
struct kadanes_struct kadane_all(int size)
{
    kadanes_struct obj;
    int p,q,i,begin_temp=0,begi=0,ending=0;
    int max_so_far = arrays[0];
    int max_ending_here = arrays[0];
    for(i=0; i<size; i++)
    {
        max_ending_here+=arrays[i];
        if(max_ending_here>arrays[i])
        {
            //begin_temp=i;
            max_ending_here = arrays[i];
        }
        if(max_so_far > max_ending_here)
        {
            max_so_far = max_ending_here;
           // begi=begin_temp;
           // ending=i;
           begin_temp=i;
        }
    }
    p=begin_temp;
    q=begin_temp;
    obj.begin_index=p;
    obj.end_index=q;
    obj.max=max_so_far;
    return obj;
}
struct kadanes_struct kadane_all_neg(int size)
{
    kadanes_struct obj;
    int p,q,i,begin_temp=0,begi=0,ending=0;
    int max_so_far = arrays[0];
    int max_ending_here = arrays[0];
    for(i=0; i<size; i++)
    {
        max_ending_here+=arrays[i];
        if(max_ending_here<arrays[i])
        {
            //begin_temp=i;
            max_ending_here = arrays[i];
        }
        if(max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
           // begi=begin_temp;
           // ending=i;
           begin_temp=i;
        }
    }
    p=begin_temp;
    q=begin_temp;
    obj.begin_index=p;
    obj.end_index=q;
    obj.max=max_so_far;
    return obj;
}
int main()
{
    int i,size,cnt,neg,pos;
    kadanes_struct maxi,mini2;
    kadanes_struct_neg mini;
    while(cin>>size&&size!=0)
    {
        cnt=0;
        neg=0;
        pos=0;
        arrays=new int[size];
        for(i=0; i<size; i++)
        {
            cin>> arrays[i];
            if(arrays[i]>0)
                pos++;
            else
                neg++;
        }
        if(pos==size)
        {
            maxi = kadane(size);
            mini2 = kadane_all(size);
            cout<<maxi.max<<" (Day:"<<maxi.begin_index+1<<",Day:"<<maxi.end_index+1<<")"<<endl;
            cout<<mini2.max<<" (Day:"<<mini2.begin_index+1<<",Day:"<<mini2.end_index+1<<")"<<endl;
        }
        else if(neg==size)
        {
            mini = kadane_neg(size);
            mini2 = kadane_all_neg(size);
            cout<<mini2.max<<" (Day:"<<mini2.begin_index+1<<",Day:"<<mini2.end_index+1<<")"<<endl;
            cout<<mini.max<<" (Day:"<<mini.begin_index+1<<",Day:"<<mini.end_index+1<<")"<<endl;
        }
        else
        {
            maxi = kadane(size);
            mini = kadane_neg(size);
            cout<<maxi.max<<" (Day:"<<maxi.begin_index+1<<",Day:"<<maxi.end_index+1<<")"<<endl;
            cout<<mini.max<<" (Day:"<<mini.begin_index+1<<",Day:"<<mini.end_index+1<<")"<<endl;
        }
        cout<<endl;
    }
    return 0;
}

