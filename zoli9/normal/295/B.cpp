#include <bits/stdc++.h>
using namespace std;
long long n;
long long t[509][509];
long long sor[509];
long long d[509][509];
long long valasz[509];
bool volt[509];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>t[i][j];
            d[i][j]=-1;
            if(i==j) d[i][j]=0;
        }
    }
    for(int i=1; i<=n; i++)
    {
        cin>>sor[i];
    }
    for(int ind=n; ind>=1; ind--)
    {
        int akt=sor[ind];
        for(int i=1; i<=n; i++)
        {
            if(d[akt][i]==-1 || t[akt][i]<d[akt][i]) d[akt][i]=t[akt][i];
            if(d[i][akt]==-1 || t[i][akt]<d[i][akt]) d[i][akt]=t[i][akt];
        }
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(d[i][j]==-1)
                {
                    if(d[i][akt]>=0 && d[akt][j]>=0)
                    {
                        d[i][j]=d[i][akt]+d[akt][j];
                    }
                }
                else if(d[i][akt]>=0 && d[akt][j]>=0)
                {
                    d[i][j]=min(d[i][j], d[i][akt]+d[akt][j]);
                }
            }
        }
        for(int i=n; i>=ind; i--)
        {
            for(int j=n; j>=ind; j--)
            {
                if(i==j) continue;
                valasz[ind]+=d[sor[i]][sor[j]];
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        cout<<valasz[i]<<" ";
    }
    return 0;
}