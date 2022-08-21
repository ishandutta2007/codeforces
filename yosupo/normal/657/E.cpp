//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx")
//#undef LOCAL
#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

#ifdef LOCAL
struct PrettyOS {
    ostream& os;
    bool first;
    template <class T> auto operator<<(T&& x) {
        if (!first) os << ", ";
        first = false;
        os << x;
        return *this;
    }
};
template <class... T> void dbg0(T&&... t) {
    (PrettyOS{cerr, true} << ... << t);
}
#define dbg(...)                                            \
    do {                                                    \
        cerr << __LINE__ << " : " << #__VA_ARGS__ << " = "; \
        dbg0(__VA_ARGS__);                                  \
        cerr << endl;                                       \
    } while (false);
#else
#define dbg(...)
#endif

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << "P(" << p.first << ", " << p.second << ")";
}

template <class T> ostream& operator<<(ostream& os, const V<T>& v) {
    os << "[";
    for (auto d : v) os << d << ", ";
    return os << "]";
}

struct LCNode {
    using NP = LCNode*;
    static NP last;
    int d, mi;
    int lz = 0;
    NP init_last() {
        sz = 0; // Important
        lz = 0; // Important
        d = mi = TEN(9);
        return this;
    }
    void init_node(int _d) {
        sz = 1; rev = false; // Important
        lz = 0; // Important
        d = mi = _d;
    }
    void update() {
        if (lz) dbg(p->p->p->p->p->p);
        assert(lz == 0);
        sz = 1 + l->sz + r->sz; // Important
        mi = min(d, min(l->mi, r->mi));
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
        if (lz) {
            if (l != last) {
                l->lzdata(lz);
            }
            if (r != last) {
                r->lzdata(lz);
            }
            lz = 0;
        }
    }
    void revdata() {
        rev ^= true; swap(l, r); // Important
    }
    void lzdata(int x) {
        d += x;
        mi += x;
        lz += x;
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
        if (q) q->push();
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
        push();
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
            assert(!u->rev && !u->lz);
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

const int MN = 300300;
LCNode ve[MN], ed[3 * MN];

struct E {
    int to;
};

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        ve[i].init_node(TEN(9));
    }
    int ec = 0;
    auto get_e = [&]() {
        ed[ec].init_node(0); ec++;
        return &(ed[ec - 1]);
    };
    auto add_e = [&](int u, int v) -> int {
        ve[u].evert();
        if (ve[v].root() != &(ve[u])) {            
            auto e = get_e();
            ve[u].link(e);
            e->link(ve + v);
            ve[u].expose();
            return 0;
        } else {      
            ve[u].evert();
            ve[v].expose();
            ve[v].lzdata(1);
            return 1;
        }
    };
    auto rem_e = [&](int u, int v, int ty) {
        if (ty == 0) {
            // cut
            ve[v].evert();
            auto e = ve[u].parent();
            assert(e->parent() == ve + v);
            e->cut();
            ve[u].cut();
        } else {
            // dec
            ve[u].evert();
            ve[v].expose();
            ve[v].lzdata(-1);
        }
    };

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        add_e(a, b);
    }

    int R = 0;
    auto rotate = [&](int ele) {
        ele = (ele + R) % n;
        if (ele == 0) return n;
        return ele;
    };
    for (int ph = 0; ph < q; ph++) {
        int n2, m2;
        cin >> n2 >> m2;
        V<int> preds(n2);
        for (int i = 0; i < n2; i++) {
            int x;
            cin >> x;
            x = rotate(x);
            x--;
            preds[i] = x;
        }


        using P = pair<int, int>;
        V<P> es(m2);
        V<int> ty(m2);
        for (int i = 0; i < m2; i++) {
            int a, b;
            cin >> a >> b;
            a = rotate(a); a--;
            b = rotate(b); b--;
            es[i] = P{a, b};
            ty[i] = add_e(a, b);

        }
        
        bool ok = true;
        for (int i = 0; i < n2 - 1; i++) {
            int u = preds[i], v = preds[i + 1];
            ve[u].evert();
            if (ve[v].root() != ve + u) {
                ok = false;
                break;
            }
            ve[v].expose();
            if (ve[v].mi == 0) {
                ok = false;
                break;
            }
        }

        for (int i = m2 - 1; i >= 0; i--) {
            int a, b;
            tie(a, b) = es[i];
            rem_e(a, b, ty[i]);
        }

        if (ok) {
            R += (ph + 1);
            R %= n;
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}