#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 210;
const int alpha = 30;
int cost[maxn];

const int root = 1;
const int blank = 2;
int nodes = 3;
int to[maxn][alpha];
int to2[maxn][alpha];
int by[maxn];
int par[maxn];
int lnk[maxn];

int go(int u, int c);

int getLnk(int u) {
    assert(u);
    if (lnk[u])
        return lnk[u];
    return lnk[u] = go(getLnk(par[u]), by[u]);
}

int go(int u, int c) {
    assert(u);
    if (to[u][c])
        return to[u][c];
    if (to2[u][c])
        return to2[u][c];
    return to2[u][c] = go(getLnk(u), c);
}

struct M {
    ll a[maxn][maxn];

    M() {
        forn (i, maxn)
            forn (j, maxn)
                a[i][j] = 0;
    }

    M operator*(const M &m) const {
        M res;
        forn (i, maxn)
            forn (j, maxn)
                if (i != j)
                    res.a[i][j] = -infl;
        forn (i, maxn)
            forn (j, maxn)
                forn (k, maxn)
                    res.a[i][j] = max(res.a[i][j], a[i][k] + m.a[k][j]);
        return res;
    }
};

M base[60];

int ncost[maxn];
bool used[maxn];
void dfs(int u) {
    if (u == blank)
        return;
    if (!used[getLnk(u)])
        dfs(getLnk(u));
    used[u] = true;
    ncost[u] += ncost[getLnk(u)];
}

M pw(ll deg) {
    int id = 0;
    M res;
    forn (i, maxn)
        forn (j, maxn)
            if (i != j)
                res.a[i][j] = -infl;
    while (deg) {
        if (deg % 2)
            res = res * base[id];
        deg /= 2;
        ++id;
    }
    return res;
}

int main() {
    #ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    forn (i, alpha)
        to[blank][i] = root;
    lnk[root] = blank;

    int n;
    ll l;
    cin >> n >> l;
    forn (i, n)
        cin >> cost[i];
    forn (i, n) {
        string s;
        cin >> s;
        int u = root;
        for (auto ch: s) {
            int c = ch - 'a';
            if (!to[u][c]) {
                to[u][c] = nodes++;
                by[nodes - 1] = c;
                par[nodes - 1] = u;
            }
            u = to[u][c];
        }
        ncost[u] += cost[i];
        //cerr << "init " << u << ' ' << cost[i] << '\n';
    }
    for (int i = 1; i < nodes; ++i)
        if (i != blank && !used[i])
            dfs(i);

    forn (i, maxn)
        forn (j, maxn)
            base[0].a[i][j] = -infl;
    for (int i = 1; i < nodes; ++i) {
        if (i == blank)
            continue;
        forn (c, alpha) {
            base[0].a[i][go(i, c)] = ncost[go(i, c)];
        }
    }
    //forn (i, nodes)
        //if (i != blank && i)
            //cerr << i << ' ' << ncost[i] << '\n';
    forn (i, 55)
        base[i + 1] = base[i] * base[i];
    M mm = pw(l);
    ll ans = 0;
    forn (i, maxn)
        ans = max(ans, mm.a[root][i]);
    cout << ans << '\n';
}