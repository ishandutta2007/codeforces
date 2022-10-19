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

constexpr int mint_mod = 1000000007;

//constexpr int mint_mod = 998244353;
struct mint {
    ll x;
    
    constexpr mint(ll x = 0) : x((x % mint_mod + mint_mod) % mint_mod) {}
    
    constexpr mint operator-() const { return mint(-x); }
    
    constexpr mint &operator+=(const mint &a) {
        if ((x += a.x) >= mint_mod) x -= mint_mod;
        return *this;
    }
    
    constexpr mint &operator++() { return *this += mint(1); }
    
    constexpr mint &operator-=(const mint &a) {
        if ((x += mint_mod - a.x) >= mint_mod) x -= mint_mod;
        return *this;
    }
    
    constexpr mint &operator--() { return *this -= mint(1); }
    
    constexpr mint &operator*=(const mint &a) {
        (x *= a.x) %= mint_mod;
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
    
    // for prime mint_mod
    constexpr mint inv() const { return pow(mint_mod - 2); }
    
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

using ull = unsigned long long;
const ull mod = (1ull << 61) - 1;
const ull mask30 = (1ull << 30) - 1;
const ull mask31 = (1ull << 31) - 1;
const ull mask61 = mod;

ull calc_mod(ull x) {
    ull xu = x >> 61;
    ull xd = x & mask61;
    ull res = xu + xd;
    if (res >= mod) res -= mod;
    return res;
}

// a*b mod 2^61-1
ull mul(ull a, ull b) {
    ull au = a >> 31;
    ull ad = a & mask31;
    ull bu = b >> 31;
    ull bd = b & mask31;
    ull mid = ad * bu + au * bd;
    ull midu = mid >> 30;
    ull midd = mid & mask30;
    return au * bu * 2 + midu + (midd << 31) + ad * bd;
}

class rolling_hash {
    int n;
    string s;
    vector<ull> hash1, hash2, pow1, pow2;
    
    void init() {
        hash1.assign(n + 1, 0);
        hash2.assign(n + 1, 0);
        pow1.assign(n + 1, 1);
        pow2.assign(n + 1, 1);
        rep(i, n) {
            hash1[i + 1] = calc_mod(mul(hash1[i], base1) + s[i]);
            hash2[i + 1] = calc_mod(mul(hash2[i], base2) + s[i]);
            pow1[i + 1] = calc_mod(mul(pow1[i], base1));
            pow2[i + 1] = calc_mod(mul(pow2[i], base2));
        }
    }

public:
    static ull base1;
    static ull base2;
    
    rolling_hash(const string &s) : s(s), n(s.size()) {
        init();
    }
    
    // return hash of [l,r) of S
    pair<ull, ull> get(int l, int r) {
        ll res1 = calc_mod(hash1[r] + mod * 4 - mul(hash1[l], pow1[r - l]));
        ll res2 = calc_mod(hash2[r] + mod * 4 - mul(hash2[l], pow2[r - l]));
        return make_pair(res1, res2);
    }
    
    // return hash of T
    pair<ull, ull> get(string t) {
        ull ht1 = 0, ht2 = 0;
        rep(i, t.size()) {
            ht1 = calc_mod(mul(ht1, base1) + t[i]);
            ht2 = calc_mod(mul(ht2, base2) + t[i]);
        }
        return make_pair(ht1, ht2);
    }
    
    void add(char c) {
        hash1.pb(calc_mod(mul(hash1.back(), base1) + c));
        hash2.pb(calc_mod(mul(hash2.back(), base2) + c));
        pow1.pb(calc_mod(mul(pow1.back(), base1)));
        pow2.pb(calc_mod(mul(pow2.back(), base2)));
    }
};

random_device rnd;
mt19937_64 mt(rnd());
uniform_int_distribution<ull> dist(2, mod - 2);
ull rolling_hash::base1 = dist(mt);
ull rolling_hash::base2 = dist(mt);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    INT(n, q);
    STR(s, t);
    rolling_hash sr(s);
    vi k(q);
    vs w(q);
    rep(i, q) scan(k[i], w[i]);
    vector<rolling_hash> rh;
    rep(i, q) rh.eb(w[i]);
    vector<mint> ans(q);
    rep(i, q) {
        if (w[i].size() > s.size()) continue;
        auto now = rh[i].get(0, w[i].size());
        rep(j, s.size() - w[i].size() + 1) {
            if (sr.get(j, j + w[i].size()) == now) ans[i] += 1;
        }
    }
    vvi end(n + 1);
    rep(i, q) end[k[i]].pb(i);
    vector<mint> coe(27);
    coe[26] = 1;
    bool flag = false;
    vvi cnt(q, vi(26, 0));
    rep(i, n) {
        if (s.size() > 1000000) {
            if (!flag) {
                rep(j, q) {
                    if (k[j] < i + 1) continue;
                    rep(l, w[j].size()) {
                        if (l > 0) {
                            assert(l <= s.size());
                            if (rh[j].get(0, l) != sr.get(s.size() - l, s.size())) continue;
                        }
                        if (l < w[j].size() - 1) {
                            assert(w[j].size() - 1 - l <= s.size());
                            if (rh[j].get(l + 1, w[j].size()) != sr.get(0, w[j].size() - 1 - l)) continue;
                        }
                        cnt[j][w[j][l] - 'a']++;
                    }
                }
                flag = true;
            }
            rep(j, 27) coe[j] *= 2;
            coe[t[i] - 'a'] += 1;
            for (int j : end[i + 1]) {
                ans[j] *= coe[26];
                rep(l, 26) {
                    ans[j] += coe[l] * cnt[j][l];
                }
            }
            continue;
        }
        rep(j, q) {
            if (k[j] < i + 1) continue;
            ans[j] *= 2;
            rep(l, w[j].size()) {
                if (w[j][l] != t[i]) continue;
                if (l > 0) {
                    if (l > s.size()) continue;
                    if (rh[j].get(0, l) != sr.get(s.size() - l, s.size())) continue;
                }
                if (l < w[j].size() - 1) {
                    if (w[j].size() - 1 - l > s.size()) continue;
                    if (rh[j].get(l + 1, w[j].size()) != sr.get(0, w[j].size() - 1 - l)) continue;
                }
                ans[j] += 1;
            }
        }
        sr.add(t[i]);
        for (char c : s) sr.add(c);
        s.pb(t[i]);
        int sz = s.size();
        rep(j, sz - 1) s.pb(s[j]);
    }
    rep(i, q) cout << ans[i] << '\n';
}