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

class dynamic_modint {
    ll x;
    static int mod;
public:
    static void set_mod(int _mod) { mod = _mod; }
    
    dynamic_modint(ll x = 0) : x((x % mod + mod) % mod) { assert(mod > 0); }
    
    static int get_mod() { return mod; }
    
    constexpr int val() const { return x; }
    
    dynamic_modint operator-() const { return dynamic_modint(-x); }
    
    dynamic_modint &operator+=(const dynamic_modint &a) {
        if ((x += a.val()) >= mod) x -= mod;
        return *this;
    }
    
    dynamic_modint &operator++() { return *this += 1; }
    
    dynamic_modint &operator-=(const dynamic_modint &a) {
        if ((x += mod - a.val()) >= mod) x -= mod;
        return *this;
    }
    
    dynamic_modint &operator--() { return *this -= 1; }
    
    dynamic_modint &operator*=(const dynamic_modint &a) {
        (x *= a.val()) %= mod;
        return *this;
    }
    
    dynamic_modint operator+(const dynamic_modint &a) const {
        dynamic_modint res(*this);
        return res += a;
    }
    
    dynamic_modint operator-(const dynamic_modint &a) const {
        dynamic_modint res(*this);
        return res -= a;
    }
    
    dynamic_modint operator*(const dynamic_modint &a) const {
        dynamic_modint res(*this);
        return res *= a;
    }
    
    dynamic_modint pow(ll t) const {
        dynamic_modint res = 1, a(*this);
        while (t > 0) {
            if (t & 1) res *= a;
            t >>= 1;
            a *= a;
        }
        return res;
    }
    
    friend istream &operator>>(istream &is, dynamic_modint &a);
    
    // for prime mod
    dynamic_modint inv() const { return pow(mod - 2); }
    
    dynamic_modint &operator/=(const dynamic_modint &a) { return *this *= a.inv(); }
    
    dynamic_modint operator/(const dynamic_modint &a) const {
        dynamic_modint res(*this);
        return res /= a;
    }
};

int dynamic_modint::mod = 0;

ostream &operator<<(ostream &os, const dynamic_modint &a) { return os << a.val(); }

bool operator==(const dynamic_modint &a, const dynamic_modint &b) { return a.val() == b.val(); }

bool operator!=(const dynamic_modint &a, const dynamic_modint &b) { return a.val() != b.val(); }

dynamic_modint &operator++(dynamic_modint &a) { return a += 1; }

dynamic_modint &operator--(dynamic_modint &a) { return a -= 1; }

using mint = dynamic_modint;

using vm = vector<mint>;
using vvm = vector<vm>;

int main() {
    INT(m, n);
    mint::set_mod(m);
    vi a(n);
    cin >> a;
    if (n == 1) fin(a[0], 1);
    if (n == m) fin(0, 1);
    mint sum = 0, sum2 = 0;
    for (int i : a) sum += i, sum2 += (ll) i * i;
    for (int x : a) {
        mint d1 = (sum / n - x) * 2 / (n - 1);
        if (!d1.val()) continue;
        if (sum2 != mint(n) * x * x + d1 * n * (n - 1) * x + d1 * d1 * (n - 1) * n * (2 * n - 1) / 6) continue;
        debug(x, d1);
        bool ok = true;
        for (int i : a) ok &= (mint(i - x) / d1).val() < n;
        if (ok) fin(x, d1);
    }
    fin(-1);
}