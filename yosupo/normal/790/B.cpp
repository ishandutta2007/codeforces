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

struct TreeOrd {
    using P = pair<int, int>;
    vector<P> s, rs;
    template<class E>
    TreeOrd(const Graph<E> &g, int r = 0) {
        s.push_back(P(r, -1));
        for (int i = 0; i < int(s.size()); i++) {
            P p = s[i];
            for (E e: g[p.first]) {
                if (e.to == p.second) continue;
                s.push_back(P(e.to, p.first));
            }
        }
        rs = vector<P>(s.rbegin(), s.rend());
    }
};

template<class N>
struct AllTree {
    vector<vector<N>> ldp;
    AllTree() {}
    template<class E>
    AllTree(const Graph<E> &g, const TreeOrd &t, int r = 0) {
        int n = int(g.size());
        auto sm = vector<N>(n), top = vector<N>(n);
        ldp = vector<vector<N>>(n);
        for (int i = 0; i < n; i++) {
            ldp[i].resize(int(g[i].size())+1);
        }
        for (auto pa: t.rs) {
            // first
            int p, b; tie(p, b) = pa;
            sm[p] = N();
            for (const E &e: g[p]) {
                int d = e.to;
                if (d == b) continue;
                sm[p] = sm[p] + N(sm[d]).first(p, e);
            }
            sm[p].finish(p);
        }
        top[r] = N();
        for (auto pa: t.s) {
            // second
            int p, b; tie(p, b) = pa;
            int dg = int(g[p].size());
            vector<N> &ln = ldp[p];
            ln[0] = N();
            for (int i = 0; i < dg; i++) {
                int d = g[p][i].to;
                ln[i+1] = ln[i] + N(d==b ? top[p] : sm[d]).first(p, g[p][i]);
            }
            N rnode = N();
            for (int i = dg-1; i >= 0; i--) {
                int d = g[p][i].to;
                if (d != b) {
                    top[d] = (ln[i]+rnode).finish(p);
                }
                ln[i] = ln[i] + rnode;
                rnode = rnode + N(d==b ? top[p] : sm[d]).first(p, g[p][i]);
            }
        }
    }
    N get(int p, int idx = -1) {
        if (idx == -1) idx = int(ldp[p].size())-1;
        return N(ldp[p][idx]).finish(p);
    }
};

int k;
struct Node {
    //  
    // first ->
    // finish->
//    int rad, dia;
//    int rd[2];
    ll sm[5];
    int sz;
    Node() {
        // !!!!!!!!!!
        fill(sm, sm+5, 0);
        sz = 0;
    }
    template<class E>
    Node first(int par, const E &e) {
        // ->  e=(par -> node)
        ll buf = sm[0];
        for (int i = 0; i < k-1; i++) {
            sm[i] = sm[i+1];
        }
        sm[k-1] = buf + sz;
        return *this;
    }
    Node operator+(const Node &r) {
        //  
        Node n;
        for (int i = 0; i < k; i++) {
            n.sm[i] = sm[i] + r.sm[i];
        }
        n.sz = sz + r.sz;
        return n;
    }
    Node finish(int par) {
        // idx
        for (int i = 1; i < k; i++) {
            sm[i] += 1;
        }
        sz++;
        return *this;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int n;
    cin >> n >> k;
    Graph<Edge> g(n);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        g[a].push_back(Edge{b});
        g[b].push_back(Edge{a});
    }
    AllTree<Node> dp(g, TreeOrd(g));
    ll sm = 0;
    for (int i = 0; i < n; i++) {
        sm += dp.get(i).sm[0];
//        cout << i << " " << dp.get(i).sm[0] << endl;
    }
    cout << sm/2 << endl;
    return 0;
}