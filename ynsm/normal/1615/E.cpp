#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, k;
vector<int> g[N];

int pr[N], col[N];
int tin[N], tout[N], timer;
int pos[N], depth[N];

pii t[N << 2];
int u[N << 2];

ll ans, cnt;

void dfs (int v, int p) {
    tin[v]      = ++timer;
    pos[tin[v]] = v;
    for (auto to : g[v]) {
        if (to == p)
            continue;
        pr[to]    = v;
        depth[to] = depth[v] + 1;
        dfs (to, v);
    }
    tout[v] = timer;
}
void build (int v, int tl, int tr) {
    if (tl == tr) {
        int u = pos[tl];
        t[v]  = { depth[u], u };
        // cerr << v << " " << tl << " " << tr << " " << t[v].f << " " << t[v].s << endl;
        return;
    }
    int tm = (tl + tr) >> 1;
    build (v << 1, tl, tm);
    build (v << 1 | 1, tm + 1, tr);
    t[v] = max (t[v << 1], t[v << 1 | 1]);
    // cerr << v << " " << tl << " " << tr << " " << t[v].f << " " << t[v].s << endl;
}
void upd (int v, int tl, int tr, int l, int r) {
    if (r < tl || tr < l)
        return;
    if (l <= tl && tr <= r) {
        t[v].f--;
        u[v]++;
        return;
    }
    int tm = (tl + tr) >> 1;
    upd (v << 1, tl, tm, l, r);
    upd (v << 1 | 1, tm + 1, tr, l, r);
    t[v] = max (t[v << 1], t[v << 1 | 1]);
    t[v].f -= u[v];
}
void solve () {
    scanf ("%d%d", &n, &k);
    for (int i = 1; i < n; i++) {
        int v, u;
        scanf ("%d%d", &v, &u);
        g[v].pb (u);
        g[u].pb (v);
    }
    dfs (1, 1);
    build (1, 1, n);
    cnt = n;
    ans = -INF;
    /*
    (n - i - cnt) * (i - cnt)
    n * i - n * cnt - i * i + i * cnt - i * cnt + cnt  * cnt
    n * i - n * cnt - i * i + cnt  * cnt
    cnt*cnt - n *cnt
    
    */
    for (int i = 1; i <= k; i++) {
        int v = t[1].s;
        while (v && col[v] == 0) {
            col[v] = 1;
            upd (1, 1, n, tin[v], tout[v]);
            v = pr[v];
            cnt--;
        }
        ll x = n / 2;
        x = min(x, cnt);
        // cerr << i << " " << cnt << " " << 1ll * (n - i - 1 - cnt) * (i + 1 - cnt) << endl; 
        ans = max (ans, 1ll * (n - i - x) * (i - x));
    }
    printf ("%lld\n", ans);
}
int main () {
    int t = 1;
    // scanf("%d", &t);
    while (t--)
        solve ();
}