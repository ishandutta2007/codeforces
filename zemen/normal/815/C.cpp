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

const int maxn = 5005;
int B;
int c[maxn];
int d[maxn];
vector<int> g[maxn];
int n;

int kc[maxn][maxn];
int kd[maxn][maxn];
int cnt[maxn];
int buf[2][maxn];

void merge(int *a, int *b, int *to, int c1, int c2) {
    forn (i, c1 + c2 + 1)
        to[i] = inf;
    forn (i, c1 + 1)
        forn (j, c2 + 1)
            to[i + j] = min(to[i + j], a[i] + b[j]);
}

void dfs(int u) {
    for (int v: g[u])
        dfs(v);
    int q = 0;
    forn (i, n + 1)
        buf[q][i] = inf;

    cnt[u] = 1;
    buf[q][0] = 0;
    buf[q][1] = c[u];
    for (int v: g[u]) {
        merge(buf[q], kc[v], buf[q ^ 1], cnt[u], cnt[v]);
        q ^= 1;
        cnt[u] += cnt[v];
    }
    forn (i, n + 1)
        kc[u][i] = buf[q][i];

    q = 0;
    forn (i, n + 1)
        buf[q][i] = inf;
    cnt[u] = 1;

    buf[q][1] = c[u] - d[u];
    for (int v: g[u]) {
        merge(buf[q], kd[v], buf[q ^ 1], cnt[u], cnt[v]);
        q ^= 1;
        cnt[u] += cnt[v];
    }
    forn (i, n + 1)
        kd[u][i] = min(buf[q][i], kc[u][i]);
}

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    cin >> n >> B;
    forn (i, n) {
        cin >> c[i] >> d[i];
        if (i) {
            int x;
            cin >> x;
            --x;
            g[x].push_back(i);
        }
    }
    dfs(0);
    int p = n;
    while (kd[0][p] > B)
        --p;
    cout << p << '\n';
}