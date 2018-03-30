#include<bits/stdc++.h>
using namespace std;
int *s;
long long c[30022];
int *d;

void counting_ways()
{
    c[0]=1;
    for(int i=0; i<6; i++)
    {
        for(int j=d[i]; j<30015; j++)
        {
            c[j]=c[j]+c[j-d[i]];
        }
    }
}
int main()
{
    int n=30018,k=5,v;
    d=new int[k+1];
    d[0]=1;
    d[1]=5;
    d[2]=10;
    d[3]=25;
    d[4]=50;
    counting_ways();
    while(cin>>v)
    {
        cout<<c[v]<<endl;

    }
    return 0;
}

