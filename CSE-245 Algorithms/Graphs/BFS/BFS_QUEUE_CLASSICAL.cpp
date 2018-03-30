#include<bits/stdc++.h>
#define SIZE 50
#define White 0
#define Grey 1
#define Black 2
using namespace std;
struct Node_queue
{
    int data;
    struct Node_queue *next;
} *temp, *node;

struct Head_queue
{
    int count;
    struct Node_queue *front;
    struct Node_queue *rear;
} *head_q;

void Head_create()
{
    head_q = (struct Head_queue*) malloc(sizeof(struct Head_queue));
    head_q->count = 0;
    head_q->front = NULL;
    head_q->rear = NULL;
}

void ENQUEUE(int value)
{
    node=(struct Node_queue*)malloc(sizeof(struct Node_queue));
    node->data = value;
    node->next=NULL;
    if(head_q->count==0)
    {
        head_q->front=node;
        head_q->rear=node;
        (head_q->count)++;
    }
    else
    {
        head_q->rear->next=node;
        head_q->rear=node;
        (head_q->count)++;
    }
}

void DEQUEUE()
{
    if(head_q->count == 1)
    {
        temp=head_q->front;
        head_q->rear=NULL;
        head_q->front=NULL;
        (head_q->count)--;
        free(temp);
    }
    else
    {
        temp=head_q->front;
        head_q->front=head_q->front->next;
        (head_q->count)--;
        free(temp);
    }
}
int mat[SIZE][SIZE];
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
    ENQUEUE(s);
    while(head_q->front!=NULL)
    {
        u=head_q->front->data;
        DEQUEUE();
        for(v=1;v<=SIZE;v++)
        {
            if(G[v].color==White&&mat[u][v]==1)
            {
                G[v].color=Grey;
                G[v].d=G[u].d+1;
                G[v].parant=u;
                ENQUEUE(v);
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
    Head_create();
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


