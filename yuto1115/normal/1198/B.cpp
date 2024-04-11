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
#define SZ(a) int(a.size())
#define popcount(x) __builtin_popcountll(x)
#define pf push_front
#define pb push_back
#define ef emplace_front
#define eb emplace_back
#define ppf pop_front
#define ppb pop_back
#ifdef __LOCAL
#define debug(...) { cout << #__VA_ARGS__; cout << ": "; print(__VA_ARGS__); cout << flush; }
#else
#define debug(...) void(0);
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
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vvvl = vector<vvl>;
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
    for (T &t : v) { is >> t; }
    return is;
}

template<class T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    os << '[';
    rep(i, v.size()) os << v[i] << (i == int(v.size() - 1) ? "" : ", ");
    return os << ']';
}

template<class T>
ostream &operator<<(ostream &os, const set<T> &st) {
    os << '{';
    auto it = st.begin();
    while (it != st.end()) {
        os << (it == st.begin() ? "" : ", ") << *it;
        it++;
    }
    return os << '}';
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

template<class M>
class lazy_segtree {
    using S = typename M::S;
    using F = typename M::F;
    
    int _n, sz, log;
    vector<S> d;
    vector<F> lz;
    
    void update(int k) { d[k] = M::op(d[2 * k], d[2 * k + 1]); }
    
    void all_apply(int k, F f) {
        d[k] = M::mapping(f, d[k]);
        if (k < sz) lz[k] = M::composition(f, lz[k]);
    }
    
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = M::id;
    }

public:
    constexpr lazy_segtree() : lazy_segtree(0) {}
    
    constexpr lazy_segtree(int _n) : lazy_segtree(vector<S>(_n, M::e)) {}
    
    constexpr lazy_segtree(const vector<S> &init) : _n(int(init.size())) {
        log = 0;
        while (1 << log < _n) log++;
        sz = 1 << log;
        d.assign(2 * sz, M::e);
        lz.assign(sz, M::id);
        rep(i, _n) d[sz + i] = init[i];
        rrep(i, sz, 1) update(i);
    }
    
    void set(int p, S x) {
        assert(0 <= p and p < _n);
        p += sz;
        rrep(i, log + 1, 1) push(p >> i);
        d[p] = x;
        rep(i, 1, log + 1) update(p >> i);
    }
    
    S get(int p) {
        assert(0 <= p and p < _n);
        p += sz;
        rrep(i, log + 1, 1) push(p >> i);
        return d[p];
    }
    
    S prod(int l, int r) {
        assert(0 <= l and l <= r and r <= _n);
        
        l += sz, r += sz;
        
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
    
    S all_prod() {
        return d[1];
    }
    
    void apply(int l, int r, F f) {
        assert(0 <= l and l <= r and r <= _n);
        
        l += sz, r += sz;
        
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
    
    template<class F>
    int max_right(int l, F f) {
        assert(0 <= l && l <= _n);
        assert(f(M::e));
        if (l == _n) return _n;
        l += sz;
        rrep(i, log + 1, 1) push(l >> i);
        S now = M::e;
        do {
            while (~l & 1) l >>= 1;
            if (!f(M::op(now, d[l]))) {
                while (l < sz) {
                    push(l);
                    l *= 2;
                    if (f(M::op(now, d[l]))) {
                        now = M::op(now, d[l]);
                        ++l;
                    }
                }
                return l - sz;
            }
            now = M::op(now, d[l]);
            ++l;
        } while ((l & -l) != l);
        return _n;
    }
    
    template<class F>
    int min_left(int r, F f) {
        assert(0 <= r && r <= _n);
        assert(f(M::e));
        if (r == 0) return 0;
        r += sz;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S now = M::e;
        do {
            r--;
            while (r > 1 && (r & 1)) r >>= 1;
            if (!f(M::op(d[r], now))) {
                while (r < sz) {
                    push(r);
                    r = 2 * r + 1;
                    if (f(M::op(d[r], now))) {
                        now = M::op(d[r], now);
                        --r;
                    }
                }
                return r + 1 - sz;
            }
            now = M::op(d[r], now);
        } while ((r & -r) != r);
        return 0;
    }
};

class M {
public:
    using S = int;
    
    static constexpr S e = -1;
    
    static constexpr S op(const S &l, const S &r) {
        return max(l, r);
    }
    
    using F = int;
    
    static constexpr F id = -1;
    
    static constexpr F composition(const F &g, const F &f) {
        return max(g, f);
    }
    
    static constexpr S mapping(const F &f, const S &x) {
        return max(f, x);
    }
};

int main() {
    INT(n);
    vi a(n);
    cin >> a;
    lazy_segtree<M> st(a);
    INT(q);
    while (q--) {
        INT(t);
        if (t == 1) {
            INT(p, x);
            --p;
            st.set(p, x);
        } else {
            INT(x);
            st.apply(0, n, x);
        }
    }
    vi ans(n);
    rep(i, n) ans[i] = st.get(i);
    vecout(ans, ' ');
}