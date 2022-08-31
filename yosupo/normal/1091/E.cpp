#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

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

V<ll> first(V<ll> a) {
    int n = int(a.size());
    V<ll> freq(n + 1);
    sort(a.begin(), a.end(), greater<ll>());
    for (int i = 0; i < n; i++) {
        freq[min(ll(i), a[i])]++;
    }
    V<ll> fi(n + 1);
    ll sm = 0, rsm = 0, cnt = n;
    for (int i = 0; i <= n; i++) {
        fi[i] += ll(i) * (i - 1);
        fi[i] += cnt * i;
        fi[i] += rsm;
        fi[i] -= sm;
        if (i == n) break;
        sm += a[i];
        rsm += i * freq[i];
        rsm -= min(ll(i), a[i]);
        cnt -= freq[i];
    }

    return fi;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;
    int n;
    cin >> n;
    V<ll> a(n);
    ll all_e = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        all_e += a[i];
    }
    sort(a.begin(), a.end(), greater<ll>());

    V<int> idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int x, int y) {
        if (a[x] != a[y]) return a[x] > a[y];
        return x > y;
    });

    auto seg = get_seg(first(a), TEN(18), 0LL,
            [&](ll x, ll y){ return min(x, y); },
            [&](ll x, ll y){ return x + y; },
            [&](ll x, ll y){ return x + y;});

    auto check = [&]() {
        if (all_e % 2) return false;
        if (seg.sum(0, n + 1) < 0) return false;
        return true;
    };

    V<int> ans;
    if (check()) ans.push_back(0);
    int now = 0;
    for (int i: idx) {
        if (!a[i]) break;
        now++;
        all_e--;

        //decrease a[i]
        seg.add(i + 1, n + 1, 1LL);
        if (a[i] <= i) {
            seg.add(a[i], i + 1, -1LL);
        }

        if (check()) ans.push_back(now);
    }

    if (ans.empty()) ans.push_back(-1);
    for (int d: ans) cout << d << " ";
    cout << endl;
    return 0;
}