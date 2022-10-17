#include<bits/stdc++.h>
#define overload4(_1, _2, _3, _4, name, ...) name
#define rep1(i, n) for (ll i = 0; i < ll(n); ++i)
#define rep2(i, s, n) for (ll i = ll(s); i < ll(n); ++i)
#define rep3(i, s, n, d) for(ll i = ll(s); i < ll(n); i+=d)
#define rep(...) overload4(__VA_ARGS__,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep1(i, n) for (ll i = ll(n)-1; i >= 0; i--)
#define rrep2(i, n, t) for (ll i = ll(n)-1; i >= (ll)t; i--)
#define rrep3(i, n, t, d) for (ll i = ll(n)-1; i >= (ll)t; i-=d)
#define rrep(...) overload4(__VA_ARGS__,rrep3,rrep2,rrep1)(__VA_ARGS__)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define SUM(a) accumulate(all(a),0LL)
#define MIN(a) *min_element(all(a))
#define MAX(a) *max_element(all(a))
#define popcount(x) __builtin_popcountll(x)
#define pb push_back
#define eb emplace_back
#ifdef __LOCAL
#define debug(...) { cout << #__VA_ARGS__; cout << ": "; print(__VA_ARGS__); cout << flush; }
#else
#define debug(...) void(0)
#endif
#define INT(...) int __VA_ARGS__;scan(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;scan(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;scan(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;scan(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;scan(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;scan(__VA_ARGS__)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using LP = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vd = vector<double>;
using vvd = vector<vd>;
using vs = vector<string>;
using vc = vector<char>;
using vvc = vector<vc>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vp = vector<P>;
using vvp = vector<vp>;

template<class S, class T>
istream &operator>>(istream &is, pair<S, T> &p) { return is >> p.first >> p.second; }

template<class S, class T>
ostream &operator<<(ostream &os, const pair<S, T> &p) { return os << '{' << p.first << ", " << p.second << '}'; }

template<class S, class T, class U>
istream &operator>>(istream &is, tuple<S, T, U> &t) { return is >> get<0>(t) >> get<1>(t) >> get<2>(t); }

template<class S, class T, class U>
ostream &operator<<(ostream &os, const tuple<S, T, U> &t) {
    return os << '{' << get<0>(t) << ", " << get<1>(t) << ", " << get<2>(t) << '}';
}

template<class T>
istream &operator>>(istream &is, vector<T> &v) {
    for (T &t:v) { is >> t; }
    return is;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << '[';
    rep(i, v.size())os << v[i] << (i == int(v.size() - 1) ? "" : ", ");
    return os << ']';
}

template<class T>
void vecout(const vector<T> &v, char div = '\n') {
    rep(i, v.size()) cout << v[i] << (i == int(v.size() - 1) ? '\n' : div);
}

template<class T>
bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

void scan() {}

template<class Head, class... Tail>
void scan(Head &head, Tail &... tail) {
    cin >> head;
    scan(tail...);
}

template<class T>
void print(const T &t) { cout << t << '\n'; }

template<class Head, class... Tail>
void print(const Head &head, const Tail &... tail) {
    cout << head << ' ';
    print(tail...);
}

template<class... T>
void fin(const T &... a) {
    print(a...);
    exit(0);
}

struct Init_io {
    Init_io() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        cout << boolalpha << fixed << setprecision(15);
        cerr << boolalpha << fixed << setprecision(15);
    }
} init_io;

const string yes[] = {"no", "yes"};
const string Yes[] = {"No", "Yes"};
const string YES[] = {"NO", "YES"};
const int inf = 1001001001;
const ll linf = 1001001001001001001;

template<class T, class S>
vector<T> cumsum(const vector<S> &v, bool shift_one = true) {
    int n = v.size();
    vector<T> res;
    if (shift_one) {
        res.resize(n + 1);
        rep(i, n) res[i + 1] = res[i] + v[i];
    } else {
        res.resize(n);
        if (n) {
            res[0] = v[0];
            rep(i, 1, n) res[i] = res[i - 1] + v[i];
        }
    }
    return res;
}

vvi graph(int n, int m, bool directed = false, int origin = 1) {
    vvi G(n);
    rep(_, m) {
        INT(u, v);
        u -= origin, v -= origin;
        G[u].pb(v);
        if (!directed) G[v].pb(u);
    }
    return G;
}

template<class T>
vector<vector<pair<int, T>>> weighted_graph(int n, int m, bool directed = false, int origin = 1) {
    vector<vector<pair<int, T>>> G(n);
    rep(_, m) {
        int u, v;
        T w;
        scan(u, v, w);
        u -= origin, v -= origin;
        G[u].eb(v, w);
        if (!directed) G[v].eb(u, w);
    }
    return G;
}

class unionfind {
    int n;
    vector<int> par, rank;
public:
    unionfind(int n) : n(n), par(n, -1), rank(n, 0) {}
    
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool is_root(int x) { return root(x) == x; }
    
    bool same(int x, int y) { return root(x) == root(y); };
    
    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) rank[x]++;
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) { return -par[root(x)]; };
    
    vi roots() {
        vi res;
        rep(i, n) if (root(i) == i) res.pb(i);
        return res;
    }
    
    bool connected() {
        return roots().size() == 1;
    }
};

template<class M>
class lazy_segtree {
    using S = typename M::S;
    using F = typename M::F;
    
    int n, log;
    vector<S> d;
    vector<F> lz;
    
    void update(int k) { d[k] = M::op(d[2 * k], d[2 * k + 1]); }
    
    void all_apply(int k, F f) {
        d[k] = M::mapping(f, d[k]);
        if (k < n) lz[k] = M::composition(f, lz[k]);
    }
    
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = M::id;
    }

public:
    constexpr lazy_segtree() : lazy_segtree(0) {}
    
    constexpr lazy_segtree(int _n) : lazy_segtree(vector<S>(_n, M::e)) {}
    
    constexpr lazy_segtree(const vector<S> &v) {
        log = 0;
        while (1 << log < (int) v.size()) log++;
        n = 1 << log;
        d.assign(2 * n, M::e);
        lz.assign(n, M::id);
        rep(i, v.size()) d[n + i] = v[i];
        rrep(i, n, 1) update(i);
    }
    
    void set(int p, S x) {
        assert(0 <= p and p < n);
        p += n;
        rrep(i, log + 1, 1) push(p >> i);
        d[p] = x;
        rep(i, 1, log + 1) update(p >> i);
    }
    
    S get(int p) {
        assert(0 <= p and p < n);
        p += n;
        rrep(i, log + 1, 1) push(p >> i);
        return d[p];
    }
    
    S prod(int l, int r) {
        assert(0 <= l and l <= r and r <= n);
        
        l += n, r += n;
        
        rrep(i, log + 1, 1) {
            if ((l >> i) << i != l) push(l >> i);
            if ((r >> i) << i != r) push(r >> i);
        }
        
        S sl = M::e, sr = M::e;
        while (l < r) {
            if (l & 1) sl = M::op(sl, d[l++]);
            if (r & 1) sr = M::op(d[--r], sr);
            l >>= 1, r >>= 1;
        }
        
        return M::op(sl, sr);
    }
    
    void apply(int l, int r, F f) {
        assert(0 <= l and l <= r and r <= n);
        
        l += n, r += n;
        
        rrep(i, log + 1, 1) {
            if ((l >> i) << i != l) push(l >> i);
            if ((r >> i) << i != r) push(r >> i);
        }
        
        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1, r >>= 1;
            }
            l = l2, r = r2;
        }
        
        rep(i, 1, log + 1) {
            if ((l >> i) << i != l) update(l >> i);
            if ((r >> i) << i != r) update(r >> i);
        }
    }
};

class M {
public:
    using S = int;
    
    static constexpr S e = 0;
    
    static constexpr S op(const S &l, const S &r) {
        return l + r;
    }
    
    using F = int;
    
    static constexpr F id = 0;
    
    static constexpr F composition(const F &g, const F &f) {
        return g + f;
    }
    
    static constexpr S mapping(const F &f, const S &x) {
        return f + x;
    }
};

// Heavy Light Decomposition
class HLD {
    vvi G;
    int n;
    vi sz, in, out, head, rev, par;
    
    void dfs_sz(int u, int p) {
        par[u] = p;
        sz[u] = 1;
        if (G[u].size() and G[u][0] == p) swap(G[u][0], G[u].back());
        for (int &v : G[u]) {
            if (v == p) continue;
            dfs_sz(v, u);
            sz[u] += sz[v];
            if (sz[G[u][0]] < sz[v]) swap(G[u][0], v);
        }
    }
    
    void dfs_hld(int u, int p, int &t) {
        in[u] = t++;
        rev[in[u]] = u;
        for (int v : G[u]) {
            if (v == p) continue;
            head[v] = (G[u][0] == v ? head[u] : v);
            dfs_hld(v, u, t);
        }
        out[u] = t;
    }
    
    void init() {
        n = G.size();
        sz.resize(n);
        in.resize(n);
        out.resize(n);
        head.resize(n);
        rev.resize(n);
        par.resize(n);
        rep(i, n) if (!sz[i]) dfs_sz(0, -1);
        int t = 0;
        dfs_hld(0, -1, t);
    }

public:
    HLD(const vvi &G) : G(G) {
        init();
    }
    
    // go up by k times from vertex v
    int la(int v, int k) {
        while (true) {
            int u = head[v];
            if (in[v] - k >= in[u]) return rev[in[v] - k];
            k -= in[v] - in[u] + 1;
            v = par[u];
        }
    }
    
    int lca(int u, int v) {
        for (;; v = par[head[v]]) {
            if (in[u] > in[v]) swap(u, v);
            if (head[u] == head[v]) return u;
        }
    }

//    e -> identity element
//    q -> query to the line
//    f -> function to merge lines
//    q and f must be commutative i.e. q(l,r) = q(r,l)
//    set edge true for query to edges
    template<class T, class Q, class F>
    T fold(int u, int v, const T &e, const Q &q, const F &f, bool edge) {
        T l = e, r = e;
        for (;; v = par[head[v]]) {
            if (in[u] > in[v]) swap(u, v), swap(l, r);
            if (head[u] == head[v]) break;
            l = f(q(in[head[v]], in[v] + 1), l);
        }
        return f(f(q(in[u] + edge, in[v] + 1), l), r);
    }
    
    template<class F>
    void update(int u, int v, const F &f, bool edge) {
        for (;; v = par[head[v]]) {
            if (in[u] > in[v]) swap(u, v);
            if (head[u] == head[v]) break;
            f(in[head[v]], in[v] + 1);
        }
        f(in[u] + edge, in[v] + 1);
    }
    
    int get_id(int i) {
        return in[i];
    }
};

int main() {
    INT(n, q);
    unionfind uf(n);
    vvp G(n);
    vvi hg(n);
    vb used(q);
    vi u(q), v(q), x(q);
    rep(i, q) {
        scan(u[i], v[i], x[i]);
        --u[i], --v[i];
        if (!uf.same(u[i], v[i])) {
            G[u[i]].eb(v[i], x[i]);
            G[v[i]].eb(u[i], x[i]);
            hg[u[i]].pb(v[i]);
            hg[v[i]].pb(u[i]);
            used[i] = true;
            uf.merge(u[i], v[i]);
        }
    }
    vi rs;
    rep(i, n) if (uf.is_root(i)) rs.pb(i);
    rep(i, 1, rs.size()) {
        G[rs[0]].eb(rs[i], 0);
        G[rs[i]].eb(rs[0], 0);
        hg[rs[0]].pb(rs[i]);
        hg[rs[i]].pb(rs[0]);
    }
    vi rx(n);
    auto dfs = [&](auto &dfs, int nu, int p, int nx) -> void {
        rx[nu] = nx;
        for (auto[nv, w] : G[nu]) {
            if (nv == p) continue;
            dfs(dfs, nv, nu, nx ^ w);
        }
    };
    dfs(dfs, 0, -1, 0);
    HLD hld(hg);
    lazy_segtree<M> st(n);
    rep(i, q) {
        if (used[i]) {
            print("YES");
            continue;
        }
        if ((rx[u[i]] ^ rx[v[i]] ^ x[i]) != 1) {
            print("NO");
            continue;
        }
        if (hld.fold(u[i], v[i], 0, [&](int l, int r) { return st.prod(l, r); }, [&](int l, int r) { return l + r; },
                     true) > 0) {
            print("NO");
            continue;
        }
        print("YES");
        hld.update(u[i], v[i], [&](int l, int r) { st.apply(l, r, 1); }, true);
    }
}