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
template<class T> void fin(T a) { cout << a << '\n'; exit(0); }
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

class unionfind {
    int n;
    vector<int> par, rank;
    vb flag;
public:
    unionfind(int n) : n(n), par(n, -1), rank(n, 0), flag(n, false) {}
    
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool same(int x, int y) { return root(x) == root(y); };
    
    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        if (rank[x] == rank[y]) rank[x]++;
        par[x] += par[y];
        par[y] = x;
        flag[x] = flag[x] or flag[y];
        return true;
    }
    
    int size(int x) { return -par[root(x)]; };
    
    bool connected() {
        rep(i, n - 1) if (!same(i, i + 1)) return false;
        return true;
    }
    
    bool check(int x) { return flag[root(x)]; }
    
    void update(int x) { flag[root(x)] = true; }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    INT(n, m);
    vi ans;
    vb one(m);
    unionfind uf(m);
    rep(i, n) {
        INT(k);
        vi x(k);
        cin >> x;
        rep(j, k) x[j]--;
        if (k == 1) {
            if (uf.check(x[0])) continue;
            uf.update(x[0]);
        } else {
            if (uf.same(x[0], x[1])) continue;
            if (uf.check(x[0]) and uf.check(x[1])) continue;
            uf.merge(x[0], x[1]);
        }
        ans.pb(i + 1);
    }
    print(mint(2).pow(ans.size()), ans.size());
    rep(i, ans.size()) cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
}