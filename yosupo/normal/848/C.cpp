#define NDEBUG
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
//bit op
int bsr(uint x) { return 31 - __builtin_clz(x); }
int bsr(ull x) { return 63 - __builtin_clzll(x); }
int bsf(uint x) { return __builtin_ctz(x); }
int bsf(ull x) { return __builtin_ctzll(x); }

struct Node;
using NP = Node*;
struct Node {
    NP ch[2]; int sz;
    int x; ll y, sm;
    Node(int x, ll y) {
        ch[0] = ch[1] = nullptr;
        sz = 1;
        this->x = x;
        this->y = this->sm = y;
    }
};
 
int sz(NP n) { return (n==nullptr) ? 0 : n->sz; }
ll getsm(NP n) { return (n==nullptr) ? 0 : n->sm; }
int wei(NP n) { return sz(n)+1; }
void update(NP n) {
    assert(n != nullptr);
    n->sz = 1 + sz(n->ch[0]) + sz(n->ch[1]);
//    n->sm = n->y + getsm(n->ch[0]) + getsm(n->ch[1]);
}
NP rot(NP n, int ty) {
    // ty = 0: ((a, b), c) -> (a, (b, c))
    NP m = n->ch[ty];
    assert(m != nullptr);
    n->ch[ty] = m->ch[1-ty];
    m->ch[1-ty] = n;
    if (ty == 0) {
        n->sm -= m->sm;
    } else {
        m->sm += n->sm;
    }
    update(n); update(m);
    assert(!n->ch[0] || n->ch[0]->x < n->x);
    return m;
}
 
NP bal(NP n) {
    for (int f = 0; f <= 1; f++) {
        if (wei(n->ch[f])*2 > wei(n->ch[1-f])*5) {
            if (wei(n->ch[f]->ch[f])*3 < wei(n->ch[f]->ch[1-f])*2) {
                n->ch[f] = rot(n->ch[f], 1-f);
            }
            return rot(n, f);
        }
    }
    return n;
}
 
NP ins(NP n, int x, ll y) {
    if (n == nullptr) return new Node(x, y);
    if (x == n->x) {
        n->y += y;
        n->sm += y;
        return n;
    }
    if (x < n->x) {
        n->ch[0] = ins(n->ch[0], x, y);
        n->sm += y;
    } else {
        n->ch[1] = ins(n->ch[1], x, y);
    }
    update(n);
    return bal(n);
}

ll getsm(NP n, int a) {
    if (n == nullptr) return 0;
    if (a <= n->x) return getsm(n->ch[0], a);
//    return getsm(n->ch[0]) + (n->y) + getsm(n->ch[1], a);
    return n->sm + getsm(n->ch[1], a);
}

const int MN = 100100;


struct Fenwick {
    Node *n = nullptr;
    void add(int i, ll x) {
        n = ins(n, i, x);
    }
    ll sum(int a, int b) { return getsm(n, b) - getsm(n, a); }
};

struct SegTree {
    int lg, sz;
    V<Fenwick> n;
    SegTree() {}
    SegTree(int sz) {
        assert(sz >= 1);
        lg = bsr(uint(2*sz-1));
        sz = 1<<lg;
        this->sz = sz;
        n = vector<Fenwick>(2*sz);
    }

    void add(int a, int b, int h, ll x, int l, int r, int k) {
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            n[k].add(h, x);
            return;
        }
        int md = (l+r)/2;
        add(a, b, h, x, l, md, 2*k);
        add(a, b, h, x, md, r, 2*k+1);
    }
    void add(int a, int b, int h, ll x) {
        add(a, b, h, x, 0, sz, 1);
    }
    ll sum(int k, int d, int u) {
        ll sm = 0;
        k += sz;
        while (k) {
            sm += n[k].sum(d, u);
            k >>= 1;
        }
        return sm;
    }    
};

int n, m;
int a[MN];
int ty[MN], q0[MN], q1[MN];
ll res[MN];

struct Solve {
    int b[MN];
    set<int> s[MN];
    set<int, greater<int>> rs[MN];
    SegTree seg = SegTree(MN);
    void add_line(int l, int r, int h, ll x) {
        seg.add(l, r+1, h, x);
    }
    ll sum_line(int x, int d, int u) {
        return seg.sum(x, d, u+1);
    }
    void solve() {
        V<int> ba(MN, -1);
        for (int i = 0; i < n; i++) {
            b[i] = a[i]; b[i]--;
            if (ba[b[i]] != -1) {
                add_line(ba[b[i]], i-1, ba[b[i]], ba[b[i]]);
            }
            ba[b[i]] = i;
            s[b[i]].insert(i);
            rs[b[i]].insert(i);
        }
        for (int i = 0; i < MN; i++) {
            if (ba[i] != -1) {
                add_line(ba[i], n-1, ba[i], ba[i]);
            }
        }
        for (int i = 0; i < n; i++) {
            s[i].insert(n);
            rs[i].insert(-1);
        }
        for (int i = 0; i < m; i++) {
            if (ty[i] == 1) {
                //cng
                int p = q0[i]; p--;
                int x = b[p], y = q1[i]; y--;
                if (x == y) continue;
                int lx = *rs[x].upper_bound(p);
                int rx = *s[x].upper_bound(p);
                add_line(p, rx-1, p, -p);
                if (lx != -1) {
                    add_line(p, rx-1, lx, +lx);
                }
                int ly = *rs[y].upper_bound(p);
                int ry = *s[y].upper_bound(p);
                add_line(p, ry-1, p, p);
                if (ly != -1) {
                    add_line(p, ry-1, ly, -ly);
                }

                b[p] = y;
                s[x].erase(p);
                rs[x].erase(p);
                s[y].insert(p);
                rs[y].insert(p);
            } else {
                //sum
                int l = q0[i], r = q1[i]; l--; r--;
                res[i] += sum_line(r, l, r);
            }
        }
    }  
};

struct Solve2 {
    int b[MN];
    set<int> s[MN];
    set<int, greater<int>> rs[MN];
    SegTree seg = SegTree(MN);
    void add_line(int l, int r, int h, ll x) {
        seg.add(l, r+1, h, x);
    }
    ll sum_line(int x, int d, int u) {
        return seg.sum(x, d, u+1);
    }
    void solve() {
        V<int> ba(MN, -1);
        for (int i = 0; i < n; i++) {
            b[i] = a[i]; b[i]--;
            if (ba[b[i]] != -1) {
                add_line(ba[b[i]]+1, i, i, i);
            } else {
                add_line(0, i, i, i);
            }
            ba[b[i]] = i;
            s[b[i]].insert(i);
            rs[b[i]].insert(i);
        }
        for (int i = 0; i < n; i++) {
            s[i].insert(n);
            rs[i].insert(-1);
        }
        for (int i = 0; i < m; i++) {
            if (ty[i] == 1) {
                //cng
                int p = q0[i]; p--;
                int x = b[p], y = q1[i]; y--;
                if (x == y) continue;
                int lx = *rs[x].upper_bound(p);
                int rx = *s[x].upper_bound(p);
                add_line(lx+1, p, p, -p);
                if (rx != n) {
                    add_line(lx+1, p, rx, rx);
                }
                int ly = *rs[y].upper_bound(p);
                int ry = *s[y].upper_bound(p);
                add_line(ly+1, p, p, p);
                if (ry != n) {
                    add_line(ly+1, p, ry, -ry);
                }

                b[p] = y;
                s[x].erase(p);
                rs[x].erase(p);
                s[y].insert(p);
                rs[y].insert(p);
            } else {
                //sum
                int l = q0[i], r = q1[i]; l--; r--;
                res[i] -= sum_line(l, l, r);
            }
        }
    }  
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> ty[i] >> q0[i] >> q1[i];
    }
    {
        Solve s;
        s.solve();
    }
    {
        Solve2 s2;
        s2.solve();
    }
    for (int i = 0; i < m; i++) {
        if (ty[i] == 2) {
            cout << res[i] << endl;
        }
    }
    return 0;
}