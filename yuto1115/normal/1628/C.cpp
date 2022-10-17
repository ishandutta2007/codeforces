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
#define SORT(a) sort(all(a));
#define REV(a) reverse(all(a));
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
template<class T>
using PQ = priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>>;

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
    for (T &t: v) { is >> t; }
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
ostream &operator<<(ostream &os, const multiset<T> &st) {
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

template<class T>
vector<T> &operator+=(vector<T> &v, T x) {
    for (T &t: v) t += x;
    return v;
}

template<class T>
vector<T> &operator-=(vector<T> &v, T x) {
    for (T &t: v) t -= x;
    return v;
}

template<class T>
vector<T> &operator*=(vector<T> &v, T x) {
    for (T &t: v) t *= x;
    return v;
}

template<class T>
vector<T> &operator/=(vector<T> &v, T x) {
    for (T &t: v) t /= x;
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

template<int mod>
class modint {
    ll x;
public:
    constexpr modint(ll x = 0) : x((x % mod + mod) % mod) {}
    
    static constexpr int get_mod() { return mod; }
    
    constexpr int val() const { return x; }
    
    constexpr modint operator-() const { return modint(-x); }
    
    constexpr modint &operator+=(const modint &a) {
        if ((x += a.val()) >= mod) x -= mod;
        return *this;
    }
    
    constexpr modint &operator++() { return *this += 1; }
    
    constexpr modint &operator-=(const modint &a) {
        if ((x += mod - a.val()) >= mod) x -= mod;
        return *this;
    }
    
    constexpr modint &operator--() { return *this -= 1; }
    
    constexpr modint &operator*=(const modint &a) {
        (x *= a.val()) %= mod;
        return *this;
    }
    
    constexpr modint operator+(const modint &a) const {
        modint res(*this);
        return res += a;
    }
    
    constexpr modint operator-(const modint &a) const {
        modint res(*this);
        return res -= a;
    }
    
    constexpr modint operator*(const modint &a) const {
        modint res(*this);
        return res *= a;
    }
    
    constexpr modint pow(ll t) const {
        modint res = 1, a(*this);
        while (t > 0) {
            if (t & 1) res *= a;
            t >>= 1;
            a *= a;
        }
        return res;
    }
    
    template<int m>
    friend istream &operator>>(istream &, modint<m> &);
    
    // for prime mod
    constexpr modint inv() const { return pow(mod - 2); }
    
    constexpr modint &operator/=(const modint &a) { return *this *= a.inv(); }
    
    constexpr modint operator/(const modint &a) const {
        modint res(*this);
        return res /= a;
    }
};

using modint998244353 = modint<998244353>;
using modint1000000007 = modint<1000000007>;

template<int mod>
istream &operator>>(istream &is, modint<mod> &a) { return is >> a.x; }

template<int mod>
constexpr ostream &operator<<(ostream &os, const modint<mod> &a) { return os << a.val(); }

template<int mod>
constexpr bool operator==(const modint<mod> &a, const modint<mod> &b) { return a.val() == b.val(); }

template<int mod>
constexpr bool operator!=(const modint<mod> &a, const modint<mod> &b) { return a.val() != b.val(); }

template<int mod>
constexpr modint<mod> &operator++(modint<mod> &a) { return a += 1; }

template<int mod>
constexpr modint<mod> &operator--(modint<mod> &a) { return a -= 1; }

using mint = modint<2>;

using vm = vector<mint>;
using vvm = vector<vm>;

template<typename T>
class matrix : public vector<vector<T>> {
public:
    using vector<vector<T>>::vector;
    
    constexpr int get_h() const { return this->size(); }
    
    constexpr int get_w() const { return (get_h() ? (*this)[0].size() : 0); }
    
    constexpr matrix &operator+=(const matrix &a) {
        rep(i, get_h()) rep(j, get_w()) (*this)[i][j] += a[i][j];
        return *this;
    }
    
    constexpr matrix &operator*=(const int &k) {
        rep(i, get_h()) rep(j, get_w()) (*this)[i][j] *= k;
        return *this;
    }
    
    constexpr matrix &operator-=(const matrix &a) {
        *this += a * (-1);
        return *this;
    }
    
    constexpr matrix operator+(const matrix &a) const { return res(*this) += a; }
    
    constexpr matrix operator*(const int &k) const { return res(*this) *= k; }
    
    constexpr matrix operator-(const matrix &a) const { return res(*this) -= a; }
    
    constexpr matrix operator*(const matrix &a) const {
        int h = get_h(), w = get_w(), ah = a.get_h(), aw = a.get_w();
        assert(w == ah);
        matrix res(h, vector<T>(aw));
        rep(i, h) rep(j, w) rep(k, aw) res[i][k] += (*this)[i][j] * a[j][k];
        return res;
    }
    
    constexpr matrix &operator*=(const matrix &a) { return *this = *this * a; }
    
    constexpr matrix pow(ll t) const {
        int h = get_h(), w = get_w();
        assert(h == w);
        matrix res(h, vector<T>(w)), a(*this);
        rep(i, get_h()) res[i][i] = 1;
        while (t > 0) {
            if (t & 1) res *= a;
            t >>= 1;
            a *= a;
        }
        return res;
    }
};

using mat = matrix<mint>;

const double eps = 1e-9;

// return the rank of the matrix
// O(h * w^2)
template<class T>
int GaussJordan(matrix<T> &a, bool isExtended) {
    int rank = 0;
    rep(col, a.get_w()) {
        if (isExtended and col == a.get_w() - 1) break;
        int pivot = -1;
        rep(row, rank, a.get_h()) {
            if (a[row][col] != T(0)) pivot = row;
        }
        if (pivot == -1) continue;
        
        swap(a[pivot], a[rank]);
        
        // fix the value of pivot 1
        rrep(col2, a.get_w()) a[rank][col2] /= a[rank][col];
        
        rep(row, a.get_h()) {
            if (row == rank) continue;
            if (a[row][col] == T(0)) continue;
            T fac = a[row][col];
            rep(col2, a.get_w()) a[row][col2] -= a[rank][col2] * fac;
        }
        rank++;
    }
    return rank;
}

template<>
int GaussJordan<double>(matrix<double> &a, bool isExtended) {
    int rank = 0;
    rep(col, a.get_w()) {
        if (isExtended and col == a.get_w() - 1) break;
        int pivot = -1;
        double mx = eps;
        rep(row, rank, a.get_h()) {
            if (abs(a[row][col]) > mx) {
                mx = abs(a[row][col]);
                pivot = row;
            }
        }
        if (pivot == -1) continue;
        
        swap(a[pivot], a[rank]);
        
        // fix the value of pivot 1
        rrep(col2, a.get_w()) a[rank][col2] /= a[rank][col];
        
        rep(row, a.get_h()) {
            if (row == rank) continue;
            if (abs(a[row][col]) <= eps) continue;
            double fac = a[row][col];
            rep(col2, a.get_w()) a[row][col2] -= a[rank][col2] * fac;
        }
        rank++;
    }
    return rank;
}

// solve ax = b     reference: https://drken1215.hatenablog.com/entry/2019/03/20/202800
// if there is no solution, return empty vector
// otherwise, return one solution (all parameters is fixed 0)
// if T is mint, calculate the numbers of solutions by 'mod^(n-rank)'
// if T is mint, mod must be a prime
template<class T>
vector<T> linear_equation(const matrix<T> &a, const vector<T> &b) {
    assert(a.get_h() == (int) b.size());
    matrix<T> m(a.get_h(), vector<T>(a.get_w() + 1));
    rep(i, a.get_h()) {
        rep(j, a.get_w()) m[i][j] = a[i][j];
        m[i][a.get_w()] = b[i];
    }
    int rank = GaussJordan(m, true);
    
    vector<T> res;
    rep(row, rank, a.get_h()) {
        if (m[row][a.get_w()] != T(0)) return res;
    }
    
    res.assign(a.get_w(), 0);
    rep(i, rank) {
        rep(j, a.get_w()) {
            if (m[i][j] != T(0)) {
                res[j] = m[i][a.get_w()];
                break;
            }
        }
    }
    return res;
}

template<>
vd linear_equation<double>(const matrix<double> &a, const vector<double> &b) {
    assert(a.get_h() == (int) b.size());
    matrix<double> m(a.get_h(), vector<double>(a.get_w() + 1));
    rep(i, a.get_h()) {
        rep(j, a.get_w()) m[i][j] = a[i][j];
        m[i][a.get_w()] = b[i];
    }
    int rank = GaussJordan(m, true);
    
    vd res;
    rep(row, rank, a.get_h()) {
        if (abs(m[row][a.get_w()]) > eps) return res;
    }
    
    res.assign(a.get_w(), 0);
    rep(i, rank) {
        rep(j, a.get_w()) {
            if (abs(m[i][j]) > eps) {
                res[j] = m[i][a.get_w()];
                break;
            }
        }
    }
    return res;
}

const int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

void solve() {
    INT(n);
    vvi a(n, vi(n));
    scan(a);
    vvi v(n, vi(n));
    auto fill = [&](auto &fill, int si, int sj, int sz) -> void {
        if (sz == 2) {
            v[si][sj] = 1;
            v[si][sj + 1] = 1;
            return;
        }
        rep(i, sz) {
            v[si][sj + i] = 1;
            v[si + sz - 2][sj + i] = 1;
        }
        rep(i, 1, sz - 1) {
            v[si + 1][sj + i] = 1;
            v[si + sz - 3][sj + i] = 1;
        }
        rep(i, 2, sz - 3) {
            if (i & 1) {
                v[si + i][sj + 1] = 1;
                v[si + i][sj + 2] = 1;
                v[si + i][sj + sz - 2] = 1;
                v[si + i][sj + sz - 3] = 1;
            } else {
                v[si + i][sj + 1] = 1;
                v[si + i][sj + 0] = 1;
                v[si + i][sj + sz - 2] = 1;
                v[si + i][sj + sz - 1] = 1;
            }
        }
        if (sz >= 10) fill(fill, si + 4, sj + 4, sz - 8);
    };
    fill(fill, 0, 0, n);
    int ans = 0;
    rep(i, n) rep(j, n) if (v[i][j]) ans ^= a[i][j];
    print(ans);
//    mat a(n * n, vm(n * n));
//    rep(i, n) rep(j, n) {
//            rep(k, 4) {
//                int ni = i + dx[k];
//                int nj = j + dy[k];
//                if (ni < 0 or ni >= n or nj < 0 or nj >= n) continue;
//                a[i * n + j][ni * n + nj] = 1;
//            }
//        }
//    vm b(n * n, 1);
//    vm x = linear_equation(a, b);
//    rep(i, n) {
//        string s;
//        rep(j, n) {
//            s.pb(' ');
//            s.pb('0' + x[i * n + j].val());
//        }
//        print(s);
//    }
//    cout << endl;
}

int main() {
    int t;
    cin >> t;
    rep(i, t) solve();
}