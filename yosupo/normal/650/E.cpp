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


/**
 * Link-Cut Tree
 *
 * linkcutevertparent, root
 * 
 */
struct LCNode {
    using NP = LCNode*;
    static NP last;

    ll v;
    ll ma;
    NP init_last() {
        sz = 0; // Important
        return this;
    }
    void init_node(int d) {
        sz = 1; rev = false; // Important
        v = d;
        ma = d;
    }
    void update() {
        sz = 1 + l->sz + r->sz;
        ma = v;
        ma = max(ma, max(l->ma, r->ma));
    }
    void cngchsz(int x) {
    }
    void addch(NP b) {
        assert(b == last || b->p == this);
    }
    void delch(NP b) {
        assert(b == last || b->p == this);
    }
    void push() {
        assert(this != last);
        if (rev) {
            if (l != last) {
                l->revdata();
            }
            if (r != last) {
                r->revdata();
            }
            rev = false;
        }
    }
    void revdata() {
        rev ^= true;
        swap(l, r);
    }

    void lzdata(int x) {
        v = x;
        update();
    }

    //
    NP p, l, r;
    int sz;
    bool rev;
    LCNode() : p(nullptr), l(last), r(last) {}
    inline int pos() {
        if (p) {
            if (p->l == this) return -1;
            if (p->r == this) return 1;
        }
        return 0;
    }
    void rot() {
        NP q = p->p;
        int pps = p->pos();
        if (pps == -1) {
            q->l = this;
        }
        if (pps == 1) {
            q->r = this;
        }
        if (p->l == this) {
            p->l = r;
            if (r) r->p = p;
            r = p;
        } else {
            p->r = l;
            if (l) l->p = p;
            l = p;
        }
        p->p = this;
        p->update();
        update();
        p = q;
        if (q) q->update();
    }
    void splay() {
        supush();
        int ps;
        while ((ps = pos())) {
            int pps = p->pos();
            if (!pps) {
                rot();
            } else if (ps == pps) {
                p->rot(); rot();
            } else {
                rot(); rot();
            }
        }
    }
    void expose() {
        for (NP u = this; u; u = u->p) {
            u->splay();
        }
        for (NP u = this, ur = last; u; u = u->p) {
            NP tmp = u->r;
            u->r = last;
            u->update();
            u->addch(tmp);
            u->delch(ur);
            u->r = ur;
            u->update();
            ur = u;
        }
        splay();
    }
    void supush() {
        if (pos()) {
            p->supush();
        }
        push();
    }
    //

    void link(NP r) {
        expose();
        r->expose();
        p = r;
        r->addch(this);
    }

    NP parent() {
        expose();
        NP u = this->l;
        if (u == last) return last;
        u->push();
        while (u->r != last) {
            u = u->r;
            u->push();
        }
        u->expose();
        return u;
    }

    void cut() {
        NP u = parent();
        assert(u != last);
        assert(u->r == last);
        this->splay();
        u->delch(this);
        this->p = nullptr;
    }

    NP root() {
        expose();
        NP u = this;
        while (u->l != last) {
            u = u->l;
            u->push();
        }
        u->expose();
        return u;
    }

    void evert() {
        expose();
        revdata();
    }

    NP lca(NP n) {
        n->expose();
        expose();
        NP t = n;
        while (n->p != nullptr) {
            if (!n->pos()) t = n->p;
            n = n->p;
        }
        return (this == n) ? t : nullptr;
    }
};
LCNode::NP LCNode::last = (new LCNode())->init_last();

const int MN = 500500;
using P = pair<int, int>;
LCNode lc[MN], et[MN];
int ec = 0;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        lc[i].init_node(-1);
        et[i].init_node(-1);
    }
    map<P, int> s;
    map<int, P> rs;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        if (a > b) swap(a, b);
        s[P(a, b)] = ec;
        rs[ec] = P(a, b);
        lc[a].evert();
        lc[a].link(et+ec);
        et[ec].link(lc+b);
        et[ec].expose();
        et[ec].lzdata(ec);
        ec++;
    }

    int A[MN], B[MN];
    for (int i = 0; i < n-1; i++) {
        int a, b;
        scanf("%d %d", &a, &b); a--; b--;
        if (a > b) swap(a, b);
        A[i] = a; B[i] = b;
    }
    for (int i = 0; i < n-1; i++) {
        if (s.count(P(A[i], B[i]))) {
            int u = s[P(A[i], B[i])];
            et[u].expose();
            et[u].lzdata(-1);
        }
    }

    using P = pair<int, int>;
    using Q = pair<P, P>;
    vector<Q> v;

    for (int i = 0; i < n-1; i++) {
        if (s.count(P(A[i], B[i]))) continue;
        lc[B[i]].evert();
        lc[A[i]].expose();
        int u = lc[A[i]].ma;
        // u move
        et[u].expose();
        et[u].lzdata(-1);
        s[P(A[i], B[i])] = -1;
        v.push_back(Q(rs[u], P(A[i], B[i])));
        int x, y;
        tie(x, y) = rs[u];
        et[u].evert();
        lc[x].cut();
        lc[y].cut();
        lc[A[i]].evert();
        lc[A[i]].link(et+u);
        et[u].link(lc+B[i]);
    }

    printf("%ld\n", v.size());
    for (Q q: v) {
        printf("%d %d %d %d\n",
            q.first.first+1, q.first.second+1,
            q.second.first+1, q.second.second+1);
    }
    return 0;
}