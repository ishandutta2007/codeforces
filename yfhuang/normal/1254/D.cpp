#include <bits/stdc++.h>
 
using namespace std;
 
const int maxn = 150005;
const int mod = 998244353;
const int heavy = 300;
int n, m, q;
vector <int> adj[maxn];
int dad[maxn];
int sz[maxn];
vector <int> pos[maxn];
int tour[2*maxn];
vector <int> heavy_vector;
int weight[2*maxn];
 
int pw(int x, int y) {
    int r = 1;
    while (y) {
        if (y & 1) r = 1LL * r * x % mod;
        x = 1LL * x * x % mod;
        y >>= 1;
    }
    return r;
}
 
void dfs(int u) {
    tour[++m] = u;
    pos[u].push_back(m);
    sz[u] = 1;
    for (auto v: adj[u]) {
        if (v == dad[u]) continue;
        dad[v] = u;
        dfs(v);
        sz[u] += sz[v];
        tour[++m] = u;
        pos[u].push_back(m);
    }
}
 
int fwt[2*maxn];
void upd(int l, int r, int d) {
    for (int p = l; p <= m; p += p & -p) fwt[p] = (fwt[p] + d) % mod;
    ++r;
    for (int p = r; p <= m; p += p & -p) fwt[p] = (fwt[p] + mod - d) % mod;
}
int get(int p) {
    int ret = 0;
    for (; p; p -= p & -p) ret = (ret + fwt[p]) % mod;
    return ret;
}
 
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> q;
    int inv_n = pw(n, mod - 2);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    dfs(1);
    for (int i = 1; i <= n; ++i) if (adj[i].size() >= heavy)
        heavy_vector.push_back(i);
 
    while (q--) {
        int type, v;
        cin >> type >> v;
        if (type == 1) {
            int d;
            cin >> d;
            weight[v] = (weight[v] + d) % mod;
            if (adj[v].size() < heavy) {
                for (auto u: adj[v]) if (u != dad[v])
                    upd(pos[u][0], pos[u].back(), 1LL * d * (n - sz[u]) % mod * inv_n % mod);
                if (v == 1) continue;
                upd(1, pos[v][0] - 1, 1LL * d * sz[v] % mod * inv_n % mod);
                upd(pos[v].back() + 1, m, 1LL * d * sz[v] % mod * inv_n % mod);
            }
        }
        else {
            int ans = (weight[v] + get(pos[v][0])) % mod;
            for (auto u: heavy_vector) {
                if (u == v) continue;
                auto it = lower_bound(pos[u].begin(), pos[u].end(), pos[v][0]);
                if (it == pos[u].begin() || it == pos[u].end())
                    ans = (ans + 1LL * weight[u] * sz[u] % mod * inv_n) % mod;
                else {
                    int p = tour[*(--it) + 1];
                    ans = (ans + 1LL * weight[u] * (n - sz[p]) % mod * inv_n) % mod;
                }
            }
            cout << ans << '\n';
        }
    }
    return 0;
}