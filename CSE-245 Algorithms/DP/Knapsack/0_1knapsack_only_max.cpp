#include<bits/stdc++.h>
#define SIZE 1000
using namespace std;
int weight[SIZE];
int value[SIZE];
int T[SIZE+3][SIZE+3];
int S[SIZE+3][SIZE+3];
int Knapsack(int item,int TotalWeight)
{
    for(int i=1; i<=item; i++)
    {
        for(int j=1; j<=TotalWeight; j++)
        {
            if(j<weight[i])
                T[i][j]=T[i-1][j];
            else
                T[i][j]=max(value[i]+T[i-1][j-weight[i]],T[i-1][j]);
        }
    }
    return T[item][TotalWeight];
}
void ShowMatrix(int item,int TotalWeight)
{
    for(int i=1; i<=item; i++)
    {
        for(int j=1; j<=TotalWeight; j++)
        {
            cout<<T[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int i,j,k,l,m,n,p,q,r,a,b,c,item,TotalWeight,MaxRevenue;
    cout<<"Total Weight: ";
    cin>>TotalWeight;
    cout<<"Total Item: ";
    cin>>item;
    for(i=1; i<=item; i++)
        cin>>weight[i]>>value[i];
    MaxRevenue=Knapsack(item,TotalWeight);
    ShowMatrix(item,TotalWeight);
    cout<<"Max Revenue = "<<MaxRevenue<<endl;
    return 0;
}

