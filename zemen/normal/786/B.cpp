#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int base = 1 << 17;
const int sh = 2 * base;
vector<pair<int, int>> g[base * 3];

int TO, W, REV;
void put(int l, int r, int v = 1, int cl = 0, int cr = base) {
    if (l <= cl && cr <= r) {
        if (!REV) {
            g[TO + base].emplace_back(v, W);
        } else {
            int u = v;
            if (v < base)
                u += sh;

            g[u].emplace_back(TO + base, W);
        }
        return;
    }
    if (r <= cl || cr <= l)
        return;
    int cc = (cl + cr) / 2;
    put(l, r, v * 2, cl, cc);
    put(l, r, v * 2 + 1, cc, cr);
}

ll dist[base * 3];
typedef pair<ll, int> pli;
priority_queue<pli, vector<pli>, greater<pli>> q;
void dickstra(int s) {
    forn (i, base * 3)
        dist[i] = infl;
    dist[s] = 0;
    q.emplace(dist[s], s);
    while (!q.empty()) {
        int u;
        ll cdist;
        tie(cdist, u) = q.top();
        q.pop();
        if (cdist != dist[u])
            continue;

        for (auto e: g[u]) {
            ll w = e.second;
            int v = e.first;
            ll ndist = dist[u] + w;
            if (ndist < dist[v]) {
                dist[v] = ndist;
                q.emplace(dist[v], v);
            }
        }
    }
}

int main() {
    #ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
    #else
    #endif
    int n, q, s;
    cin >> n >> q >> s;
    --s;
    for (int i = 1; i < base; ++i) {
        g[i].emplace_back(i * 2, 0);
        g[i].emplace_back(i * 2 + 1, 0);
        if (i * 2 >= base) {
            g[i * 2].emplace_back(i + sh, 0);
            g[i * 2 + 1].emplace_back(i + sh, 0);
        } else {
            g[i * 2 + sh].emplace_back(i + sh, 0);
            g[i * 2 + 1 + sh].emplace_back(i + sh, 0);
        }
    }

    forn (i, q) {
        int t, u, v, l, r, w;
        scanf("%d", &t);
        if (t == 1) {
            scanf("%d%d%d", &u, &v, &w);
            --u, --v;
            g[u + base].emplace_back(v + base, w);
        } else {
            scanf("%d%d%d%d", &u, &l, &r, &w);
            --l, --u;
            W = w, TO = u, REV = t == 3;
            put(l, r);
        }
    }

    dickstra(s + base);
    forn (i, n) {
        int id = i + base;
        if (dist[id] == infl)
            dist[id] = -1;
        cout << dist[id] << ' ';
    }
    cout << '\n';
}