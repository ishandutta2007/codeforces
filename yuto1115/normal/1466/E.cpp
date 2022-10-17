//@formatter:off
#include<bits/stdc++.h>
#define overload4(_1,_2,_3,_4,name,...) name
#define rep1(i,n) for (ll i = 0; i < ll(n); ++i)
#define rep2(i,s,n) for (ll i = ll(s); i < ll(n); ++i)
#define rep3(i,s,n,d) for(ll i = ll(s); i < ll(n); i+=d)
#define rep(...) overload4(__VA_ARGS__,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep(i,n) for (ll i = ll(n)-1; i >= 0; i--)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vp vector<P>
#define vvp vector<vector<P>>
#ifdef __LOCAL
#define debug(...) { cout << #__VA_ARGS__; cout << ": "; print(__VA_ARGS__); }
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
using P = pair<int,int>;
using LP = pair<ll,ll>;
template<class S,class T> istream& operator>>(istream &is,pair<S,T> &p) { return is >> p.first >> p.second; }
template<class S,class T> ostream& operator<<(ostream &os,const pair<S,T> &p) { return os<<'{'<<p.first<<","<<p.second<<'}'; }
template<class T> istream& operator>>(istream &is,vector<T> &v) { for(T &t:v){is>>t;} return is; }
template<class T> ostream& operator<<(ostream &os,const vector<T> &v) { os<<'[';rep(i,v.size())os<<v[i]<<(i==int(v.size()-1)?"":","); return os<<']'; }
void Yes(bool b) { cout << (b ? "Yes" : "No") << '\n'; }
void YES(bool b) { cout << (b ? "YES" : "NO") << '\n'; }
template<class T> bool chmin(T& a,T b) {if(a > b){a = b; return true;} return false;}
template<class T> bool chmax(T& a,T b) {if(a < b){a = b; return true;} return false;}
void scan(){}
template <class Head, class... Tail> void scan(Head& head, Tail&... tail){ cin >> head; scan(tail...); }
template<class T> void print(const T& t){ cout << t << '\n'; }
template <class Head, class... Tail> void print(const Head& head, const Tail&... tail){ cout<<head<<' '; print(tail...); }
const int inf = 1001001001;
const ll linf = 1001001001001001001;
//@formatter:on

constexpr int mod = 1000000007;

//constexpr int mod = 998244353;
struct mint {
    ll x;
    
    constexpr mint(ll x = 0) : x((x % mod + mod) % mod) {}
    
    constexpr mint operator-() const { return mint(-x); }
    
    constexpr mint &operator+=(const mint &a) {
        if ((x += a.x) >= mod) x -= mod;
        return *this;
    }
    
    constexpr mint &operator++() { return *this += mint(1); }
    
    constexpr mint &operator-=(const mint &a) {
        if ((x += mod - a.x) >= mod) x -= mod;
        return *this;
    }
    
    constexpr mint &operator--() { return *this -= mint(1); }
    
    constexpr mint &operator*=(const mint &a) {
        (x *= a.x) %= mod;
        return *this;
    }
    
    constexpr mint operator+(const mint &a) const {
        mint res(*this);
        return res += a;
    }
    
    constexpr mint operator-(const mint &a) const {
        mint res(*this);
        return res -= a;
    }
    
    constexpr mint operator*(const mint &a) const {
        mint res(*this);
        return res *= a;
    }
    
    constexpr mint pow(ll t) const {
        mint res = mint(1), a(*this);
        while (t > 0) {
            if (t & 1) res *= a;
            t >>= 1;
            a *= a;
        }
        return res;
    }
    
    // for prime mod
    constexpr mint inv() const { return pow(mod - 2); }
    
    constexpr mint &operator/=(const mint &a) { return *this *= a.inv(); }
    
    constexpr mint operator/(const mint &a) const {
        mint res(*this);
        return res /= a;
    }
};

ostream &operator<<(ostream &os, const mint &a) { return os << a.x; }

bool operator==(const mint &a, const mint &b) { return a.x == b.x; }

bool operator!=(const mint &a, const mint &b) { return a.x != b.x; }

bool operator==(const mint &a, const int &b) { return a.x == b; }

bool operator!=(const mint &a, const int &b) { return a.x != b; }

void solve() {
    INT(n);
    vl x(n);
    cin >> x;
    vi cnt(60);
    rep(i, n) {
        ll now = x[i];
        rep(j, 60) {
            if (now & 1) cnt[j]++;
            now >>= 1;
        }
    }
    mint ans = 0;
    rep(j, n) {
        mint si = 0, sk = 0;
        mint p = 1;
        rep(i, 60) {
            if (x[j] >> i & 1) {
                si += p * cnt[i];
            } else {
                sk += p * cnt[i];
            }
            p *= 2;
        }
        sk += mint(x[j]) * n;
        ans += si * sk;
    }
    print(ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    rep(i, t) solve();
}