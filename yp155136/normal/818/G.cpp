#include <bits/stdc++.h>
using namespace std;

const int maxv = 1e4 + 5, maxn = 1e5 + 5;
const int inf = 1e9 + 5;

struct MCMF {
    struct Edge {
        int to, rev, cap, w;
        Edge() {}
        Edge(int a, int b, int c, int d): to(a), cap(b), w(c), rev(d) {}
    };
    int n, s, t;
    vector<int> p, id, d;
    bitset<maxn> inque;
    vector<Edge> G[maxn];
    pair<int, int> spfa() {
        p.assign(n, -1);
        d.assign(n, inf);
        id.assign(n, -1);
        d[s] = 0; p[s] = s;
        queue<int> que; que.push(s); inque[s] = true;
        while (que.size()) {
            int tmp = que.front(); que.pop();
            inque[tmp] = false;
            int i = 0;
            for (auto e : G[tmp]) {
                if (e.cap > 0 && d[e.to] > d[tmp] + e.w) {
                    d[e.to] = d[tmp] + e.w;
                    p[e.to] = tmp;
                    id[e.to] = i;
                    if (!inque[e.to]) que.push(e.to), inque[e.to] = true;
                }
                ++i;
            }
        }
        if (d[t] == inf) return make_pair(-1, -1);
        int a = inf;
        for (int i = t; i != s; i = p[i]) {
            a = min(a, G[p[i]][id[i]].cap);
        }
        for (int i = t; i != s; i = p[i]) {
            Edge &e = G[p[i]][id[i]];
            e.cap -= a; G[e.to][e.rev].cap += a;
        }
        return make_pair(a, d[t]);
    }
    MCMF(int _n, int _s, int _t): n(_n), s(_s), t(_t) {
        fill(G, G + maxn, vector<Edge>());
    }
    void add_edge(int a, int b, int cap, int w) {
        G[a].push_back(Edge(b, cap, w, (int)G[b].size()));
        G[b].push_back(Edge(a, 0, -w, (int)G[a].size() - 1));
    }
    pair<int, int> maxflow() {
        int mxf = 0, mnc = 0;
        while (true) {
            pair<int, int> res = spfa();
            if (res.first == -1) break;
            mxf += res.first; mnc += res.first * res.second;
        }
        return make_pair(mxf, mnc);
    }
};
int a[maxn], nxt[maxn];
int z[7];

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    MCMF flow(n + n + 10, n + n + 2, n + n + 1);
    for (int i = 1; i <= n; ++i) flow.add_edge(i, i + n, 1, -1), flow.add_edge(i, i + n, inf, 0);
    for (int i = n; i >= 1; --i) {
        if (nxt[a[i] + 1]) flow.add_edge(i + n, nxt[a[i] + 1], 1, 0);
        if (nxt[a[i] - 1]) flow.add_edge(i + n, nxt[a[i] - 1], 1, 0);
        if (z[a[i] % 7]) flow.add_edge(i + n, z[a[i] % 7], 4, 0);
        z[a[i] % 7] = i;
        nxt[a[i]] = i;
    }
    for (int i = 1; i <= n; ++i) flow.add_edge(0, i, 1, 0);
    for (int i = 1; i <= n; ++i) flow.add_edge(i + n, n + n + 1, 1, 0);
    flow.add_edge(n + n + 2, 0, 4, 0);
    int f = 0, c = 0;
    tie(f, c) = flow.maxflow();
    printf("%d\n", -c);
}