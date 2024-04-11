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

/**
 * Link-Cut Tree
 *
 * linkcutevertparent, root
 * 
 */

vector<int> v_buf1(30), v_buf2(30);
struct LCNode {
    using NP = LCNode*;
    static NP last;

    vector<int> v, vsm;
    NP init_last() {
        sz = 0;
        v.clear();
        vsm.clear();
        return this;
    }
    void init_node(int d) {
        sz = 1;
        rev = false;
        v.clear();
        vsm.clear();
    }
    void update() {
        sz = 1 + l->sz + r->sz;
        v_buf1.clear(); v_buf2.clear();
        int ls = l->vsm.size();
        int vs = v.size();
        int rs = r->vsm.size();
        merge(l->vsm.begin(), l->vsm.end(), v.begin(), v.end(), v_buf1.begin());
        merge(v_buf1.begin(), v_buf1.begin()+ls+vs, r->vsm.begin(), r->vsm.end(), v_buf2.begin());
        int nv = min(10, ls+vs+rs);
        vsm.resize(nv);
        copy_n(v_buf2.begin(), nv, vsm.begin());
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
        swap(l, r);
        rev ^= true;
    }

    void adddata(int x) {
        v.push_back(x);
        sort(v.begin(), v.end());
        if (10 < v.size()) v.resize(10);
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

const int MN = 100100;
LCNode lc[MN];

int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 0; i < n; i++) {
        lc[i] = LCNode();
    }
    for (int i = 0; i < n-1; i++) {
        int x, y;
        scanf("%d %d", &x, &y); x--; y--;
        lc[x].evert();
        lc[x].link(lc+y);
    }
    for (int i = 1; i <= m; i++) {
        int x;
        scanf("%d", &x); x--;
        lc[x].expose();
        lc[x].adddata(i);
    }

    for (int i = 0; i < q; i++) {
        int v, u, a;
        scanf("%d %d %d", &v, &u, &a); v--; u--;
        lc[v].evert();
        lc[u].expose();
        auto ans = lc[u].vsm;
        if (a < ans.size()) ans.resize(a);
        printf("%ld", ans.size());
        for (int d: ans) {
            printf(" %d", d);
        }
        printf("\n");
    }
    return 0;
}