#include<bits/stdc++.h>
#define SIZE 10
#define infinite 100000000
long long mer[SIZE];
using namespace std;
void Merge(int p,int q,int r)
{
    int n1,n2;
    n1=q-p+1;
    n2=r-q;
    int L[n1+1],R[n2+1],i,j,k;
    for(i=0;i<n1;i++)
        L[i]=mer[p+i];
    for(j=0;j<n1;j++)
        R[j]=mer[q+j+1];
    L[n1]=infinite;
    R[n2]=infinite;
    i=0;
    j=0;
    for(k=p;k<=r;k++)
    {
        if(L[i]<=R[j])
        {
            mer[k]=L[i];
            i++;
        }
        else
        {
            mer[k]=R[j];
            j++;
        }
    }
}
void merge_sort(int p, int r)
{
    int q;
    if(p<r)
    {
        q=(p+r)/2;
        q=abs(q);
        merge_sort(p,q);
        merge_sort(q+1,r);
        Merge(p,q,r);
    }
}
int main()
{
    int i,input;
    srand(time(NULL));
    cout<<"Before sort"<<endl;
    for(i=0; i<SIZE; i++)
    {
        input=rand()%9+1;
        cout<<input<<" ";
        mer[i]=input;
    }
    cout<<endl<<"After sort"<<endl;
    merge_sort(0,SIZE-1);
    for(i=0; i<SIZE; i++)
    {
        cout<<mer[i]<<" ";
    }
    return 0;
}


