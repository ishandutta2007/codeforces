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
int bsr(uint x) { return 31 - __builtin_clz(x); }
int bsr(ull x) { return 63 - __builtin_clzll(x); }
int bsf(uint x) { return __builtin_ctz(x); }
int bsf(ull x) { return __builtin_ctzll(x); }

template<class N>
struct SegTree {
    int lg, sz;
    vector<N> n;
    SegTree() {}
    SegTree(int sz) {
        assert(sz >= 1);
        lg = bsr(uint(2*sz-1));
        sz = 1<<lg;
        this->sz = sz;
        n = vector<N>(2*sz);
        for (int i = 2*sz-1; i >= sz; i--) {
            n[i] = N();
        }
        for (int i = sz-1; i >= 1; i--) {
            n[i] = N(n[2*i], n[2*i+1]);
        }
    }
    void all_update() {
        for (int i = 1; i <= sz-1; i++) {
            n[i].push();
        }
        for (int i = sz-1; i >= 1; i--) {
            n[i].update(n[2*i], n[2*i+1]);
        }
    }
    template<class Q>
    Q single(int idx, Q q) {
        if (idx < 0 || sz <= idx) return q;
        idx += sz;
        for (int i = lg; i >= 1; i--) {
            int k = idx>>i;
            n[k].push(n[2*k], n[2*k+1]);
        }
        q += n[idx];
        if (q.update()) {
            for (int i = 1; i <= lg; i++) {
                int k = idx>>i;
                n[k].update(n[2*k], n[2*k+1]);
            }
        }
        return q;
    }
    template<class Q>
    void query(int a, int b, Q &q, int k, int sz) {
        if (a <= 0 && sz <= b) {
            q += n[k];
            return;
        }
        n[k].push(n[2*k], n[2*k+1]);
        if (a < sz/2) query(a, b, q, 2*k, sz/2);
        if (sz/2 < b) query(a-sz/2, b-sz/2, q, 2*k+1, sz/2);
        if (q.update()) n[k].update(n[2*k], n[2*k+1]);
    }
    template<class Q>
    Q query(int a, int b, Q q) {
        if (a < sz && 0 < b) query(a, b, q, 1, sz);
        return q;
    }
    struct NodeQuery {
        N n;
        static constexpr bool update() { return false; }
        void operator+=(N &r) { N nn; nn.update(n, r); n = nn; }
    };
};

struct Int {
    uint v;
    int st, ed;
    Int operator+(const Int &r) const {
        Int u;
        u.v = v + r.v;
        u.st = st; u.ed = r.ed;
        return u;
    }
    bool operator<(const Int &r) const {
        return v < r.v;
    }
    string to_string() {
        string s;
        s += "(";
        s += ::to_string(v);
        s += ", ";
        s += ::to_string(st);
        s += ", ";
        s += ::to_string(ed);
        s += ")";
        return s;
    }
};

const uint INF = TEN(9)*2+100;
const Int e = Int{INF, -1, -1};
const Int z = Int{0, -1, -1};
struct Node {
    int id;
    uint up, down;
    Int d[2][3][3];
    int cnt_mi;
    int cnt_lz;

    void init() {
        id = -1;
        up = INF; down = INF;
        cnt_mi = 0;
        cnt_lz = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                d[0][i][j] = d[1][i][j] = e;
            }
        }
    }
    Node() { init(); } // leaf
    Node(Node &l, Node &r) { init(); update(l, r); }

    void update_leaf() {
        d[0][0][0] = d[1][0][0] = z;
        d[0][0][1] = d[1][0][1] = Int{uint(down), -1, id};
        d[0][0][2] = d[1][0][2] = e;

        d[0][1][0] = d[1][1][0] = Int{uint(up), id, -1};
        d[0][1][1] = d[1][1][1] = Int{uint(up+down), id, id};
        d[0][1][2] = d[1][1][2] = Int{uint(up), id, -1};
        
        d[0][2][0] = d[1][2][0] = e;
        d[0][2][1] = e;
        d[1][2][1] = Int{uint(down), -1, id};
        d[0][2][2] = e;
        d[1][2][2] = z;
    }
    void update(const Node &l, const Node &r) {
        cnt_mi = min(l.cnt_mi, r.cnt_mi);

        // update 2
        int a = -1, b = -1;
        if (l.cnt_mi < r.cnt_mi) {
            //merge 0, 1
            a = 0; b = 1;
        } else if (l.cnt_mi > r.cnt_mi) {
            //merge 1, 0
            a = 1; b = 0;
        } else {
            //merge 0, 0
            a = 0; b = 0;
        }

        //update
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                d[0][i][j] = e;
                d[1][i][j] = e;
            }
        }
        d[0][0][0] = d[1][0][0] = z;
        d[0][2][2] = e;
        d[1][2][2] = z;

        d[0][0][1] = min(d[0][0][1], l.d[a][0][1]);
        d[1][0][1] = min(d[1][0][1], l.d[1][0][1]);

        d[0][1][2] = min(d[0][1][2], l.d[a][1][2]);
        d[1][1][2] = min(d[1][1][2], l.d[1][1][2]);

        d[0][1][0] = min(d[0][1][0], r.d[b][1][0]);
        d[1][1][0] = min(d[1][1][0], r.d[1][1][0]);

        d[0][2][1] = min(d[0][2][1], r.d[b][2][1]);
        d[1][2][1] = min(d[1][2][1], r.d[1][2][1]);

        d[0][1][1] = min(d[0][1][1], l.d[a][1][1]);
        d[0][1][1] = min(d[0][1][1], r.d[b][1][1]);
        d[1][1][1] = min(d[1][1][1], l.d[1][1][1]);
        d[1][1][1] = min(d[1][1][1], r.d[1][1][1]);
        
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                d[0][i][j] = min(d[0][i][j], l.d[a][i][0] + r.d[b][0][j]);
                d[0][i][j] = min(d[0][i][j], r.d[b][i][2] + l.d[a][2][j]);
                d[1][i][j] = min(d[1][i][j], l.d[1][i][0] + r.d[1][0][j]);
                d[1][i][j] = min(d[1][i][j], r.d[1][i][2] + l.d[1][2][j]);
            }
        }
    }

    void push(Node &l, Node &r) {
        if (cnt_lz) {
            l.lzdata(cnt_lz);
            r.lzdata(cnt_lz);
            cnt_lz = 0;
        }
    }
    void lzdata(ll x) {
        cnt_mi += x;
        cnt_lz += x;
    }
    // query
    struct AddQuery {
        ll x;
        static constexpr bool update() { return true; }
        void operator+=(Node &n) { n.lzdata(x); }
    };
    struct FirstQuery {
        int x; ll u, d;
        static constexpr bool update() { return true; }
        void operator+=(Node &n) {
            n.id = x;
            n.up = u;
            n.down = d;
            n.update_leaf();
        }
    };
};


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    int n, k;
    cin >> n >> k;
    V<ll> A(n), B(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    SegTree<Node> seg(n);

    for (int i = 0; i < n; i++) {
        seg.single(i, Node::FirstQuery{i, A[i], B[i]});
    }


    ll sm = 0;
    for (int ph = 0; ph < k; ph++) {
        auto no = seg.query(0, n, SegTree<Node>::NodeQuery{}).n;        
/*        for (int i = 0; i < n; i++) {
            cout << seg.n[i+seg.sz].d[0][1][1].to_string() << ", ";
        }
        cout << endl;
        cout << no.d[0][1][1].to_string() << endl;*/
        int st, ed;
        int wow;
        if (no.cnt_mi == 0) {
            wow = 0;
        } else {
            wow = 1;
        }
        sm += no.d[wow][1][1].v;
        st = no.d[wow][1][1].st;
        ed = no.d[wow][1][1].ed;
//        cout << st << " " << ed << " " << no.cnt_mi << " " << no.d[wow][1][1].to_string() << endl;
        if (st <= ed) {
            seg.query(st, ed, Node::AddQuery{1});
        } else {
            seg.query(ed, st, Node::AddQuery{-1});
        }
        A[st] = B[ed] = INF;
        seg.single(st, Node::FirstQuery{st, A[st], B[st]});
        seg.single(ed, Node::FirstQuery{ed, A[ed], B[ed]});
    }
    cout << sm << endl;
    return 0;
}