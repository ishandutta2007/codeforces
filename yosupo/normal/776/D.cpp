#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }

template <class E>
using Graph = vector<vector<E>>;

struct Edge {
	int to;
};

struct SCC {
    int gc; /// group count
    vector<int> res; /// res[i] = iID
    vector<vector<int>> scc; /// scc[i] = i

    template<class E>
    SCC(const Graph<E> &g, const Graph<E> &rg) {
        int V = (int)g.size();
        used = vector<bool>(V);
        res = vector<int>(V);
        gc = 0;

        fill(begin(used), end(used), false);
        for (int i = 0; i < V; i++) {
            if (!used[i]) dfs(g, i);
        }
        fill(begin(used), end(used), false);
        for (int i = vs.size()-1; i >= 0; i--) {
            if (!used[vs[i]]) {
                scc.push_back(vector<int>());
                rdfs(rg, vs[i], gc++, scc.back());
            }
        }        
    }

    vector<bool> used;
    vector<int> vs;

    template<class E>
    void dfs(const Graph<E> &g, int v) {
        used[v] = true;
        for (E e: g[v]) {
            if (!used[e.to]) dfs(g, e.to);
        }
        vs.push_back(v);
    }

    template<class E>
    void rdfs(const Graph<E> &rg, int v, int k, vector<int> &vv) {
        used[v] = true;
        res[v] = k; vv.push_back(v);
        for (E e: rg[v]) {
            if (!used[e.to]) rdfs(rg, e.to, k, vv);
        }
    }
};

struct TwoSat {
    int V;
    vector<bool> res;
    bool exec() {
        SCC scc(g, rg);
        for (int i = 0; i < V; i++) {
            if (scc.res[i] == scc.res[i+V]) return false;
            res[i] = scc.res[i] > scc.res[i+V];
        }
        return true;
    }

    struct Edge { int to; };
    Graph<Edge> g, rg;
    TwoSat(int V) : V(V) {
        g = Graph<Edge>(2*V);
        rg = Graph<Edge>(2*V);
        res.resize(V);
    }
    void addEdge(int a, int b) {
        g[a].push_back(Edge{b});
        rg[b].push_back(Edge{a});
    }
    void add(int a, bool apos, int b, bool bpos) {
        addEdge(a+(apos?V:0), b+(bpos?0:V));
        addEdge(b+(bpos?V:0), a+(apos?0:V));
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int n, m;
    cin >> n >> m;
    V<int> flag(n);
    for (int i = 0; i < n; i++) {
        cin >> flag[i];
    }
    VV<int> g(n);
    TwoSat two(m);
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        for (int j = 0; j < t; j++) {
            int a;
            cin >> a; a--;
            g[a].push_back(i);
        }
    }

    for (int i = 0; i < n; i++) {
        assert(g[i].size() == 2);
        int l = g[i][0], r = g[i][1];
        if (flag[i]) {
            two.add(l, false, r, true);
            two.add(l, true, r, false);
        } else {
            two.add(l, false, r, false);
            two.add(l, true, r, true);
        }
    }
    if (two.exec()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}