#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
#define pii pair<int, int>
#define piii pair<pii, int>
#define pll pair<long long, long long>
#define ff first
#define ss second

using namespace std;

struct edge
{
    int s, e;
    long long x;
};
bool operator< (const edge &x, const edge &y) { return x.x < y.x; }

int par[101010];
int fnd(int x) { return (par[x] == x ? x : par[x] = fnd(par[x])); }
bool uni(int x, int y)
{
    x = fnd(x), y = fnd(y);
    if(x == y) return false;
    par[x] = y; return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, T; cin >> n >> m >> k >> T;
    vector<pii> gph[n];
    edge eg[m];
    for(int i = 0; i < m; ++i)
    {
        int x, y, p; cin >> x >> y >> p; --x; --y;
        gph[x].push_back({y, p});
        gph[y].push_back({x, p});
        eg[i] = {x, y, p};
    }

    priority_queue<pll, vector<pll>, greater<pll>> PQ;
    for(int i = 0; i < k; ++i) PQ.push({0, i});
    long long dis[n]; for(auto &i : dis) i = -1;
    while(!PQ.empty())
    {
        pll tmp = PQ.top(); PQ.pop();
        if(dis[tmp.ss] != -1) continue;
        dis[tmp.ss] = tmp.ff;
        for(auto x : gph[tmp.ss]) PQ.push({tmp.ff + x.ss, x.ff});
    }

    for(auto &i : eg) i.x += dis[i.s] + dis[i.e];
    sort(eg, eg + m);

    vector<pll> spt[n];
    for(int i = 0; i < n; ++i) par[i] = i;
    for(auto &i : eg)
        if(uni(i.s, i.e))
    {
        spt[i.s].push_back({i.e, i.x});
        spt[i.e].push_back({i.s, i.x});
    }

    pll par[n]; par[0] = {0, 0};
    int dep[n]; dep[0] = 0;
    queue<int> Q; Q.push(0);
    while(!Q.empty())
    {
        int tmp = Q.front(); Q.pop();
        for(auto &i : spt[tmp])
            if(i.ff != par[tmp].ff)
        {
            par[i.ff] = {tmp, i.ss};
            dep[i.ff] = dep[tmp] + 1;
            Q.push(i.ff);
        }
    }

    pll spr[21][n];
    for(int j = 0; j < n; ++j) spr[0][j] = par[j];
    for(int i = 1; i <= 20; ++i)
        for(int j = 0; j < n; ++j)
    spr[i][j] = { spr[i - 1][spr[i - 1][j].ff].ff, max(spr[i - 1][j].ss, spr[i - 1][spr[i - 1][j].ff].ss) };

    while(T--)
    {
        int x, y; cin >> x >> y; --x; --y;
        long long ans = -1;
        if(dep[x] > dep[y]) swap(x, y);
        for(int i = 20; i >= 0; --i) if(dep[x] + (1 << i) <= dep[y]) ans = max(ans, spr[i][y].ss), y = spr[i][y].ff;
        for(int i = 20; i >= 0; --i) if(spr[i][x].ff != spr[i][y].ff)
            ans = max(max(ans, spr[i][x].ss), spr[i][y].ss), x = spr[i][x].ff, y = spr[i][y].ff;
        if(x != y) ans = max(max(ans, par[x].ss), par[y].ss);
        cout << ans << '\n';
    }

    return 0;
}