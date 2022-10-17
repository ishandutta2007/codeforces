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

struct edge {
    int to;
    ll len;
    
    edge(int to, ll l) : to(to), len(l) {}
};

vl dijkstra(int start, const vector<vector<edge>> &v) {
    int n = v.size();
    vl dist(n, linf);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
    q.emplace(0LL, start);
    dist[start] = 0;
    while (!q.empty()) {
        auto p = q.top();
        q.pop();
        if (dist[p.second] < p.first) continue;
        for (auto e : v[p.second]) {
            if (chmin(dist[e.to], p.first + e.len)) {
                q.emplace(p.first + e.len, e.to);
            }
        }
    }
    return dist;
}

using vve = vector<vector<edge>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vvp G(n);
    rep(_, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].eb(v, 0);
        G[v].eb(u, 1);
    }
    vp dist(n * 2, P{inf, inf});
    dist[0] = {0, 0};
    priority_queue<pair<P, int>, vector<pair<P, int>>, greater<pair<P, int>>> pq;
    pq.push({dist[0], 0});
    while (pq.size()) {
        auto[d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        int pos = u / 2, t = u % 2;
        auto nd = d;
        nd.second++;
        for (auto[v, rt] : G[pos]) {
            if (t != rt) continue;
            if (chmin(dist[v * 2 + t], nd)) {
                pq.push({dist[v * 2 + t], v * 2 + t});
            }
        }
        nd = d;
        nd.first++;
        int now = pos * 2 + 1 - t;
        if (chmin(dist[now], nd)) {
            pq.push({dist[now], now});
        }
    }
    auto fd = min(dist[n * 2 - 2], dist[n * 2 - 1]);
    assert(fd.first != inf);
    if (fd.first >= 30) {
        mint ans = fd.second;
        ans += mint(2).pow(fd.first) - 1;
        cout << ans << endl;
        return 0;
    }
    
    auto toId = [](int i, int d) {
        return i * 30 + d;
    };
    vve g(n * 30);
    vi pow(30, 1);
    rep(i, 29) pow[i + 1] = pow[i] * 2;
    rep(i, n) rep(d, 30) {
            int t = d % 2;
            for (auto[j, rt] : G[i]) {
                if (t != rt) continue;
                g[toId(i, d)].eb(toId(j, d), 1);
            }
            if (d < 29) g[toId(i, d)].eb(toId(i, d + 1), pow[d]);
        }
    auto res = dijkstra(toId(0, 0), g);
    ll ans = linf;
    rep(j, 30) chmin(ans, res[toId(n - 1, j)]);
    cout << ans << endl;
}