#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

template <class T> ostream& operator<<(ostream& os, const V<T>& v) {
    os << "[";
    for (auto d : v) os << d << ", ";
    return os << "]";
}

template <class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << "P(" << p.first << ", " << p.second << ")";
}

template <class D, class L, class OpDD, class OpDL, class OpLL> struct SegTree {
    D e_d;
    L e_l;
    OpDD op_dd;
    OpDL op_dl;
    OpLL op_ll;
    int sz, lg;  //(2^lg), lg
    V<D> d;
    V<L> lz;

    SegTree(const V<D>& v,
            D _e_d,
            L _e_l,
            OpDD _op_dd,
            OpDL _op_dl,
            OpLL _op_ll)
            : e_d(_e_d), e_l(_e_l), op_dd(_op_dd), op_dl(_op_dl), op_ll(_op_ll) {
        int n = int(v.size());
        lg = 1;
        while ((1 << lg) < n) lg++;
        sz = 1 << lg;
        d = V<D>(2 * sz, e_d);
        lz = V<L>(2 * sz, e_l);
        for (int i = 0; i < n; i++) d[sz + i] = v[i];
        for (int i = sz - 1; i >= 0; i--) {
            update(i);
        }
    }

    void all_add(int k, L x) {
        d[k] = op_dl(d[k], x);
        lz[k] = op_ll(lz[k], x);
    }
    void push(int k) {
        all_add(2 * k, lz[k]);
        all_add(2 * k + 1, lz[k]);
        lz[k] = e_l;
    }
    void update(int k) { d[k] = op_dd(d[2 * k], d[2 * k + 1]); }

    void set(int p, D x) {
        p += sz;
        for (int i = lg; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= lg; i++) update(p >> i);
    }

    void add(int a, int b, L x, int l, int r, int k) {
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            all_add(k, x);
            return;
        }
        push(k);
        int mid = (l + r) / 2;
        add(a, b, x, l, mid, 2 * k);
        add(a, b, x, mid, r, 2 * k + 1);
        update(k);
    }
    void add(int a, int b, L x) { add(a, b, x, 0, sz, 1); }

    D single(int p) {
        p += sz;
        for (int i = lg; i >= 1; i--) push(p >> i);
        return d[p];
    }

    D sum(int a, int b, int l, int r, int k) {
        if (b <= l || r <= a) return e_d;
        if (a <= l && r <= b) return d[k];
        push(k);
        int mid = (l + r) / 2;
        return op_dd(sum(a, b, l, mid, 2 * k), sum(a, b, mid, r, 2 * k + 1));
    }
    D sum(int a, int b) { return sum(a, b, 0, sz, 1); }
};

template <class D, class L, class OpDD, class OpDL, class OpLL>
SegTree<D, L, OpDD, OpDL, OpLL> get_seg(V<D> v,
                                        D e_d,
                                        L e_l,
                                        OpDD op_dd,
                                        OpDL op_dl,
                                        OpLL op_ll) {
    return SegTree<D, L, OpDD, OpDL, OpLL>(v, e_d, e_l, op_dd, op_dl, op_ll);
}

struct E {
    int to;
    ll dist;
};
struct Q {
    int l, r, idx;
};

int n;
VV<E> g;
V<ll> dist;
V<int> lw, up;
void dfs(int p, ll nw = 0) {
    lw[p] = p; up[p] = p + 1;
    if (g[p].empty()) dist[p] = nw;
    for (auto e: g[p]) {
        dfs(e.to, nw + e.dist);
        lw[p] = min(lw[p], lw[e.to]);
        up[p] = max(up[p], up[e.to]);
    }
}

VV<Q> que;
V<ll> res;

template<class Seg>
void dfs2(int p, Seg& seg) {
    for (auto q: que[p]) {
        res[q.idx] = seg.sum(q.l, q.r);
    }
    for (auto e: g[p]) {
        seg.add(0, n, e.dist);
        seg.add(lw[e.to], up[e.to], - 2 * e.dist);
        dfs2(e.to, seg);
        seg.add(0, n, -e.dist);
        seg.add(lw[e.to], up[e.to], 2 * e.dist);
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;

    int q;
    cin >> n >> q;
    g = VV<E>(n);
    for (int i = 1; i < n; i++) {
        int p; ll x;
        cin >> p >> x; p--;
        g[p].push_back(E{i, x});
    }
    dist = V<ll>(n, TEN(18));
    lw = up = V<int>(n);
    dfs(0);
    que = VV<Q>(n);
    for (int i = 0; i < q; i++) {
        int v, l, r;
        cin >> v >> l >> r; v--; l--;
        que[v].push_back(Q{l, r, i});
    }
    res = V<ll>(q);

    auto seg = get_seg(dist, TEN(18), 0LL,
            [&](ll a, ll b) { return min(a, b); },
            plus<>(), plus<>());

    dfs2(0, seg);

    for (auto d: res) cout << d << endl;
    return 0;
}