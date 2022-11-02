#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//(double)clock() / CLOCKS_PER_SEC;

vi G[100009];
int ot[100009];
bool vis[100009];

void dfs(int x)
{
    vis[x]=true;
    for(int sz: G[x])
    {
        if(!vis[sz]) dfs(sz);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        int ans=0;
        int n, m;
        cin>>n>>m;
        for(int i=1; i<=n; i++)
        {
            G[i].clear();
            ot[i]=0;
            vis[i]=false;
        }
        for(int i=1; i<=m; i++)
        {
            int x, y;
            cin>>x>>y;
            if(x==y) continue;
            G[x].push_back(y);
            ot[y]++;
            ans++;
        }
        for(int i=1; i<=n; i++)
        {
            if(G[i].size()>0 && ot[i]==0 && !vis[i]) dfs(i);
        }
        for(int i=1; i<=n; i++)
        {
            if(G[i].size()>0 && !vis[i])
            {
                dfs(i);
                ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}