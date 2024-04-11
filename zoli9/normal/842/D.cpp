#include <bits/stdc++.h>
using namespace std;
int logn=19;
int dig[21];
int n, m;
bool van[524288];
int xo=0;
int ans;
class pont
{
public:
    pont* nulla;
    pont* egy;
    pont()
    {
        nulla=NULL;
        egy=NULL;
    }
    void beszur(int ind)
    {
        if(ind==-1) return;
        if(dig[ind]==0)
        {
            if(nulla==NULL) nulla=new pont();
            nulla->beszur(ind-1);
        }
        else
        {
            if(egy==NULL) egy=new pont();
            egy->beszur(ind-1);
        }
    }
    void calc(int ind)
    {
        if(ind==-1) return;
        if(dig[ind]==0)
        {
            if(nulla==NULL)
            {
                ans+=(1<<(ind));
                egy->calc(ind-1);
            }
            else
            {
                nulla->calc(ind-1);
            }
        }
        else
        {
            if(egy==NULL)
            {
                ans+=(1<<(ind));
                nulla->calc(ind-1);
            }
            else
            {
                egy->calc(ind-1);
            }
        }
    }
};
pont root;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        int szam;
        cin>>szam;
        van[szam]=true;
    }
    for(int i=0; i<524288; i++)
    {
        if(!van[i])
        {
            int u=i;
            for(int o=0; o<=18; o++)
            {
                dig[o]=u%2;
                u/=2;
            }
            root.beszur(18);
        }
    }
    for(int i=1; i<=m; i++)
    {
        int szam;
        cin>>szam;
        xo^=szam;
        int xoz=xo;
        for(int o=0; o<=18; o++)
        {
            dig[o]=xoz%2;
            xoz/=2;
        }
        ans=0;
        root.calc(18);
        cout<<ans<<endl;
    }
    return 0;
}