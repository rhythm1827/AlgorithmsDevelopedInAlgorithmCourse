#include<bits/stdc++.h>
#define length 7
using namespace std;
int p[length]= {30,35,15,5,10,20,25};
int m[8][8];
int s[8][8];
void matrixChainOrder()
{
    int i,j,k,q,n,l;
    n=length-1;
    for(i=1; i<=n; i++)
        m[i][i]=0;
    for(l=2; l<=n; l++)
    {
        for(i=1; i<=n-l+1; i++)
        {
            j=i+l-1;
            m[i][j]=INT_MAX;
            for(k=i; k<=j-1; k++)
            {
                q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }
}
void printOptimalParens(int i,int j)
{
    if(i==j)
        cout<<"A"<<i;
    else
    {
        cout<<"(";
        printOptimalParens(i,s[i][j]);
        cout<<" x ";
        printOptimalParens(s[i][j]+1,j);
        cout<<")";
    }
}
void matrixStructure()
{
    int i,j;
    for(i=1; i<length; i++)
    {
        for(j=1; j<length; j++)
        {
            cout<<setw(6)<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(i=1; i<length; i++)
    {
        for(j=1; j<length; j++)
        {
            cout<<setw(6)<<s[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
    int i,j,k;
    matrixChainOrder();
    matrixStructure();
    printOptimalParens(1,length-1);
    cout<<endl;
    return 0;
}
