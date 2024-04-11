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
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
template<class T = ll> constexpr T TEN(int n) {return (n==0)?1:10*TEN<T>(n-1);}

template <class E>
using Graph = vector<vector<E>>;

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

int L; //LOK

struct Node {
    //  
    // first ->
    // finish->
    int msz, szsm, mid;
    int Lsz;
    Node() {
        // !!!!!!!!!!
        msz = 0; mid = -1; szsm = 0;
        Lsz = 0;
    }
    template<class E>
    Node first(int par, const E &e) {
        // ->  e=(par -> node)
        msz = szsm;
        mid = e.to;
        return *this;
    }
    Node operator+(const Node &r) {
        //  
        Node n;
        if (msz < r.msz) {
            n.msz = r.msz;
            n.mid = r.mid;
        } else {
            n.msz = msz;
            n.mid = mid;
        }
        n.szsm = szsm+r.szsm;
        n.Lsz = max(Lsz, r.Lsz);
        return n;
    }
    Node finish(int par) {
        // idx
        szsm++;
        if (szsm <= L) Lsz = szsm;
        return *this;
    }
};

int main() {
    int n;
    scanf("%d", &n);
    L = n/2;
    struct Edge {
        int to, idx;
    };
    Graph<Edge> g(n);
    using P = pair<int, int>;
    map<P, int> p2idx;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        p2idx[P(a, b)] = int(g[a].size());
        g[a].push_back(Edge{b, int(g[a].size())});
        p2idx[P(b, a)] = int(g[b].size());
        g[b].push_back(Edge{a, int(g[b].size())});
    }
    AllTree<Node> dp(g, TreeOrd(g));
    bool res[n];
    for (int i = 0; i < n; i++) {
        auto n = dp.get(i);
        auto n2 = dp.get(n.mid, p2idx[P(n.mid, i)]);
        res[i] = (n.msz - n2.Lsz <= L);
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }
    printf("\n");
    return 0;
}