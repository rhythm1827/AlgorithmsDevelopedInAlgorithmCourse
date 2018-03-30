//============================================================================
// Name        : Lab.cpp
// Author      : S. M. Ruhul Kabir Howlader
// Version     : Final
// Copyright   : This is my private program
// Description : C++, Ansi-style
//============================================================================

#include<bits/stdc++.h>
#define SIZE 7
long long mer[SIZE];
using namespace std;

struct finder
{
	int min;
	int max;
};

struct finder maxmini(int p,int r)
{
    int mini,maxi,q;
    finder cemp,temp,objk;
    if(p==r)
    {
    	objk.min=mer[p];
    	objk.max=mer[p];
    	return objk;
    }
    if(p==r-1)
    {
        if(mer[p]<mer[r])
        {
            mini=mer[p];
            maxi=mer[r];
        }
        else
        {
        	mini=mer[r];
        	maxi=mer[p];
        }
        objk.min=mini;
        objk.max=maxi;
        return objk;
    }
    else
    {
        q=(p+r)/2;
        cemp=maxmini(p,q);
        temp=maxmini(q+1,r);
        if(cemp.min>=temp.min)
            objk.min=temp.min;
        else
            objk.min=cemp.min;
        if(cemp.max<=temp.max)
            objk.max=temp.max;
        else
            objk.max=cemp.max;
        return objk;
    }
}
int main()
{
    srand(time(NULL));
    int i,input;
    finder obj;
    cout<<"Inputs : ";
    for(i=0;i<SIZE;i++)
    {
        input=rand()%20+1;
        mer[i]=input;
        cout<<input<<" ";
    }
    obj=maxmini(0,SIZE-1);
    cout<<endl<<"Minimum: "<<obj.min<<"\nMaximum: "<<obj.max<<endl;
    return 0;
}



