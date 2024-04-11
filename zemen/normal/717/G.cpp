#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int maxm = 105;
string s;
string t[maxm];
int p[maxm];

const int maxn = 505;
const int maxN = maxn;

struct Edge {
    int to, c, f, cost;

    Edge(int to, int c, int cost): to(to), c(c), f(0), cost(cost) {}
};

namespace MinCost {
    int N, S, T;
    vector<int> g[maxN];
    vector<Edge> edge;
    int total;

    void addEdge(int u, int v, int c, int cost) {
        g[u].push_back(sz(edge));
        edge.emplace_back(v, c, cost);
        g[v].push_back(sz(edge));
        edge.emplace_back(u, 0, -cost);
    }

    bool inq[maxN];
    int dist[maxN];
    int from[maxN];
    bool fb() {
        forn (i, N)
            inq[i] = false, dist[i] = inf;
        queue<int> o;
        dist[S] = 0;
        o.push(S);
        inq[S] = true;
        while (!o.empty()) {
            int u = o.front();
            o.pop();
            inq[u] = false;

            for (int id: g[u]) {
                if (edge[id].c == edge[id].f)
                    continue;
                int v = edge[id].to;
                int ndist = dist[u] + edge[id].cost;
                if (ndist >= dist[v])
                    continue;
                dist[v] = ndist;
                from[v] = id;
                if (!inq[v]) {
                    inq[v] = true;
                    o.push(v);
                }
            }
        }
        return dist[T] != inf;
    }

    void push() {
        assert(fb());
        int u = T;
        while (u != S) {
            int id = from[u];
            total += edge[id].cost;
            edge[id].f++;
            edge[id ^ 1].f--;
            u = edge[id ^ 1].to;
        }
    }
}

int main() {
    #ifdef LOCAL
    assert(freopen("g.in", "r", stdin));
    #else
    #endif
    int n, m;
    cin >> n >> s >> m;
    forn (i, m)
        cin >> t[i] >> p[i];
    int x;
    cin >> x;
    MinCost::N = n + 1;
    MinCost::S = 0;
    MinCost::T = n;
    forn (i, n)
        MinCost::addEdge(i, i + 1, x, 0);
    forn (i, m) {
        for (int j = 0; j + sz(t[i]) <= n; ++j) {
            bool ok = true;
            forn (k, sz(t[i]))
                if (s[j + k] != t[i][k])
                    ok = false, k = inf;
            if (!ok)
                continue;
            MinCost::addEdge(j, j + sz(t[i]), 1, -p[i]);
            //cerr << j << ' ' << j + sz(t[i]) << ' ' << p[i] << '\n';
        }
    }
    forn (i, x)
        MinCost::push();
    cout << -MinCost::total << '\n';
}