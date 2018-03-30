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
    int d;
    int parant;
};
struct Node G[SIZE];
void BFS(int n,int s)
{
    int i,u,v;
    for(i=1;i<=n;i++)
    {
        G[i].color=White;
        G[i].d=INT_MAX;
        G[i].parant=-1;
    }
    G[s].color=Grey;
    G[s].d=0;
    G[s].parant=-1;
    vect.push_back(s);
    while(vect.size()!=0)
    {
        u=vect.at(0);
        vect.erase(vect.begin());
        for(v=1;v<=SIZE;v++)
        {
            if(G[v].color==White&&mat[u][v]==1)
            {
                G[v].color=Grey;
                G[v].d=G[u].d+1;
                G[v].parant=u;
                vect.push_back(v);
            }
        }
        G[u].color=Black;
    }
}
void show(int n)
{
    int i,j;
    cout<<setw(02)<<"No"<<setw(10)<<"Distance"<<setw(10)<<"Parent"<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<setw(02)<<i<<" "<<setw(9)<<G[i].d<<" "<<setw(9)<<G[i].parant<<endl;
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
    cin>>s;
    cout<<endl;
    BFS(n,s);
    show(n);
    return 0;
}


