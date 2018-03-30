#include<bits/stdc++.h>
using namespace std;
int *s;
long long c[10022];
int *d;

void counting_ways()
{
    c[0]=1;
    for(int i=0; i<22; i++)
    {
        for(int j=d[i]; j<10015; j++)
        {
            c[j]=c[j]+c[j-d[i]];
        }
    }
}
int main()
{
    int n=10018,k=21,v;
    d=new int[k+1];
    for(int i=0; i<=k; i++)
    {
        d[i]=(i+1)*(i+1)*(i+1);
    }
    counting_ways();
    while(cin>>v)
    {
        cout<<c[v]<<endl;
    }
    return 0;
}

