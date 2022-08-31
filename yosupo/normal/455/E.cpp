#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <random>
#include <complex>
#include <unordered_map>
#include <cmath>
#include <cassert>
#include <cstdint>

using namespace std;
typedef long long ll;

struct STree {
    struct Node;
    using NP = Node*;
    struct Node {
        NP l, r;
        int sz;
        short v, lz;
        int sm;
        static NP make(NP x) {
            if (!x->sz) return x;
            pool[pc] = *x;
            pc++;
            assert(pc <= PLS);
            return &pool[pc-1];
        }
        static NP make(int v) {
            pool[pc] = Node(v);
            pc++;
            return &pool[pc-1];
        }
        Node() {}
        Node(int v) :l(last), r(last), sz(1), v(v), sm(v), lz(-1) {}
        Node(NP l, NP r, int sz = 0) :l(l), r(r), sz(sz) {} 
        void push() {
            if (lz == -1) return;
            if (l->sz) {
                l = make(l);
                l->v = lz;
                l->sm = lz*l->sz;
                l->lz = lz;
            }
            if (r->sz) {
                r = make(r);
                r->v = lz;
                r->sm = lz*r->sz;
                r->lz = lz;
            }
            lz = -1;
        }
        NP update() {
            sz = 1+l->sz+r->sz;
            if (lz != -1) push();
            sm = v;
            if (l->sz) {
                sm += l->sm;
            }
            if (r->sz) {
                sm += r->sm;
            }
            return this;
        }
        void set(int a, int b, int x) {
            if (!sz || b <= 0 || sz <= a) return;
            push();
            if (a <= 0 && sz <= b) {
                v = x;
                sm = sz*x;
                lz = x;
                return;
            }
            l = make(l);
            l->set(a, b, x);
            if (a <= l->sz && l->sz < b) {
                v = x;
            }
            r = make(r);
            r->set(a- l->sz - 1, b- l->sz - 1, x);
            update();
        }
        void add(int k, int x) {
            push();
            if (k < l->sz) {
                l = make(l);
                l->add(k, x);
            } else if (k == l->sz) {
                v += x;
            } else {
                r = make(r);
                r->add(k - l->sz - 1, x);
            }
            update();
        }
        int sum(int a, int b) {
            if (!sz || b <= 0 || sz <= a) return 0;
            if (a <= 0 && sz <= b) return sm;
            if (lz != -1) {
                return (min(sz, b) - max(0, a))*lz;
            }
            push();
            int res = 0;
            res += l->sum(a, b);
            if (a <= l->sz && l->sz < b) res += v;
            res += r->sum(a - l->sz - 1, b - l->sz - 1);
            return res;
        }
        void get(int d[]) {
            if (!sz) return;
            push();
            l->get(d);
            d[l->sz] = v;
            r->get(d+l->sz+1);
        }
        void print() {
            if (!sz) return;
            push();
            l->print();
            printf("%d ", v);
            r->print();
        }
    } *n;
    static Node last_d;
    static NP last;
    static const int PLS = 250000000 / sizeof(Node);
    static int pc;
    static Node pool[PLS];


    static NP built(int l, int r, int d[]) {
        if (l == r) return last;
        int md = (l+r)/2;
        NP x = Node::make(d[md]);
        x->l = built(l, md, d);
        x->r = built(md+1, r, d);
        return x->update();
    }

    static unsigned int xor128(){
        static unsigned int x=123456789,y=362436069,z=521288629,w=88675123;
        unsigned int t;
        t=(x^(x<<11));x=y;y=z;z=w; return( w=(w^(w>>19))^(t^(t>>8)) );
    }
    static NP merge(NP l, NP r) {
        if (!l->sz) return r;
        if (!r->sz) return l;
        l->push(); r->push();
        if (xor128() % (l->sz + r->sz) < l->sz) {
            l = Node::make(l);
            l->r = merge(l->r, r);
            return l->update();
        } else {
            r = Node::make(r);
            r->l = merge(l, r->l);
            return r->update();
        }
    }
    static pair<NP, NP> split(NP x, int k) {
        if (!x->sz) return {last, last};
        x->push();
        x = Node::make(x);
        if (k <= x->l->sz) {
            auto y = split(x->l, k);
            x->l = y.second;
            y.second = x->update();
            return y;
        } else {
            auto y = split(x->r, k- x->l->sz -1);
            x->r = y.first;
            y.first = x->update();
            return y;
        }
    }

    STree() : n(last) {}
    STree(NP n) : n(n) {}
    STree(int sz, int d[]) {
        n = built(0, sz, d);
    }
    int sz() {
        return n->sz;
    }

    STree merge(STree r) {
        return STree(merge(n, r.n));
    }
    pair<STree, STree> split(int k) {
        auto u = split(n, k);
        return pair<STree, STree>(STree(u.first), STree(u.second));
    }
    STree insert(int k, int x) {
        auto u = split(n, k);
        return merge(merge(u.first, Node::make(x)), u.second);
    }
    STree erase(int k) {
        auto u = split(n, k);
        return merge(u.first, split(u.second, 1).second);
    }

    void get(int d[]) {
        n->get(d);
    }

    STree set(int l, int r, int x) {
        auto res = STree(Node::make(n));
        res.n->set(l,r,x);
        return res;
    }
    STree add(int k, int x) {
        auto res = STree(Node::make(n));
        res.n->add(k, x);
        return res;
    }
    int sum(int l, int r) {
        return n->sum(l, r);
    }
    void print() {
        n->print();
        printf("\n");
    }
};
STree::Node STree::last_d = STree::Node(NULL, NULL, 0);
STree::NP STree::last = &last_d;
STree::Node STree::pool[STree::PLS];
int STree::pc = 0;

const int MN = 100100;
int a[MN], b[MN];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[n-1-i] = a[i];
    }

    STree t[MN];
    t[0] = STree(n, b);
    for (int i = 1; i < n; i++) {
        //t[i] = t[i-1].insert(0, a[i]);
        t[i] = t[i-1];
        int l = 0, r = i+2;
        while (r - l > 1) {
            int md = (l+r)/2;
            if (md*a[i] <= t[i].sum(n-1-i, n-1-i+md)) {
                l = md;
            } else {
                r = md;
            }
        }
        if (l < i+1) {
            t[i] = t[i].add(n-1-i+l, t[i].sum(n-1-i, n-1-i+l)-l*a[i]);
        }
        t[i] = t[i].set(n-1-i, n-1-i+l, a[i]);
        //t[i].print();
    }
    //cout << STree::pc << endl;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> y >> x; x--; //xy
        cout << t[x].sum(n-1-x, n-1-x+y) << endl;
    }
    return 0;
}