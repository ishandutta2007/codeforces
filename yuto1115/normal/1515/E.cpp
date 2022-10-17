//@formatter:off
#include<bits/stdc++.h>
#define overload4(_1,_2,_3,_4,name,...) name
#define rep1(i,n) for (ll i = 0; i < ll(n); ++i)
#define rep2(i,s,n) for (ll i = ll(s); i < ll(n); ++i)
#define rep3(i,s,n,d) for(ll i = ll(s); i < ll(n); i+=d)
#define rep(...) overload4(__VA_ARGS__,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep1(i,n) for (ll i = ll(n)-1; i >= 0; i--)
#define rrep2(i,n,t) for (ll i = ll(n)-1; i >= (ll)t; i--)
#define rrep3(i,n,t,d) for (ll i = ll(n)-1; i >= (ll)t; i-=d)
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
using P = pair<int,int>;
using LP = pair<ll,ll>;
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
template<class S,class T> istream& operator>>(istream &is,pair<S,T> &p) { return is >> p.first >> p.second; }
template<class S,class T> ostream& operator<<(ostream &os,const pair<S,T> &p) { return os<<'{'<<p.first<<","<<p.second<<'}'; }
template<class T> istream& operator>>(istream &is,vector<T> &v) { for(T &t:v){is>>t;} return is; }
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) { os<<'[';rep(i,v.size())os<<v[i]<<(i==int(v.size()-1)?"":","); return os<<']'; }
template<class T> void vecout(const vector<T> &v,char div='\n') { rep(i,v.size()) cout<<v[i]<<(i==int(v.size()-1)?'\n':div);}
template<class T> bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
void scan(){}
template<class Head, class... Tail> void scan(Head& head, Tail&... tail){ cin >> head; scan(tail...); }
template<class T> void print(const T& t){ cout << t << '\n'; }
template<class Head, class... Tail> void print(const Head& head, const Tail&... tail){ cout<<head<<' '; print(tail...); }
template<class... T> void fin(const T&... a) { print(a...); exit(0); }
struct Init_io {
    Init_io() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        cout << boolalpha << fixed << setprecision(15);
    }
} init_io;
const string yes[] = {"no","yes"};
const string Yes[] = {"No","Yes"};
const string YES[] = {"NO","YES"};
const int inf = 1001001001;
const ll linf = 1001001001001001001;
//@formatter:on

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

class combination {
    vector<mint> fact, ifact;
public:
    combination(int n) : fact(n + 1), ifact(n + 1) {
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
    }
    
    mint operator()(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * ifact[k] * ifact[n - k];
    }
};

int main() {
    INT(n, m);
    mint::set_mod(m);
    mint dp[410][410];
    combination comb(500);
    vm v(n + 1);
    rep(i, 1, n + 1) {
        rep(j, i) {
            v[i] += comb(i - 1, j);
        }
    }
    debug(v);
    rep(i, 1, n + 1) dp[i][i] += v[i];
    rep(i, n) rep(j, i + 1) {
            mint now = dp[i][j];
            if (!now.val()) continue;
            rep(k, 2, n - i + 1) {
                dp[i + k][j + k - 1] += now * comb(j + k - 1, k - 1) * v[k - 1];
            }
        }
    mint ans = 0;
    rep(i, n + 1) ans += dp[n][i];
    fin(ans);
}