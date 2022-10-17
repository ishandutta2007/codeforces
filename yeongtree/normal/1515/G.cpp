#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#define pii pair<int, int>
#define piii pair<int, pii>
#define pll pair<long long, long long>
#define plll pair<long long, pll>
#define tiii tuple<int, int, int>
#define tiiii tuple<int, int, int, int>
#define ff first
#define ss second
#define ee ss.ff
#define rr ss.ss
#define DEBUG

using namespace std;

vector<pii> gph[202020];
vector<tiii> eg;
bool vst[202020];
int scc[202020];
long long G[202020];
int in[202020];
long long dep[202020];
int scnt = 0, cnt = 0;
vector<int> S;

int dfs(int x, long long d)
{
    vst[x] = true;
    dep[x] = d;
    in[x] = cnt++;
    int ret = in[x];
    S.push_back(x);

    for(auto [y, l] : gph[x])
    {
        if(!vst[y]) ret = min(ret, dfs(y, d + l));
        else if(!scc[y]) ret = min(ret, in[y]);
    }

    if(ret == in[x])
    {
        ++scnt;
        while(S.back() != x) scc[S.back()] = scnt, S.pop_back();
        scc[x] = scnt; S.pop_back();
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    for(int i = 0; i < m; ++i)
    {
        int x, y, v; cin >> x >> y >> v; --x; --y;
        gph[x].push_back({y, v});
        eg.push_back({x, y, v});
    }

    for(int i = 0; i < n; ++i) if(!vst[i]) dfs(i, 0);
    for(auto [x, y, v] : eg)
    {
        if(scc[x] == scc[y])
        {
            if(dep[x] + v - dep[y] != 0) G[scc[x]] = __gcd(G[scc[x]], dep[x] + v - dep[y]);
        }
    }

    int T; cin >> T;
    while(T--)
    {
        int v, s, t; cin >> v >> s >> t; --v;
        if(s == 0) cout << "YES\n";
        else if(G[scc[v]] == 0) cout << "NO\n";
        else if(s % __gcd((long long)t, G[scc[v]]) == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}