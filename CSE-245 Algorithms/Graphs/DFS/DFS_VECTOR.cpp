#include<bits/stdc++.h>
#define SIZE 50
#define White 0
#define Grey 1
#define Black 2
using namespace std;
int mat[SIZE][SIZE];
vector<int>vect;
struct Node
{
    int color;
    int parant;
    int d; //discover times
    int f; //finishing times
};
struct Node G[SIZE];
int times;
void DFS_Visit(int u)
{
    times++;
    G[u].d=times;
    G[u].color=Grey;
    for(int v=1;v<=SIZE;v++)
    {
        if(G[v].color==White&&mat[u][v]==1)
        {
            G[v].parant=u;
            DFS_Visit(v);
        }
    }
    G[u].color=Black;
    times++;
    G[u].f=times;
}
void DFS(int n)
{
    int u,i,j;
    for(u=1;u<=n;u++)
    {
        G[u].color=White;
        G[u].parant=-1;
    }
    times=0;
    for(u=1;u<=n;u++)
    {
        if(G[u].color==White)
            DFS_Visit(u);
    }
}
void show(int n)
{
    cout<<setw(02)<<"No"<<setw(15)<<"Discover time"<<setw(16)<<"Finishing time"<<setw(8)<<"Parent"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<setw(02)<<i<<setw(15)<<G[i].d<<setw(16)<<G[i].f<<setw(8)<<G[i].parant<<endl;
    }
}
int main()
{
    int i,j,k,a,b,n,s;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            cin>>mat[i][j];
        }
    }
    cout<<endl;
    DFS(n);
    show(n);
    return 0;
}

