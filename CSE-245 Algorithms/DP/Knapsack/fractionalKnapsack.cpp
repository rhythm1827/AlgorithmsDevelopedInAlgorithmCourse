#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,ans=0,s,n;
    double p[2005],q[2005],r[2005];
    cout<<"Max weight and total object: ";
    cin>>s>>n;
    for(i=0; i<n; i++)
    {
        cout<<"Weight :";
        cin>>p[i];
        cout<<"Price :";
        cin>>q[i];
        r[i]=(q[i]/p[i])*1.0;
    }
    for(i=0; i<n-1; i++)
    {
        for(j=n-1; j>=i+1; j--)
        {
            if(r[j]>r[j-1])
            {
                swap(q[j],q[j-1]);
                swap(p[j],p[j-1]);
                swap(r[j],r[j-1]);
            }
        }
    }
   /* cout<<endl;
    for(i=0; i<n; i++)
    {
        cout<<r[i]<<" "<<p[i]<<" "<<q[i]<<endl;
    }  */
    for(i=0; i<n; i++)
    {
        if(s>=p[i])
        {
            ans+=q[i];
            s-=p[i];
        }
        else
        {
            ans+=((q[i]/p[i])*s);
            break;
        }
    }
    cout<<"Max Benefit: "<<ans<<endl;
    return 0;
}
