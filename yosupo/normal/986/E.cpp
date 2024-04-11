#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

template<int LG = 20>
struct LCA {
    vector<int> ro[LG], dps;
    LCA() {}
    ///  rrootid
    template<class E>
    LCA(VV<E> &g, int r) {
        int V = int(g.size());
        ro[0] = vector<int>(V, -1);
        dps.resize(V);
        dfs(g, r, -1, 0);
        for (int i = 1; i < LG; i++) {
            ro[i].resize(V);
            for (int j = 0; j < V; j++) {
                ro[i][j] = (ro[i-1][j] == -1) ? -1 : ro[i-1][ro[i-1][j]];
            }
        }
    }

    /// lrLCA
    int query(int l, int r) {
        if (dps[l] < dps[r]) swap(l, r);
        int dd = dps[l]-dps[r];
        for (int i = LG-1; i >= 0; i--) {
            if (dd < (1<<i)) continue;
            dd -= 1<<i;
            l = ro[i][l];
        }
        if (l == r) return l;
        for (int i = LG-1; i >= 0; i--) {
            if (ro[i][l] == ro[i][r]) continue;
            l = ro[i][l]; r = ro[i][r];
        }
        return ro[0][l];
    }
    
    template<class E>
    void dfs(VV<E> &g, int p, int b, int now) {
        ro[0][p] = b;
        dps[p] = now;
        for (E e: g[p]) {
            if (e.to == b) continue;
            dfs(g, e.to, p, now+1);
        }
    }
};

template<uint MD>
struct ModInt {
    using M = ModInt;
    uint v;
    ModInt() : v{0} {}
    ModInt(ll v) : v{normS(v%MD+MD)} {}
    explicit operator bool() const {return v != 0;}
    static uint normS(uint x) {return (x<MD)?x:x-MD;};
    static M make(uint x) {M m; m.v = x; return m;}
    static M inv(const M &x) {return x.pow(MD-2); }
    M operator+(const M &r) const {return make(normS(v+r.v));}
    M operator-(const M &r) const {return make(normS(v+MD-r.v));}
    M operator*(const M &r) const {return make(ull(v)*r.v%MD);}
    M operator/(const M &r) const {return *this*inv(r);}
    M& operator+=(const M &r) {return *this=*this+r;}
    M& operator-=(const M &r) {return *this=*this-r;}
    M& operator*=(const M &r) {return *this=*this*r;}
    M& operator/=(const M &r) {return *this=*this/r;}
    M pow(ll n) const {
        M x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
};
using Mint = ModInt<TEN(9) + 7>;

struct E { int to; };
int n;
VV<E> g;
V<int> a;
using P = pair<int, int>;
VV<P> que_mul, que_div;
V<Mint> answer;
LCA<> lca;

void init() {
    g = VV<E>(n);
    a = V<int>(n);
    que_mul = VV<P>(n);
    que_div = VV<P>(n);
}


const int MD = TEN(7) + TEN(4);
int bk[MD];
Mint iz[MD];
V<Mint> dp[MD];
void first() {
    fill_n(bk, MD, -1);
    ll gc = 0;
    for (int i = 2; i < MD; i++) {
        if (bk[i] != -1) continue;
        iz[i] = Mint(1) / Mint(i);
        for (int j = i; j < MD; j+=i) {
            if (bk[j] != -1) continue;
            bk[j] = i;
        }
        int c = 0;
        ll nw = 1;
        while (nw*i < MD) {
            c++;
            nw *= i;
        }
        gc += c;
        dp[i] = V<Mint>(c, Mint(1));
    }
}

V<P> div_pr(int x) {
    V<P> res;
    while (x > 1) {
        int z = bk[x];
        if (res.size() && res.back().first == z) {
            res.back().second++;
        } else {
            res.push_back(P(z, 1));
        }
        x /= z;
    }
    return res;
}

void dfs(int p, int b) {
    auto vp = div_pr(a[p]);
    for (auto pa: vp) {
        int pr = pa.first;
        int c = pa.second;
        assert(c <= dp[pr].size());
        for (int i = 0; i < c; i++) {
            dp[pr][i] *= Mint(pr);
        }
    }
    for (auto qu: que_mul[p]) {
        auto vp = div_pr(qu.second);
        Mint ans = Mint(1);
        for (auto pa: vp) {
            int pr = pa.first;
            int c = pa.second;
            for (int i = 0; i < c; i++) {
                ans *= dp[pr][i];
            }
        }
        answer[qu.first] *= ans;
    }
    for (auto qu: que_div[p]) {
        auto vp = div_pr(qu.second);
        Mint ans = Mint(1);
        for (auto pa: vp) {
            int pr = pa.first;
            int c = pa.second;
            for (int i = 0; i < c; i++) {
                ans *= dp[pr][i];
            }
        }
        answer[qu.first] /= ans;
    }
    for (auto e: g[p]) {
        int d = e.to;
        if (d == b) continue;
        dfs(d, p);   
    }
    for (auto pa: vp) {
        int pr = pa.first;
        int c = pa.second;
        assert(c <= dp[pr].size());
        for (int i = 0; i < c; i++) {
            dp[pr][i] *= iz[pr];
        }
    }
}

int main() {
    first();
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    cin >> n;
    init();
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b; a--; b--;
        g[a].push_back(E{b});
        g[b].push_back(E{a});
    }
    lca = LCA<>(g, 0);
    for (int i = 0; i < n; i++) cin >> a[i];
    int q;
    cin >> q;
    answer = V<Mint>(q, Mint(1));
    for (int ph = 0; ph < q; ph++) {
        int a, b, x;
        cin >> a >> b >> x; a--; b--;
        que_mul[a].push_back(P(ph, x));
        que_mul[b].push_back(P(ph, x));
        int c = lca.query(a, b);
        que_div[c].push_back(P(ph, x));
        int d = lca.ro[0][c];
        if (d != -1) {
            que_div[d].push_back(P(ph, x));
        }
    }
    dfs(0, -1);
    for (int ph = 0; ph < q; ph++) {
        cout << answer[ph].v << endl;
    }
    return 0;
}