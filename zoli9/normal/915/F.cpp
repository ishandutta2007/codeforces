#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
int n;
vector<int> G[1000009];
long long a[1000009];
int apa[1000009];
long long meret[1000009];
vector<pair<long long, int> > parok;
int holvan(int x)
{
    if(apa[x]==x) return x;
    return apa[x]=holvan(apa[x]);
}
void unio(int x, int y)
{
    if(meret[y]<meret[x])
    {
        apa[y]=x;
        meret[x]+=meret[y];
    }
    else
    {
        apa[x]=y;
        meret[y]+=meret[x];
    }
}
long long maxi, mini;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        parok.push_back({a[i], i});
        apa[i]=i;
        meret[i]=1;
    }
    for(int i=1; i<n; i++)
    {
        int aa, bb;
        cin>>aa>>bb;
        G[aa].push_back(bb);
        G[bb].push_back(aa);
    }
    sort(parok.begin(), parok.end());
    for(int i=0; i<parok.size(); i++)
    {
        int akt=parok[i].S;
        for(int sz: G[akt])
        {
            int h1=holvan(akt);
            int h2=holvan(sz);
            if(a[akt]>=a[sz] && h1!=h2)
            {
                maxi+=(a[akt]*meret[h1]*meret[h2]);
                unio(h1, h2);
            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        apa[i]=i;
        meret[i]=1;
    }
    reverse(parok.begin(), parok.end());
    for(int i=0; i<parok.size(); i++)
    {
        int akt=parok[i].S;
        for(int sz: G[akt])
        {
            int h1=holvan(akt);
            int h2=holvan(sz);
            if(a[akt]<=a[sz] && h1!=h2)
            {
                mini+=(a[akt]*meret[h1]*meret[h2]);
                unio(h1, h2);
            }
        }
    }
    cout<<maxi-mini<<endl;
    return 0;
}