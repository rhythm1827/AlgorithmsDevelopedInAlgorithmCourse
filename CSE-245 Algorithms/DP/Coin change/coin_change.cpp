#include<bits/stdc++.h>
using namespace std;
int *s;
int *c;
int *d;
void Change(int k,int n)
{
    c[0]=0;
    int p,i,min,coin;
    for(p=1; p<=n; p++)
    {
        min=INT_MAX;
        for(i=1; i<=k; i++)
        {
            if(d[i]<=p)
            {
                if((1+c[p-d[i]])<min)
                {
                    min=1+c[p-d[i]];
                    coin=d[i];
                }
            }
        }
        c[p]=min;
        s[p]=coin;
    }
}
void make_change(int n)
{
    while(n>0)
    {
        cout<<s[n]<<" ";
        n=n-s[n];
    }
}
int main()
{
    int n,k,v;
    cout<<"Enter no of coins variation & coin types: ";
    cin>>n>>k;
    s=new int[n+1];
    d=new int[k+1];
    c=new int[n+1];
    cout<<"Coin types: ";
    for(int i=1; i<=k; i++)
    {
        cin>>d[i];
    }
    Change(k,n);
    cout<<"Coins needed: ";
    cin>>v;
    cout<<"Result: ";
    make_change(v);
    return 0;
}
