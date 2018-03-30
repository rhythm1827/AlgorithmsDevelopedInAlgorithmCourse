#include<bits/stdc++.h>
using namespace std;
char str[1005];
int lps[3000][3000];
void longest_pal_sub(int n)
{
    int i,j,k;
    for(i=0; i<n; i++)
        lps[i][i]=1;
    for(k=2; k<=n; k++)
    {
        for(i=0; i<n; i++)
        {
            j=i+k-1;
            if(str[i]==str[j]&&k==2)
            {
                lps[i][j]=2;
            }
            else if(str[i]==str[j])
            {
                lps[i][j]=2+lps[i+1][j-1];
            }
            else
                lps[i][j]=max(lps[i][j-1],lps[i+1][j]);
        }
    }
}
void show(int p)
{
    int i,j;
    for(i=0; i<p; i++)
    {
        for(j=0; j<p; j++)
        {
            cout<<lps[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int p,c,len,i;
    cin>>p;
    getchar();
    for(i=0;i<p;i++)
        //gets(str);
    {
        gets(str);
        len=strlen(str);
        longest_pal_sub(len);
        //cout<<endl;
        //show(len);
        //cout<<endl<<"Length of LPS: "<<lps[0][len-1]<<endl<<endl;
        cout<<lps[0][len-1]<<endl;
    }
}

