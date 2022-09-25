#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 105;
const int maxk = 25;
const int ROOT = 0;

const int mod = 1e9 + 7;

void udd(int &a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
}

int mul(ll a, ll b) {
    return (a * b) % mod;
}

vector<int> g[maxn];
int d[maxn][maxk][maxk];
int n, k;

int D[2][maxk][maxk];

void merge(int a[maxk][maxk], int b[maxk][maxk], int d[maxk][maxk]) {
    forn (i1, k + 2)
        forn (j1, k + 2) {
            int aw = a[i1][j1];
            if (aw == 0)
                continue;
            forn (_i2, k + 2)
                forn (_j2, k + 2) {
                    int bw = b[_i2][_j2];
                    if (bw == 0)
                        continue;
                    int i2 = _i2 + 1;
                    int j2 = _j2 - 1;
                    if (_j2 == k + 1)
                        j2 = k + 1;
                    if (j2 < 0)
                        continue;

                    int ni = min(i1, i2);
                    int nj = k + 1;
                    if (j1 <= k && i2 > j1)
                        nj = min(nj, j1);
                    if (j2 <= k && i1 > j2)
                        nj = min(nj, j2);

                    udd(d[ni][nj], mul(aw, bw));
                }
        }
}

void dfs(int u, int prev = -1) {
    for (int v: g[u]) {
        if (v == prev)
            continue;
        dfs(v, u);
    }
    forn (q, 2)
        forn (i, k + 2)
            forn (j, k + 2)
                D[q][i][j] = 0;
    int q = 0;
    D[q][k + 1][k] = 1;
    D[q][0][k + 1] = 1;
    for (int v: g[u]) {
        if (v == prev)
            continue;
        forn (i, k + 2)
            forn (j, k + 2)
                D[q ^ 1][i][j] = 0;
        merge(D[q], d[v], D[q ^ 1]);
        q ^= 1;
    }
    forn (i, k + 2)
        forn (j, k + 2)
            d[u][i][j] = D[q][i][j];
}

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    cin >> n >> k;
    forn (i, n - 1) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(ROOT % n);
    int res = 0;
    forn (i, k + 2) {
        udd(res, d[ROOT % n][i][k + 1]);
        //cerr << "h " << i << ' ' << d[ROOT % n][i][k + 1] << '\n';
    }
    cout << res << '\n';
}