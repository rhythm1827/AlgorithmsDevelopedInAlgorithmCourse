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
    int i,j,m[n+3],p[n+3],q,r[n+3];
    cout<<"Normally"<<endl<<endl;
    cout<<setw(02)<<"No"<<setw(10)<<"Distance"<<setw(10)<<"Parent"<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<setw(02)<<i<<" "<<setw(9)<<G[i].d<<" "<<setw(9)<<G[i].parant<<endl;
    }
    cout<<"\n\nSorted by distance"<<endl<<endl;
    for(i=1;i<=n;i++)
    {
        m[i]=i;
        r[i]=G[i].d;
        p[i]=G[i].parant;
    }
    for(i=1; i<=n-1; i++)
    {
        for(j=n; j>i; j--)
        {
            if(r[j]<r[j-1])
            {
                swap(r[j],r[j-1]);
                swap(p[j],p[j-1]);
                swap(m[j],m[j-1]);
            }
        }
    }
    cout<<setw(02)<<"No"<<setw(10)<<"Distance"<<setw(10)<<"Parent"<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<setw(02)<<m[i]<<" "<<setw(9)<<r[i]<<" "<<setw(9)<<p[i]<<endl;
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


