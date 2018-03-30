#include<bits/stdc++.h>
using namespace std;
int r[10000],s[10000],p[11]={0,1,5,8,9,10,17,17,20,24,30};
void extended_bottom_up_cut_rod(int n)
{
    int j,q,i;
    for(j=1;j<=n;j++)
    {
        q=INT_MIN;
        for(i=1;i<=j;i++)
        {
            if(q<p[i]+r[j-i])
            {
                q=p[i]+r[j-i];
                s[j]=i;
            }
        }
        r[j]=q;
    }
    cout<<"R : ";
    for(i=1;i<=n;i++)
        cout<<r[i]<<" ";
    cout<<endl<<"S : ";;
    for(i=1;i<=n;i++)
        cout<<s[i]<<" ";
    cout<<endl;
}
void print_cut_rod_solution(int n)
{
    int m=n;
    extended_bottom_up_cut_rod(n);
    cout<<"Cutting points : ";
    while(n>0)
    {
        cout<<s[n]<<" ";
        n=n-s[n];
    }
    cout<<endl<<"Max Revenue: "<<r[m]<<endl;
}

int main()
{
    int n,i,j;
    cout<<"Rod lengths: ";
    for(i=1;i<=10;i++)
        cout<<p[i]<<" ";
    cout<<endl<<"Taken length: ";
    cin>>n;
    cout<<endl;
    print_cut_rod_solution(n);
    cout<<endl;
    return 0;
}
