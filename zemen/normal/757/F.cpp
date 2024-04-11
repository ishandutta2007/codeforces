#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxn = 200200;
vector<pair<int, int>> g[maxn];
vector<int> G[maxn];
vector<int> rg[maxn];
int n;

ll dist[maxn];
typedef pair<ll, int> pli;
priority_queue<pli, vector<pli>, greater<pli>> o;
void dickstra(int u) {
    forn (i, n)
        dist[i] = infl;
    dist[u] = 0;
    o.emplace(dist[u], u);
    while (!o.empty()) {
        int u;
        ll cdist;
        tie(cdist, u) = o.top();
        o.pop();
        if (dist[u] != cdist)
            continue;
        for (auto p: g[u]) {
            int v;
            ll w;
            tie(v, w) = p;
            ll ndist = dist[u] + w;
            if (ndist >= dist[v])
                continue;
            dist[v] = ndist;
            o.emplace(dist[v], v);
        }
    }
    forn (u, n) {
        if (dist[u] == infl)
            continue;
        for (auto p: g[u]) {
            int v;
            ll w;
            tie(v, w) = p;
            if (dist[v] == dist[u] + w) {
                G[u].push_back(v);
                rg[v].push_back(u);
                //cerr << "edge " << u + 1 << ' ' << v + 1 << '\n';
            }
        }
    }
}

bool used[maxn];
vector<int> ord;

void dfs(int u) {
    used[u] = true;
    for (int v: G[u]) {
        if (used[v])
            continue;
        dfs(v);
    }
    ord.push_back(u);
}

int col[maxn];
int ccnt[maxn];

int main() {
    #ifdef LOCAL
    assert(freopen("f.in", "r", stdin));
    #else
    #endif
    int m, s;
    cin >> n >> m >> s;
    --s;
    forn (i, m) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        --u, --v;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    dickstra(s);
    dfs(s);
    ord.pop_back();
    reverse(ord.begin(), ord.end());
    int cc = 0;
    col[s] = -1;
    int res = 0;
    for (int u: ord) {
        //cerr << u + 1 << '\n';
        int cur = -1;
        for (int v: rg[u]) {
            if (v == s) {
                cur = cc++;
                break;
            }
            if (cur == -1)
                cur = col[v];
            if (cur != col[v]) {
                cur = cc++;
                break;
            }
        }
        if (cur == -1)
            cur = cc++;
        col[u] = cur;
        ccnt[cur]++;
        res = max(res, ccnt[cur]);
    }
    //forn (i, n)
        //cerr << col[i] << ' ';
    //cerr << '\n';
    cout << res << '\n';
}