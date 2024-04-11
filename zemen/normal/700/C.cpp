#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

struct Edge {
    int to, cost, id;
};

const int maxn = 1005;
const int maxm = 30005;
vector<Edge> g[maxn];
int ecost[maxm];
bool used[maxn];

vector<int> path;
bool dfs1(int u, int to) {
    used[u] = true;
    if (u == to)
        return true;
    for (const auto &e: g[u]) {
        if (used[e.to])
            continue;
        if (dfs1(e.to, to)) {
            path.push_back(e.id);
            return true;
        }
    }
    return false;
}

bool uin(int &a, int b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

int in[maxn];
int up[maxn];
int timer;
bool isBridge[maxm];

int BAD_ID;
vector<int> path2;
bool dfs2(int u, int to, int fromId = -1) {
    used[u] = true;
    in[u] = up[u] = timer++;

    bool ret = (u == to);
    for (const auto &e: g[u]) {
        if (BAD_ID == e.id || e.id == fromId)
            continue;
        if (used[e.to]) {
            up[u] = min(up[u], in[e.to]);
        } else {
            bool found = dfs2(e.to, to, e.id);
            isBridge[e.id] = (up[e.to] == in[e.to]);
            up[u] = min(up[u], up[e.to]);
            if (found) {
                path2.push_back(e.id);
                ret = true;
            }
        }
    }
    return ret;
}

int main() {
    #ifdef LOCAL
    assert(freopen("c.in", "r", stdin));
    #else
    #endif
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    --s, --t;
    forn (i, m) {
        int u, v, c;
        scanf("%d%d%d", &u, &v, &c);
        --u, --v;
        g[u].push_back(Edge{v, c, i});
        g[v].push_back(Edge{u, c, i});
        ecost[i] = c;
    }
    dfs1(s, t);
    if (path.empty()) {
        cout << 0 << '\n' << 0 << '\n' << '\n';
        return 0;
    }
    vector<int> best;
    int bestCost = 2 * inf;
    for (int bad: path) {
        BAD_ID = bad;
        path2.clear();
        timer = 0;
        memset(used, 0, sizeof(used));
        memset(isBridge, 0, sizeof(isBridge));
        if (!dfs2(s, t)) {
            if (uin(bestCost, ecost[bad]))
                best = {bad};
            continue;
        }
        for (int bad2: path2) {
            if (!isBridge[bad2])
                continue;
            if (uin(bestCost, ecost[bad] + ecost[bad2]))
                best = {bad, bad2};
        }
    }
    if (bestCost == 2 * inf) {
        cout << -1 << '\n';
        return 0;
    }

    cout << bestCost << '\n';
    cout << best.size() << '\n';
    for (int x: best)
        cout << x + 1 << ' ';
    cout << '\n';
}