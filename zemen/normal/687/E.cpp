#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 5005;
vector<int> g[maxn];
vector<int> gr[maxn];
int col[maxn];
bool used[maxn];
bool term[maxn];
int COL;
int n;
vector<int> nodes[maxn];

vector<int> ord;
void dfs1(int u) {
    used[u] = true;
    for (int v: g[u])
        if (!used[v])
            dfs1(v);
    ord.push_back(u);
}

void dfs2(int u) {
    used[u] = false;
    for (int v: gr[u]) {
        if (!used[v])
            continue;
        dfs2(v);
    }
    col[u] = COL;
    nodes[COL].push_back(u);
}

int o[maxn];
int d[maxn];
int bfs(int S) {
    fill(d, d + n, maxn);
    int q = 0;
    o[q++] = S;
    d[S] = 0;
    for (int ii = 0; ii < q; ++ii) {
        int u = o[ii];
        for (int v: g[u]) {
            if (v == S)
                return d[u] + 1;
            if (d[v] != maxn)
                continue;
            d[v] = d[u] + 1;
            o[q++] = v;
        }
    }
    //cerr << "bfs " << S + 1 << " fail\n";
    return maxn;
}

int solveCol(int col) {
    int best = maxn;
    for (auto u: nodes[col]) {
        if (g[u].size() == 0)
            return 0;
        int cres = bfs(u);
        best = min(best, cres);
    }
    return best;
}

int main() {
    #ifdef LOCAL
    assert(freopen("e.in", "r", stdin));
    #else
    #endif
    int m;
    cin >> n >> m;
    forn (i, m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        gr[v].push_back(u);
    }
    forn (i, n)
        if (!used[i])
            dfs1(i);
    reverse(ord.begin(), ord.end());
    for (auto u: ord) {
        if (used[u]) {
            dfs2(u);
            ++COL;
        }
    }
    //forn (i, n)
        //cerr << col[i] << ' ';
    //cerr << '\n';
    forn (i, COL)
        term[i] = true;
    forn (u, n) {
        for (int v: g[u]) {
            if (col[u] != col[v])
                term[col[u]] = false;
        }
    }
    ll res = n;
    forn (i, COL)
        if (term[i]) {
            ll c = solveCol(i);
            if (c > 0) {
                res += 998 * c + 1;
            }
        }
    cout << res << '\n';
}