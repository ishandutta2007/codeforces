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
ostream &operator<<(ostream &os, const deque<T> &v) {
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

template<class T>
vector<T> &operator+=(vector<T> &v, T x) {
    for (T &t : v) t += x;
    return v;
}

template<class T>
vector<T> &operator-=(vector<T> &v, T x) {
    for (T &t : v) t -= x;
    return v;
}

template<class T>
vector<T> &operator*=(vector<T> &v, T x) {
    for (T &t : v) t *= x;
    return v;
}

template<class T>
vector<T> &operator/=(vector<T> &v, T x) {
    for (T &t : v) t /= x;
    return v;
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

void rearrange(const vi &) {}

template<class T, class... Tail>
void rearrange(const vi &ord, vector<T> &head, Tail &...tail) {
    assert(ord.size() == head.size());
    vector<T> ori = head;
    rep(i, ord.size()) head[i] = ori[ord[i]];
    rearrange(ord, tail...);
}

template<class T, class... Tail>
void sort_by(vector<T> &head, Tail &... tail) {
    vi ord(head.size());
    iota(all(ord), 0);
    sort(all(ord), [&](int i, int j) { return head[i] < head[j]; });
    rearrange(ord, head, tail...);
}

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

template<typename T>
class BIT {
    int n;
    vector<T> val;
public:
    BIT(int n) : n(n), val(n + 1, 0) {}
    
    void add(int i, T x = 1) {
        i++;
        while (i <= n) {
            val[i] += x;
            i += i & -i;
        }
    }
    
    T sum(int i) {
        T ret = 0;
        i++;
        while (i > 0) {
            ret += val[i];
            i -= i & -i;
        }
        return ret;
    }
    
    // [l, r)
    T sum(int l, int r) { return sum(r - 1) - sum(l - 1); }
};

int main() {
    INT(n, q, k);
    vi a(n);
    cin >> a;
    vi l(q), r(q);
    vvp qs(n);
    rep(i, q) {
        scan(l[i], r[i]);
        --l[i];
        qs[l[i]].eb(r[i], i);
    }
    ll all = 0;
    BIT<ll> adi(k + 1);
    deque<int> dq;
    auto add = [&](int i) {
        int nx = (dq.size() ? dq.front() : n);
        int t = (nx - i) / k;
        all += (ll) a[i] * t;
        int num = (nx - i) % k;
        int s = i % k;
        if (s + num <= k) {
            adi.add(s, a[i]);
            adi.add(s + num, -a[i]);
        } else {
            adi.add(s, a[i]);
            adi.add(0, a[i]);
            adi.add((s + num) % k, -a[i]);
        }
    };
    auto del = [&](int i) {
        int nx = (dq.size() ? dq.front() : n);
        int t = (nx - i) / k;
        all -= (ll) a[i] * t;
        int num = (nx - i) % k;
        int s = i % k;
        if (s + num <= k) {
            adi.add(s, -a[i]);
            adi.add(s + num, a[i]);
        } else {
            adi.add(s, -a[i]);
            adi.add(0, -a[i]);
            adi.add((s + num) % k, a[i]);
        }
    };
    vvi ask(n);
    rrep(i, n) {
        while (dq.size() and a[dq.front()] >= a[i]) {
            dq.ppf();
        }
        dq.pf(i);
        for (auto[nr, _] : qs[i]) {
            int last = *prev(lower_bound(all(dq), nr));
            ask[last].pb(i % k);
        }
    }
    dq.clear();
    vector<map<int, ll>> res(n);
    vl ans(q);
    rrep(i, n) {
        while (dq.size() and a[dq.front()] >= a[i]) {
            int last = dq.front();
            dq.ppf();
            del(last);
        }
        add(i);
        dq.pf(i);
        sort(all(ask[i]));
        ask[i].erase(unique(all(ask[i])), ask[i].end());
        for (int j : ask[i]) {
            res[i][j] = all + adi.sum(j);
        }
        for (auto[nr, id] : qs[i]) {
            ans[id] += all + adi.sum(i % k);
            int last = *prev(lower_bound(all(dq), nr));
            ans[id] -= res[last][i % k];
            int lb = (last - i + k - 1) / k;
            int rb = (nr - i + k - 1) / k;
            ans[id] += (ll) a[last] * (rb - lb);
        }
    }
    vecout(ans);
}