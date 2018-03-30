#include<bits/stdc++.h>
#define SIZE 50
#define White 0
#define Gray 1
#define Black 2
using namespace std;
int mat[SIZE][SIZE];
vector<int>vect;
struct Node
{
    int parant;
    int d; //discover times
    int f; //finishing times
    struct Node *next;
} *temp, *node;

struct Head
{
    int count;
    struct Node *first;
} *head;
struct NodeDFS
{
    int color;
    int parant;
    int d; //discover times
    int f; //finishing times
};
struct NodeDFS G[SIZE];
int times;
void Head_create()
{
    head = (struct Head*) malloc(sizeof(struct Head));
    head->count = 0;
    head->first = NULL;
}

void Add_value_start(int parent,int d,int f)
{
    node = (struct Node*) malloc(sizeof(struct Node));
    node->parant=parent;
    node->d=d;
    node->f=f;
    node->next = head->first;
    head->first = node;
    (head->count)++;
}
void DFS_Visit(int u)
{
    times++;
    G[u].d=times;
    G[u].color=Gray;
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
void Topological_Show()
{
    int i=1;
    temp = head->first;
    cout<<setw(02)<<"No"<<setw(15)<<"Discover time"<<setw(16)<<"Finishing time"<<setw(8)<<"Parent"<<endl;
    while(temp != NULL)
    {
        cout<<setw(02)<<i<<setw(15)<<temp->d<<setw(16)<<temp->f<<setw(8)<<temp->parant<<endl;
        temp = temp->next;
        i++;
    }
}
void TopologicalSort(int n)
{
    Head_create();
    for(int i=1; i<=n; i++)
    {
        for(int j=n; j>i; j--)
        {
            if(G[j].f>G[j-1].f)
            {
                swap(G[j].f,G[j-1].f);
                swap(G[j].d,G[j-1].d);
                swap(G[j].parant,G[j-1].parant);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        int d=G[i].d;
        int f=G[i].f;
        int parent=G[i].parant;
        Add_value_start(parent,d,f);
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
    TopologicalSort(n);
    Topological_Show();
    show(n);
    return 0;
}


