#include <bits/stdc++.h>
using namespace std;
int n, q;
int p[5009];
int kezd[5009];
int veg[5009];
int db1[5009];
int db2[5009];
int ans=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>q;
    for(int i=1; i<=q; i++)
    {
        cin>>kezd[i]>>veg[i];
        for(int j=kezd[i]; j<=veg[i]; j++)
        {
            p[j]++;
        }
    }
    for(int i=1; i<=n; i++)
    {
        if(p[i]>0)
        {
            ans++;
        }
        if(p[i]==1)
        {
            db1[i]=db1[i-1]+1;
        }
        else
        {
            db1[i]=db1[i-1];
        }
        if(p[i]==2)
        {
            db2[i]=db2[i-1]+1;
        }
        else
        {
            db2[i]=db2[i-1];
        }
    }
    int maxans=0;
    for(int i=1; i<=q; i++)
    {
        for(int j=i+1; j<=q; j++)
        {
            int cans=0;
            if(veg[j]<kezd[i] || veg[i]<kezd[j])
            {
                cans=ans-(db1[veg[i]]-db1[kezd[i]-1])-(db1[veg[j]]-db1[kezd[j]-1]);
            }
            else
            {
                int mink=min(kezd[i], kezd[j]);
                int minv=max(kezd[i], kezd[j]);
                int maxk=min(veg[i], veg[j]);
                int maxv=max(veg[i], veg[j]);
                cans=ans-(db1[minv]-db1[mink-1])-(db1[maxv]-db1[maxk-1]);

                cans=cans-(db1[maxk-1]-db1[minv])-(db2[maxk]-db2[minv-1]);
            }
            maxans=max(maxans, cans);
        }
    }
    cout<<maxans<<endl;
    return 0;
}