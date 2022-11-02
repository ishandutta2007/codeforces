#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;
int n, m;
int test;
vi G[500009];
vi ns;
ll cost[500009];
bool rendez(int x, int y)
{
    if(G[x].size()==G[y].size())
    {
        return G[x]<G[y];
    }
    return G[x].size()<G[y].size();
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>test;
    for(int tt=1; tt<=test; tt++)
    {
        cin>>n>>m;
        for(int i=1; i<=n; i++)
        {
            cin>>cost[i];
            G[i].clear();
        }
        ns.clear();
        for(int i=1; i<=m; i++)
        {
            int a, b;
            cin>>a>>b;
            G[b].push_back(a);
        }
        for(int i=1; i<=n; i++)
        {
            if(G[i].size()>0)
            {
                sort(G[i].begin(), G[i].end());
                ns.push_back(i);
            }
        }
        sort(ns.begin(), ns.end(), rendez);
        ll cur=cost[ns[0]];
        ll ans=-1;
        for(int i=1; i<ns.size(); i++)
        {
            if(G[ns[i]]!=G[ns[i-1]])
            {
                if(ans==-1) ans=cur;
                else ans=__gcd(ans, cur);
                cur=0;
            }
            cur+=cost[ns[i]];
        }
        if(ans==-1) ans=cur;
        else ans=__gcd(ans, cur);
        cout<<ans<<'\n';
    }

    return 0;
}