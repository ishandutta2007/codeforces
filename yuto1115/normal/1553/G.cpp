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

class sieve {
    int n;
    vi val;
    
    void init() {
        rep(i, n + 1) val[i] = i;
        for (int i = 2; i * i <= n; i++) {
            if (val[i] != i) continue;
            for (int j = i * 2; j <= n; j += i) {
                if (val[j] == j) val[j] = i;
            }
        }
    }

public:
    sieve(int n) : n(n), val(n + 1) {
        init();
    }
    
    map<int, int> factor_list(int x) {
        if (n < 2) return {};
        map<int, int> ret;
        int now = x;
        while (now > 1) {
            ret[val[now]]++;
            now /= val[now];
        }
        return ret;
    }
    
    vi unique_factor(int x) {
        map<int, int> m = factor_list(x);
        vi ret;
        for (P p : m) ret.pb(p.first);
        return ret;
    };
    
    bool is_prime(int x) {
        return x >= 2 and val[x] == x;
    }
    
    int count_divisor(int x) {
        int ret = 1;
        map<int, int> fl = factor_list(x);
        for (auto p : fl) ret *= p.second + 1;
        return ret;
    };
    
    vi prime_list() {
        vi res;
        rep(i, 2, n + 1) if (is_prime(i)) res.pb(i);
        return res;
    }
} sv(2000010);

int main() {
    INT(n, q);
    vi a(n);
    cin >> a;
    vi ps = sv.prime_list();
    int sz = ps.size();
    unionfind uf(sz);
    vvi ori(n), add(n);
    rep(i, n) {
        ori[i] = sv.unique_factor(a[i]);
        add[i] = sv.unique_factor(a[i] + 1);
        for (int &j : ori[i]) j = lower_bound(all(ps), j) - ps.begin();
        for (int &j : add[i]) j = lower_bound(all(ps), j) - ps.begin();
        rep(j, ori[i].size() - 1) uf.merge(ori[i][j], ori[i][j + 1]);
    }
    vi rs(sz);
    rep(i, sz) rs[i] = uf.root(i);
    set<P> st;
    auto ad = [&](int i, int j) {
        if (i == j) return;
        if (i > j) swap(i, j);
        st.insert({i, j});
    };
    auto ch = [&](int i, int j) {
        if (i > j) swap(i, j);
        return st.count({i, j});
    };
    rep(i, n) {
        for (int k : add[i]) ad(rs[ori[i][0]], rs[k]);
        for (int j : add[i]) for (int k : add[i]) ad(rs[j], rs[k]);
    }
    rep(_, q) {
        INT(s, t);
        --s, --t;
        s = rs[ori[s][0]];
        t = rs[ori[t][0]];
        if (s == t) print(0);
        else if (ch(s, t)) print(1);
        else print(2);
    }
}