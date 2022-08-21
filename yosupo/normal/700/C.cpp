#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}


template <class E>
using Graph = vector<vector<E>>;

/**
 * LowLink
 * dfs
 */
struct LowLink {
    vector<int> low, ord, par; //low, ord, parent
    vector<int> vlis; //preorder list
    
    template<class E>
    LowLink(const Graph<E> &g, int r) {
        int V = (int)g.size();
        low.resize(V); ord.resize(V); par.resize(V);
        co = 0; used.resize(V);
        fill(begin(used), end(used), false);
        if (r != -1) {
            dfs(g, r, -1);
        } else {
            for (int i = 0; i < V; i++) {
                if (used[i]) continue;
                dfs(g, i, -1);
            }
        }
    }
    int co;
    vector<bool> used;
    template<class E>
    void dfs(const Graph<E> &g, int p, int b) {
        used[p] = true;
        bool rt = true;
        low[p] = ord[p] = co++;
        vlis.push_back(p);
        par[p] = b;
        for (E e: g[p]) {
            if (e.enable == false) {
                continue;
            }
            if (rt and e.to == b) {
                rt = false;
                continue;
            }
            if (!used[e.to]) {
                dfs(g, e.to, p);
                low[p] = min(low[p], low[e.to]);
            } else {
                low[p] = min(low[p], ord[e.to]);
            }
        }
    }
};

/**
 * 
 */
struct Bridge {
    int gc;
    vector<int> ig; // i to group
    vector<int> gpar; // group par
    vector<bool> isRoot;
    template<class E>
    Bridge(const Graph<E> &g, int r, const LowLink &lc) {
        int V = (int)g.size();
        ig.resize(V);
        isRoot.resize(V);
        gc = 0;
        for (int p: lc.vlis) {
            isRoot[p] = (lc.low[p] == lc.ord[p]);
            if (lc.low[p] == lc.ord[p]) {
                ig[p] = gc++;
                gpar.push_back((p == r) ? -1 : ig[lc.par[p]]);
            } else {
                ig[p] = ig[lc.par[p]];
            }
        }
    }
};


struct Edge {
    int to;
    int cost;
    int idx;
    bool enable;
    int rev;
};

int n;
Graph<Edge> g;

int main() {
    int m;
    cin >> n >> m;
    int s, t;
    cin >> s >> t; s--; t--;
    g = Graph<Edge>(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c; a--; b--;
        g[a].push_back(Edge{b, c, i, true, (int)g[b].size()});
        g[b].push_back(Edge{a, c, i, true, (int)g[a].size()-1});
    }
    LowLink mas(g, s);
    if (!mas.used[t]) {
        printf("0\n");
        printf("0\n");
        printf("\n");
        return 0;
    }
    int p = t;
    int ans = 0;
    vector<Edge> ev;
    while (p != s) {
//        printf("%d %d\n", p, mas.par[p]);
        vector<Edge> nev = [&]() -> vector<Edge> {
            for (Edge &e: g[p]) {
                if (e.to == mas.par[p]) {
                    e.enable = false;
                    g[e.to][e.rev].enable = false;
                    LowLink lc(g, s);
                    Bridge br(g, s, lc);
                    vector<Edge> res = {e};
                    if (!lc.used[t]) {
                        e.enable = true;
                        g[e.to][e.rev].enable = true;
                        return res;
                    }
                    int q = t;
                    int nc = 0;
                    Edge ne;
                    while (q != s) {
                        if (br.isRoot[q]) {
                            for (Edge e2: g[q]) {
                                if (e2.enable and e2.to == lc.par[q]) {
                                    if (nc == 0 or e2.cost < nc) {
                                        nc = e2.cost;
                                        ne = e2;
                                    }
                                    break;
                                }
                            }
                        }
                        q = lc.par[q];
                    }
                    e.enable = true;
                    g[e.to][e.rev].enable = true;
                    if (nc) {
                        res.push_back(ne);
                        return res;
                    }
                    break;
                }
            }
            return vector<Edge>();
        }();
        if (nev.size()) {
            int nans = 0;
            for (Edge e: nev) {
                nans += e.cost;
            }
            if (ev.size() == 0 or nans <= ans) {
                ans = nans;
                ev = nev;
            }
        }
        p = mas.par[p];
    }

    if (ev.size() == 0) {
        printf("-1\n");
        return 0;
    }
    printf("%d\n", ans);
    printf("%ld\n", ev.size());
    for (Edge e: ev) {
        printf("%d ", e.idx+1);
    }
    printf("\n");
    return 0;
}