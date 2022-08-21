#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

struct LCNode {
    using NP = LCNode*;
    static NP last;
    int d, dsm;
    NP init_last() {
        sz = 0; // Important
        d = dsm = 0;
        return this;
    }
    void init_node(int x) {
        sz = 1; rev = false; // Important
        d = dsm = x;
    }
    void update() {
        sz = 1 + l->sz + r->sz; // Important
        dsm = d ^ l->dsm ^ r->dsm;
    }
    void push() {
        assert(this != last);
        if (rev) { // Important
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
        rev ^= true; swap(l, r); // Important
    }

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
        if (pps == -1) q->l = this;
        if (pps == 1) q->r = this;
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
        p->update(); update();
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
        assert(this != last);
        NP u = this, ur = last;
        do {
            u->splay();
            u->r = ur;
            u->update();
            ur = u;
        } while ((u = u->p));
        splay();
    }
    void supush() {
        if (pos()) p->supush();
        push();
    }
    void link(NP r) {
        evert(); r->expose();
        p = r;
    }
    void cut() {
        expose();
        l->p = NULL;
        l = last;
        update();
    }
    void evert() {
        expose(); revdata();
    }

    //tree func
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

LCNode lct[600100];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;

    map<int, int> to_id;
    auto get_id = [&](int x, int v = 0) {
        if (to_id.count(x)) return to_id[x];
        int nid = int(to_id.size());
        to_id[x] = nid;
        lct[nid].init_node(v);
        return nid;
    };
    auto path_dist = [&](int lid, int rid) {
        if (lct[lid].lca(lct+rid) == nullptr) return -1;
        lct[lid].evert();
        lct[rid].expose();
        return lct[rid].dsm;
    };

    int q;
    cin >> q;
    int last = 0;
    for (int ph = 0; ph < q; ph++) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r;
            int x;
            cin >> l >> r >> x;
            l ^= last;
            r ^= last;
            x ^= last;
            if (l > r) swap(l, r);
            r++;
            int lid = get_id(l);
            int rid = get_id(r);
            int pd = path_dist(lid, rid);
            if (lct[lid].lca(lct+rid) == nullptr) {
                int mid = get_id(-1 - ph, x);
                lct[lid].evert();
                lct[lid].link(lct+mid);
                lct[mid].link(lct+rid);
            }
        } else {
            int l, r;
            cin >> l >> r;
            l ^= last;
            r ^= last;
            if (l > r) swap(l, r);
            r++;
            int lid = get_id(l);
            int rid = get_id(r);

            int pd = path_dist(lid, rid);
            cout << pd << endl;
            last = pd;
            if (last == -1) last = 1;
        }
    }
    return 0;
}