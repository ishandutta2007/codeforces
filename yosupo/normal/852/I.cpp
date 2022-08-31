#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

struct HL {
    V<int> _ord, _rord, big, small;  // primitive
    HL(int n = 0) : _ord(n), _rord(n), big(n), small(n) {}
    int ord(int i) const { return i == -1 ? -1 : _ord[i]; }
    int rord(int i) const { return i == -1 ? -1 : _rord[i]; }
    int lca(int a, int b) const {
        a = ord(a);
        b = ord(b);
        while (a != b) {
            if (a > b) swap(a, b);
            if (small[b] <= a)
                break;
            else
                b = big[b];
        }
        return rord(a);
    }
};

template <class E> struct HL_EXEC : HL {
    const VV<E>& g;
    V<int> tch;
    int id = 0;
    HL_EXEC(const VV<E>& _g, int r) : HL(_g.size()), g(_g), tch(g.size(), -1) {
        assert(dfs_sz(r, -1) == int(g.size()));
        dfs(r, -1);
    }
    int dfs_sz(int p, int b) {
        int sz = 1, msz = -1;
        for (auto e : g[p]) {
            if (e.to == b) continue;
            int u = dfs_sz(e.to, p);
            sz += u;
            if (msz < u) tie(tch[p], msz) = make_pair(e.to, u);
        }
        return sz;
    }
    void dfs(int p, int b) {
        int q = id++, bq = ord(b);
        _ord[p] = q;
        _rord[q] = p;
        if (b == -1 || bq != q - 1) {
            small[q] = q;
            big[q] = bq;
        } else {
            small[q] = small[bq];
            big[q] = big[bq];
        }
        if (tch[p] == -1) return;
        dfs(tch[p], p);
        for (auto e : g[p]) {
            if (e.to == b || e.to == tch[p]) continue;
            dfs(e.to, p);
        }
    }
};

template <class E> HL get_hl(const VV<E>& g, int r) { return HL_EXEC<E>(g, r); }

struct E { int to; };
int n;
VV<E> g;

V<int> idx;
V<int> st, ed;
int dfs_c = 0;
void dfs(int p, int b) {
    st[p] = dfs_c;
    idx[dfs_c] = p;
    dfs_c++;
    for (E e: g[p]) {
        int d = e.to;
        if (d == b) continue;
        dfs(d, p);
    }
    ed[p] = dfs_c;
    idx[dfs_c] = p;
    dfs_c++;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;

    cin >> n;

    V<int> col(n), ty(n);
    for (int i = 0; i < n; i++) cin >> col[i];
    for (int i = 0; i < n; i++) cin >> ty[i];
    {
        V<int> buf = ty;
        sort(buf.begin(), buf.end());
        buf.erase(unique(buf.begin(), buf.end()), buf.end());
        for (auto& x: ty) {
            x = int(lower_bound(buf.begin(), buf.end(), x) - buf.begin());
        }
    }

    g = VV<E>(n);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        g[a].push_back(E{b});
        g[b].push_back(E{a});
    }

    idx = V<int>(2*n); st = V<int>(n); ed = V<int>(n);
    dfs(0, -1);
    auto hl = get_hl(g, 0);

    struct Q { int from, to, extra, idx; };
    V<Q> que;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        if (st[a] > st[b]) swap(a, b);
        if (ed[b] <= ed[a]) que.push_back(Q{st[a], st[b], -1, i});
        else {
            que.push_back(Q{ed[a], st[b], hl.lca(a, b), i});
        }
    }
    const int B = 400;
    sort(que.begin(), que.end(), [&](Q l, Q r) {
        int lx = l.from / B, rx = r.from / B;
        if (lx != rx) return lx < rx;
        return l.to < r.to;
    });


    ll sm = 0;
    V<ll> u0(n), u1(n);
    auto add = [&](int c, int d, int e) {
        sm -= u0[d] * u1[d];
        if (c == 0) u0[d] += e;
        else u1[d] += e;
        sm += u0[d] * u1[d];
    };
    V<int> uc(n);
    auto add_v = [&](int p) {
        if (uc[p] == 0) add(col[p], ty[p], 1);
        else add(col[p], ty[p], -1);
        uc[p]++;
    };
    auto rem_v = [&](int p) {
        if (uc[p] == 2) add(col[p], ty[p], 1);
        else add(col[p], ty[p], -1);
        uc[p]--;
    };

    V<ll> res(q);
    int l = 0, r = -1;
    for (auto q: que) {
        int nl = q.from, nr = q.to;
        while (nl < l) { add_v(idx[l-1]); l--; }
        while (r < nr) { add_v(idx[r+1]); r++; }
        while (l < nl) { rem_v(idx[l]); l++; }
        while (nr < r) { rem_v(idx[r]); r--; }
        if (q.extra != -1) add_v(q.extra);
        //cerr << q.from << " " << q.to << " " << q.extra << " " << q.idx << endl;
        res[q.idx] = sm;
        if (q.extra != -1) rem_v(q.extra);
    }

    for (ll d: res) {
        cout << d << "\n";
    }
    return 0;
}