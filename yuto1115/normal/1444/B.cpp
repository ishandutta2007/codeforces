//@formatter:off
#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < int(n); ++i)
#define rrep(i,n) for (int i = int(n)-1; i >= 0; i--)
#define rep2(i,s,n) for (int i = int(s); i < int(n); ++i)
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
const int inf = 1001001001;
const ll linf = 1001001001001001001;
//@formatter:on

//constexpr int mod = 1000000007;
constexpr int mod = 998244353;

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

class combination {
    vector<mint> fact, ifact;
public:
    combination(int n) : fact(n + 1), ifact(n + 1) {
        assert(n < mod);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i) ifact[i - 1] = ifact[i] * i;
    }
    
    mint operator()(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * ifact[k] * ifact[n - k];
    }
} comb(300010);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vi a(2 * n);
    cin >> a;
    sort(all(a));
    mint ans = 0;
    rep(i, n) ans -= a[i];
    rep2(i, n, n * 2) ans += a[i];
    ans *= comb(2 * n, n);
    cout << ans << endl;
}