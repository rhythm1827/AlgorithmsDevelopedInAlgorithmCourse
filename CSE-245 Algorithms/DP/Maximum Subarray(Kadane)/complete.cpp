//============================================================================
// Name        : Assignment 3.1
// Author      : S. M. Ruhul Kabir Howlader (2014-2-60-089)
// Version     : Final
// Copyright   : Private
// Description : Maximum sub-array with begin and end index.
//============================================================================

#include <bits/stdc++.h>
int *arrays;
int cnt;
using namespace std;
struct kadanes_struct
{
    int max;
    int begin_index;
    int end_index;
    int maxl;
    int begin_indexl;
    int end_indexl;
};
struct kadanes_struct kadane(int size)
{
    kadanes_struct obj;
    int pp,qq,p,q,i,begin_temp=0,begi=0,ending=0,begin_temp_low=0,begi_low=0,ending_low=0,thr=0;
    if(cnt==1)
    {
        int max_so_far = arrays[0];
        int max_ending_here = arrays[0];
        int max_so_far_low = 0;
        int max_ending_here_low = 0;
        for(i=0; i<size; i++)
        {
            max_ending_here+=arrays[i];
            max_ending_here_low+=arrays[i];
            if(max_ending_here<arrays[i])
            {
                begin_temp=i;
                max_ending_here = arrays[i];
            }
            if(max_so_far < max_ending_here)
            {
                max_so_far = max_ending_here;
            }
            if(max_ending_here_low>0)
            {
                begin_temp_low=i+1;
                max_ending_here_low = 0;
            }
            if(max_so_far_low > max_ending_here_low)
            {
                max_so_far_low = max_ending_here_low;
                begi_low=begin_temp_low;
                ending_low=i;
            }
        }
        p=begin_temp;
        q=begin_temp;
        pp=begi_low;
        qq=ending_low;
        obj.begin_index=p;
        obj.end_index=q;
        obj.max=max_so_far;
        obj.begin_indexl=pp;
        obj.end_indexl=qq;
        obj.maxl=max_so_far_low;
        return obj;
    }
    else
    {

        int max_so_far = 0;
        int max_ending_here = 0;
        int max_so_far_low = 0;
        int max_ending_here_low = 0;
        for(i=0; i<size; i++)
        {
            max_ending_here+=arrays[i];
            max_ending_here_low+=arrays[i];
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
            if(max_ending_here_low>0)
            {
                begin_temp_low=i+1;
                max_ending_here_low = 0;
            }
            if(max_so_far_low > max_ending_here_low)
            {
                max_so_far_low = max_ending_here_low;
                begi_low=begin_temp_low;
                ending_low=i;
            }
        }
        p=begi;
        q=ending;
        pp=begi_low;
        qq=ending_low;
        obj.begin_index=p;
        obj.end_index=q;
        obj.max=max_so_far;
        obj.begin_indexl=pp;
        obj.end_indexl=qq;
        obj.maxl=max_so_far_low;
        return obj;
    }
}
int main()
{
    int i,size;
    kadanes_struct maxi;
    int flag;
    while(cin>>size&&size!=0)
    {
        flag=0;
        arrays=new int[size];
        for(i=0; i<size; i++)
        {
            cin>> arrays[i];
            flag++;
        }
        if(flag==size)
            cnt=0;
        else
            cnt=1;
        maxi = kadane(size);
        cout<<maxi.max<<" (Day:"<<maxi.begin_index+1<<",Day:"<<maxi.end_index+1<<")"<<endl;
        cout<<maxi.maxl<<" (Day:"<<maxi.begin_indexl+1<<",Day:"<<maxi.end_indexl+1<<")"<<endl<<endl;
    }
    return 0;
}



