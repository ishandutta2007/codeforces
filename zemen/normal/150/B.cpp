#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

struct DSU {
    vector<int> col, rk;

    DSU(int n): col(n), rk(n, 1) {
        iota(col.begin(), col.end(), 0);
    }

    int get(int u) {
        if (u == col[u])
            return u;
        return col[u] = get(col[u]);
    }

    void join(int u, int v) {
        u = get(u), v = get(v);
        if (u == v)
            return;
        if (rk[u] > rk[v])
            swap(u, v);
        rk[v] += rk[u];
        col[u] = v;
    }
};

int main() {
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    int n, m, k;
    cin >> n >> m >> k;
    DSU dsu(n);
    for (int i = 0; i + k <= n; ++i) {
        forn (j, k)
            dsu.join(i + j, i + k - j - 1);
    }
    ll res = 1;
    const ll mod = 1e9 + 7;
    forn (i, n) {
        if (dsu.col[i] == i) {
            res *= m;
            res %= mod;
        }
    }
    cout << res << '\n';
}