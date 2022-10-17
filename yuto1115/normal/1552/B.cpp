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

template<class Monoid>
class segtree {
    using S = typename Monoid::S;
    
    int n;
    vector<S> val;

public:
    constexpr segtree(const vector<S> &init = vector<S>()) {
        int _n = init.size();
        n = 1;
        while (n < _n) n *= 2;
        val.assign(n * 2, Monoid::identity);
        rep(i, _n) val[i + n] = init[i];
        rrep(i, n) val[i] = Monoid::operate(val[i * 2], val[i * 2 + 1]);
    }
    
    constexpr segtree(int _n) : segtree(vector<S>(_n, Monoid::identity)) {}
    
    // segment [l,r)
    S prod(int l, int r) {
        l += n, r += n;
        S prod_l = Monoid::identity;
        S prod_r = Monoid::identity;
        while (l < r) {
            if (l & 1) prod_l = Monoid::operate(prod_l, val[l++]);
            if (r & 1) prod_r = Monoid::operate(val[--r], prod_r);
            l >>= 1, r >>= 1;
        }
        return Monoid::operate(prod_l, prod_r);
    }
    
    template<class F>
    void update(int i, const F &f) {
        i += n;
        val[i] = f(val[i]);
        while (i > 1) {
            i >>= 1;
            val[i] = Monoid::operate(val[i * 2], val[i * 2 + 1]);
        }
    }
    
    S get(int i) {
        assert(i >= 0 and i < n);
        return val[i + n];
    }
};

class M {
public:
    using S = int;
    
    static constexpr S identity = inf;
    
    static constexpr S operate(const S &l, const S &r) {
        return min(l, r);
    }
};

void solve() {
    INT(n);
    vvi r(n, vi(5));
    cin >> r;
    rep(i, 5) {
        vi zip;
        rep(j, n) zip.pb(r[j][i]);
        sort(all(zip));
        rep(j, n) r[j][i] = lower_bound(all(zip), r[j][i]) - zip.begin();
    }
    vb ok(n, true);
    rep(bit, 1 << 5) {
        vi v;
        rep(j, 5) if (bit >> j & 1) v.pb(j);
        if (v.size() != 3) continue;
        segtree<M> st(n);
        vi ord(n);
        iota(all(ord), 0);
        sort(all(ord), [&](int i, int j) { return r[i][v[0]] < r[j][v[0]]; });
        rep(i, n) {
            if (st.prod(0, r[ord[i]][v[1]]) < r[ord[i]][v[2]]) ok[ord[i]] = false;
            st.update(r[ord[i]][v[1]], [&](int pre) { return min(pre, r[ord[i]][v[2]]); });
        }
    }
    rep(i, n) if (ok[i]) {
            print(i + 1);
            return;
        }
    print(-1);
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
}