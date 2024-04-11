#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

namespace MinCost {
const int infc = 1e9;

struct Edge {
    int to;
    int c, f, cost;

    Edge(int to, int c, int cost): to(to), c(c), f(0), cost(cost)
    {  }
};

int N, S, T;
int totalFlow;
int totalCost;
const int maxn = 105;
vector<Edge> edge;
vector<int> g[maxn];

void addEdge(int u, int v, int c, int cost) {
    if (c == 0)
        return;
    //cerr << u << ' ' << v << ' ' << c << ' ' << cost << '\n';
    g[u].push_back(edge.size());
    edge.emplace_back(v, c, cost);
    g[v].push_back(edge.size());
    edge.emplace_back(u, 0, -cost);
}

//min-cost-circulation
int d[maxn][maxn];
int dfrom[maxn][maxn];
int level[maxn];
void circulation() {
    while (true) {
        int q = 0;
        fill(d[0], d[0] + N, 0);
        forn (iter, N) {
            fill(d[iter + 1], d[iter + 1] + N, infc);
            forn (u, N)
                for (int e: g[u]) {
                    if (edge[e].c == edge[e].f)
                        continue;
                    int v = edge[e].to;
                    int ndist = d[iter][u] + edge[e].cost;
                    if (ndist >= d[iter + 1][v])
                        continue;
                    d[iter + 1][v] = ndist;
                    dfrom[iter + 1][v] = e;
                }
            q ^= 1;
        }
        int w = -1;
        ld mindmax = 1e18;
        forn (u, N) {
            ld dmax = -1e18;
            forn (iter, N)
                dmax = max(dmax,
                    (d[N][u] - d[iter][u]) / ld(N - iter));
            if (mindmax > dmax)
                mindmax = dmax, w = u;
        }
        if (mindmax >= 0)
            break;
        fill(level, level + N, -1);
        int k = N;
        while (level[w] == -1) {
            level[w] = k;
            w = edge[dfrom[k--][w] ^ 1].to;
        }
        int k2 = level[w];
        int delta = infc;
        while (k2 > k) {
            int e = dfrom[k2--][w];
            delta = min(delta, edge[e].c - edge[e].f);
            w = edge[e ^ 1].to;
        }
        k2 = level[w];
        while (k2 > k) {
            int e = dfrom[k2--][w];
            totalCost += edge[e].cost * delta;
            edge[e].f += delta;
            edge[e ^ 1].f -= delta;
            w = edge[e ^ 1].to;
        }
    }
}
} // namespace MinCost

int main() {
    #ifdef LOCAL
    assert(freopen("d.in", "r", stdin));
    #else
    #endif
    int n, m;
    cin >> n >> m;
    int extra = 0;
    MinCost::N = n;
    forn (i, m) {
        int u, v, c, f;
        scanf("%d%d%d%d", &u, &v, &c, &f);
        --u, --v;
        if (c >= f) {
            extra += f;
            MinCost::addEdge(u, v, f, -1);
            MinCost::addEdge(u, v, c - f, 1);
            MinCost::addEdge(u, v, MinCost::infc, 2);
        } else {
            extra += f;
            MinCost::addEdge(u, v, c, -1);
            MinCost::addEdge(u, v, f - c, 0);
            MinCost::addEdge(u, v, MinCost::infc, 2);
        }
    }
    MinCost::addEdge(n - 1, 0, MinCost::infc, 0);
    MinCost::circulation();
    cout << extra + MinCost::totalCost << '\n';
}