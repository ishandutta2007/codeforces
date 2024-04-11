#include <bits/stdc++.h>
 
using namespace std;
 
#define S second
#define F first
 
typedef long long ll;
typedef long double ld;
 
const int maxn = 1e6+10;
const int mod = 1e9+7;
const int inf = 1e9+10;
const int N = 80010;
 
int n, m;
vector<int> g[N];
 
int bfs(int s)
{
    int dis[N], mark[N], par[N];
    memset(mark, 0, sizeof mark);
    queue<int> q;
 
    dis[s] = 0;
    mark[s] = 1;
    q.push(s);
    bool X = 0;
    int ans = inf;
    while(q.size())
    {
        int v = q.front();
        q.pop();
        for(auto u : g[v])
            if(!mark[u])
            {
                mark[u] = 1;
                dis[u] = dis[v] + 1;
                par[u] = v;
                q.push(u);
            }
            else
                if(u != par[v] && !X)
                {
                    ans = min(ans, dis[v]+dis[u]+1);
                    X = 1;
                }
    }
    return ans;
}
 
bool av[maxn];
vector<int> pr[maxn];
int mp[maxn], a[maxn];
 
int num(int x, int p)
{
    int cnt = 0;
    int X = x;
    while(x % p == 0)
    {
        cnt++;
        x /= p;
    }
    if(!(cnt&1)) return x;
    return X;
}
 
set<pair<int,int>> edge;
 
signed main()
{
    //ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
 
    cin>> n;
 
    int last = 0;
    for(int i = 2; i < maxn; i++)
        if(!av[i])
        {
            last++; mp[i] = last;
            for(int j = 2*i; j < maxn; j += i)
            {
                pr[j].push_back(i);
                av[j] = 1;
            }
            pr[i].push_back(i);
        }
    last++;
 
    bool T = 0;
    for(int i = 1, x; i <= n; i++)
    {
        cin>> x;
        for(auto p : pr[x])
            x = num(x,p);
 
        if(pr[x].size() == 2)
        {
            if(edge.count({mp[pr[x][1]], mp[pr[x][0]]}))
                T = 1;
 
            g[mp[pr[x][0]]].push_back(mp[pr[x][1]]);
            g[mp[pr[x][1]]].push_back(mp[pr[x][0]]);
 
            edge.insert({mp[pr[x][1]], mp[pr[x][0]]});
            edge.insert({mp[pr[x][0]], mp[pr[x][1]]});
        }
 
        if(pr[x].size() == 1)
        {
            if(edge.count({last,mp[pr[x][0]]}))
                T = 1;
 
            g[last].push_back(mp[pr[x][0]]);
            g[mp[pr[x][0]]].push_back(last);
 
            edge.insert({last,mp[pr[x][0]]});
        }
 
        if(x == 1)
            return cout<< 1, 0;
    }
 
    if(T) return cout<< 2, 0;
 
    int cyc = inf;
    for(int i = 1; i <= 1010; i++)
        cyc = min(cyc, bfs(mp[i]));
    cyc = min(cyc,bfs(last));
 
    if(cyc == inf) cout<< -1;
    else cout<< cyc;
}