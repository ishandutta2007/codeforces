#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 2005;
int n;
int g[maxn][maxn];
ll minw[maxn];

ll dist[maxn];
bool used[maxn];

void dickstra() {
    forn (iter, n) {
        int u = -1;
        forn (i, n) {
            if (used[i])
                continue;
            if (u == -1 || dist[i] < dist[u])
                u = i;
        }
        used[u] = true;
        forn (v, n) {
            ll ndist = dist[u] + g[u][v];
            dist[v] = min(dist[v], ndist);
        }
    }
}

int main() {
    #ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    scanf("%d", &n);
    ll mw = infl;
    forn (u, n) {
        for (int j = 1; j < n - u; ++j) {
            int v = u + j;
            scanf("%d", &g[u][v]);
            g[v][u] = g[u][v];
            mw = min(mw, (ll) g[u][v]);
        }
    }
    forn (u, n) {
        minw[u] = infl;
        forn (v, n) {
            if (u == v)
                continue;
            g[u][v] -= mw;
            minw[u] = min(minw[u], (ll) g[u][v]);
        }
        dist[u] = 2 * minw[u];
    }
    dickstra();
    forn (u, n) {
        ll res = dist[u];
        res += ll(n - 1) * mw;
        cout << res << '\n';
    }
}