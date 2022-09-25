#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 1002;
const int maxm = 200200;
int ua[maxm], ub[maxm];
int d[maxn][maxn];

int qr[maxm], qu[maxm], qv[maxm];
int qans[maxm];
vector<int> qid[maxm];

int main() {
    #ifdef LOCAL
    assert(freopen("e.in", "r", stdin));
    #else
    #endif
    int n, m, q;
    cin >> n >> m >> q;
    forn (i, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        ua[i] = u, ub[i] = v;
    }
    forn (i, q) {
        int l, r, u, v;
        scanf("%d%d%d%d", &l, &r, &u, &v);
        --u, --v, --l, --r;
        qid[l].push_back(i);
        qu[i] = u, qv[i] = v, qr[i] = r;
    }
    forn (i, n)
        forn (j, n) {
            d[i][j] = inf;
            if (i == j)
                d[i][j] = -1;
        }
    for (int i = m - 1; i >= 0; --i) {
        int u = ua[i], v = ub[i];
        forn (j, n)
            d[u][j] = d[v][j] = min(d[u][j], d[v][j]);
        d[u][v] = d[v][u] = i;
        for (auto id: qid[i]) {
            qans[id] = d[qu[id]][qv[id]] <= qr[id];
        }
    }
    forn (i, q)
        cout << (qans[i] ? "Yes\n" : "No\n");
}