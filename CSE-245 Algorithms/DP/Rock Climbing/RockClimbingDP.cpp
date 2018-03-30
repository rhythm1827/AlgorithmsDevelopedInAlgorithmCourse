#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll A[1000][1000], R[1000][1000];
void ShowMat(ll n, ll m)
{
    ll i,j;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
            cout<<R[i][j]<<" ";
        cout<<endl;
    }
}
void RockPath(ll n,ll m)
{
    ll i=n,c,r=LONG_LONG_MAX,j,u,v,w;
    for(j=1; j<=m; j++)
    {
        if(R[i][j]<r)
        {
            c=j;
            r=R[i][j];
        }
    }
    cout<<A[i][c];
    for(i=n-1; i>0; i--)
    {
        if(R[i][c]<R[i][c-1]&&R[i][c]<R[i][c+1])
        {
            cout<<" "<<A[i][c];
        }
        else if(R[i][c+1]<R[i][c-1]&&R[i][c+1]<R[i][c])
        {
            cout<<" "<<A[i][c+1];
            c=c+1;
        }
        else
        {
            cout<<" "<<A[i][c-1];
            c=c-1;
        }
    }
}
void RockClimbing(ll n,ll m)
{
    ll a,b,c,i,j,k;
    for(j=1; j<=m; j++)
        R[1][j]=A[1][j];
    for(i=2; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            //min{A(i-1,j-1),A(i-1,j),A(i-1,j+1)}
            k = min(R[i-1][j-1],R[i-1][j]);
            a = min(k,R[i-1][j+1]);
            R[i][j] = A[i][j] + a;
        }
    }
}

int main()
{

    ll a,b,c,d,i,j,k,n,m;
    cin>>n>>m;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            cin>>A[i][j];
    for(i=0; i<=n; i++)
    {
        R[i][0]= LONG_LONG_MAX;
        R[i][m+1]= LONG_LONG_MAX;
    }
    cout<<endl;
    RockClimbing(n,m);
    RockPath(n,m);
    cout<<endl<<endl;
    ShowMat(n,m);
    return 0;
}

/*
4 5
3 2 5 4 8
5 7 5 6 1
4 4 6 2 3
2 8 9 5 8

3 2 5 4 8
7 9 7 10 5
11 11 13 7 8
13 19 16 12 15
*/
