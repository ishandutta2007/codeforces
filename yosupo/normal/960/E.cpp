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
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

struct TreeOrd {
    using P = pair<int, int>;
    vector<P> s, rs;
    template<class E>
    TreeOrd(const VV<E> &g, int r = 0) {
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
    AllTree(const VV<E> &g, int r = 0) : AllTree(g, TreeOrd(g, r), r) {}
    template<class E>
    AllTree(const VV<E> &g, const TreeOrd &t, int r = 0) {
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

template<uint MD>
struct ModInt {
    using M = ModInt;
    uint v;
    ModInt() : v{0} {}
    ModInt(ll v) : v{normS(v%MD+MD)} {}
    explicit operator bool() const {return v != 0;}
    static uint normS(uint x) {return (x<MD)?x:x-MD;};
    static M make(uint x) {M m; m.v = x; return m;}
    static M inv(const M &x) {return x.pow(MD-2); }
    M operator+(const M &r) const {return make(normS(v+r.v));}
    M operator-(const M &r) const {return make(normS(v+MD-r.v));}
    M operator*(const M &r) const {return make(ull(v)*r.v%MD);}
    M operator/(const M &r) const {return *this*inv(r);}
    M& operator+=(const M &r) {return *this=*this+r;}
    M& operator-=(const M &r) {return *this=*this-r;}
    M& operator*=(const M &r) {return *this=*this*r;}
    M& operator/=(const M &r) {return *this=*this/r;}
    M pow(ll n) const {
        M x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
};
using Mint = ModInt<TEN(9)+7>;

struct Node {
    //  
    // first ->
    // finish->

    Mint odd, even;
    Node() {
        // !!!!!!!!!!
        odd = even = Mint(0);
    }
    template<class E>
    Node first(int par, const E &e) {
        // ->  e=(par -> node)
        swap(odd, even);
        return *this;
    }
    Node operator+(const Node &r) {
        //  
        Node n;
        n.odd = odd + r.odd;
        n.even = even + r.even;
        return n;
    }
    Node finish(int par) {
        // idx
        even += Mint(1);
        return *this;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    struct E { int to; };
    int n;
    cin >> n;
    V<Mint> a(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i] = Mint(x);
    }
    VV<E> g(n);
    using P = pair<int, int>;
    map<P, int> toID;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        toID[P(a, b)] = int(g[a].size());
        toID[P(b, a)] = int(g[b].size());
        g[a].push_back(E{b});
        g[b].push_back(E{a});
    }
    Mint sm = Mint(0);
    AllTree<Node> tr(g);
    for (int i = 0; i < n; i++) {
        int m = int(g[i].size());
        sm += a[i] * Mint(n);
        for (int ph = 0; ph < m; ph++) {
            int j = g[i][ph].to;
            auto u = tr.get(i, ph);
            auto w = tr.get(j, toID[P(j, i)]);
            sm += a[i] * w.odd * (u.odd + u.even);
            sm -= a[i] * w.even * (u.odd + u.even);
        }
    }
    cout << sm.v << endl;
    return 0;
}