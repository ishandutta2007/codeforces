#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);
typedef pair<int, int> pii;

struct Edge {
    int to, c, f, cost;

    Edge(int to, int c, int cost): to(to), c(c), f(0), cost(cost) {}
};

const int maxn = 100100;
namespace MinCost {

int N, S, T;
int p[maxn];
vector<int> g[maxn];
vector<Edge> edge;
int total;

void addEdge(int u, int v, int c, int cost) {
    g[u].push_back(sz(edge));
    edge.emplace_back(v, c, cost);
    g[v].push_back(sz(edge));
    edge.emplace_back(u, 0, -cost);
}

int dist[maxn];
int from[maxn];
void dickstra() {
    forn (i, N)
        dist[i] = inf;
    dist[S] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> o;
    o.emplace(dist[S], S);
    while (!o.empty()) {
        int u, cd;
        tie(cd, u) = o.top();
        o.pop();
        if (cd != dist[u])
            continue;
        for (int e: g[u]) {
            if (edge[e].f == edge[e].c)
                continue;
            int v = edge[e].to;
            int w = edge[e].cost + p[u] - p[v];
            assert(w >= 0);
            int ndist = w + dist[u];
            if (dist[v] <= ndist)
                continue;
            dist[v] = ndist;
            o.emplace(dist[v], v);
            from[v] = e;
        }
    }
    assert(dist[T] != inf);
    forn (i, N) {
        if (dist[i] == inf)
            continue;
        p[i] += dist[i];
    }
}

void step() {
    dickstra();
    int u = T;
    while (u != S) {
        int e = from[u];
        edge[e].f++;
        edge[e ^ 1].f--;
        total += edge[e].cost;
        u = edge[e ^ 1].to;
    }
}

}

int main() {
    #ifdef LOCAL
    assert(freopen("i.in", "r", stdin));
    #else
    #endif
    int n, p, s;
    cin >> n >> p >> s;
    MinCost::N = n + 4;
    MinCost::S = n + 2;
    MinCost::T = n + 3;

    forn (i, n) {
        int a;
        cin >> a;
        MinCost::addEdge(i, n, 1, -a);
    }
    forn (i, n) {
        int b;
        cin >> b;
        MinCost::addEdge(i, n + 1, 1, -b);
    }
    forn (i, n)
        MinCost::p[i] = 3000;
    MinCost::p[MinCost::S] = 3000;

    forn (i, n)
        MinCost::addEdge(MinCost::S, i, 1, 0);
    MinCost::addEdge(n, MinCost::T, p, 0);
    MinCost::addEdge(n + 1, MinCost::T, s, 0);
    forn (i, p + s)
        MinCost::step();
    cout << -MinCost::total << '\n';
    forn (i, n) {
        if (MinCost::edge[i * 2].f)
            cout << i + 1 << ' ';
    }
    cout << '\n';
    forn (i, n) {
        if (MinCost::edge[i * 2 + n * 2].f)
            cout << i + 1 << ' ';
    }
    cout << '\n';
}