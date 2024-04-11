#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int test;
vi G[500009];
vll W[500009];
ll dp0[500009];
ll dp1[500009];
bool bejar[500009];
int n, k;

void dfs(int x)
{
    bejar[x]=true;
    vll crt;
    dp0[x]=0;
    dp1[x]=0;
    for(int i=0; i<G[x].size(); i++)
    {
        int sz=G[x][i];
        if(bejar[sz]) continue;
        ll ww=W[x][i];
        dfs(sz);
        dp0[x]+=dp0[sz];
        if(ww+dp1[sz]-dp0[sz]>0) crt.push_back(ww+dp1[sz]-dp0[sz]);
    }
    sort(crt.begin(), crt.end());
    reverse(crt.begin(), crt.end());
    dp1[x]=dp0[x];
    for(int i=0; i<min(k, (int)(crt.size())); i++)
    {
        if(i!=k-1) dp1[x]+=crt[i];
        dp0[x]+=crt[i];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n>>k;
        for(int i=1; i<=n; i++)
        {
            bejar[i]=false;
            G[i].clear();
            W[i].clear();
        }
        for(int i=1; i<n; i++)
        {
            int a, b;
            ll ww;
            cin>>a>>b>>ww;
            G[a].push_back(b);
            G[b].push_back(a);
            W[a].push_back(ww);
            W[b].push_back(ww);
        }
        dfs(1);
        cout<<dp0[1]<<'\n';
    }
    return 0;
}