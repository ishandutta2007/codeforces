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
    V<int> pid, psz;
    int pc = 0;  // path id, size, count(optional)
    V<int> in, out;  // [id, out[id]) is subtree, [in[id], out[id]) is light-subtree (optional)
    HL(int n = 0) : _ord(n), _rord(n), big(n), small(n), pid(n), in(n), out(n) {}
    int ord(int i) const { return i == -1 ? -1 : _ord[i]; }
    int rord(int i) const { return i == -1 ? -1 : _rord[i]; }
    int par(int a) const {
        a = ord(a);
        return rord(small[a] == a ? big[a] : a - 1);
    }
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
    template <class F>
    void get_path(int a,
                  int b,
                  F f) const {  // abf
        a = ord(a);
        b = ord(b);
        while (a < b) {
            if (small[b] <= a)
                f(a + 1, b);
            else
                f(small[b], b);
            b = big[b];
        }
    }
    int to(int a, int b) {  // ab1
        a = ord(a);
        b = ord(b);
        assert(a < b);
        while (true) {
            if (small[b] <= a)
                return rord(a + 1);
            else if (big[b] == a)
                return rord(small[b]);
            b = big[b];
        }
        assert(false);
    }
};

template <class E> struct HL_EXEC : HL {
    const VV<E>& g;
    V<int> tch;
    int id = 0;
    HL_EXEC(const VV<E>& _g, int r) : HL(_g.size()), g(_g), tch(g.size(), -1) {
        assert(dfs_sz(r, -1) == int(g.size()));
        dfs(r, -1);
        init_extra();
    }
    void init_extra() {
        // ord, rord, big, small
        int n = int(g.size());

        // pid, psz, pc
        int l = 0;
        while (l < n) {
            int r = l + 1;
            while (r < n && small[r] == l) r++;
            psz.push_back(r - l);
            for (int i = l; i < r; i++) {
                pid[i] = pc;
            }
            l = r;
            pc++;
        }

        // out
        for (int i = n - 1; i >= 0; i--) {
            in[i] = (i == n - 1 || ord(par(rord(i + 1))) != i) ? i + 1 : out[i + 1];
            out[i] = max(out[i], i + 1);
            int p = ord(par(rord(i)));
            if (p != -1) out[p] = max(out[p], out[i]);
        }
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

using P = pair<int, int>;
struct Node {
    using NP = Node*;
    NP l, r;
    int sz;
    P mi;
    int lz = 0;
    Node(int _sz) : sz(_sz), mi(P(0, sz)) {
        if (sz == 1) return;
        l = new Node(sz/2);
        r = new Node(sz-sz/2);
    }
    void lzdata(int x) {
        mi.first += x;
        lz += x;
    }
    void push() {
        l->lzdata(lz);
        r->lzdata(lz);
        lz = 0;
    }
    static P mrg(P a, P b) {
        P c;
        c.first = min(a.first, b.first);
        c.second = 0;
        if (c.first == a.first) c.second += a.second;
        if (c.first == b.first) c.second += b.second;
        return c;
    }
    void update() {
        mi = mrg(l->mi, r->mi);
    }

    void add(int a, int b, int x) {
        if (b <= 0 || sz <= a) return;
        if (a <= 0 && sz <= b) {
            lzdata(x);
            return;
        }
        push();
        l->add(a, b, x);
        r->add(a-sz/2, b-sz/2, x);
        update();
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;

    int n, q;
    cin >> n >> q;
    struct E { int to; };
    VV<E> g(n);
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        g[a].push_back(E{b});
        g[b].push_back(E{a});
    }
    auto hl = get_hl(g, 0);
    auto tr = new Node(n);
    set<P> st;
    for (int ph = 0; ph < q; ph++) {
        int a, b;
        cin >> a >> b; a--; b--;
        if (a > b) swap(a, b);
        int f = 0;
        if (st.count(P(a, b))) {
            st.erase(P(a, b));
            f = -1;
        } else {
            st.insert(P(a, b));
            f = 1;
        }
        int c = hl.lca(a, b);
        if (a != c && b != c) {
            tr->add(0, n, f);
            tr->add(hl.ord(a), hl.out[hl.ord(a)], -f);
            tr->add(hl.ord(b), hl.out[hl.ord(b)], -f);
        } else {
            if (a == c) swap(a, b);
            c = hl.to(b, a);
            tr->add(hl.ord(c), hl.out[hl.ord(c)], f);
            tr->add(hl.ord(a), hl.out[hl.ord(a)], -f);
        }
        P p = tr->mi;
        int x = (p.first ? 0 : p.second);
        cout << x << endl;
    }
    return 0;
}