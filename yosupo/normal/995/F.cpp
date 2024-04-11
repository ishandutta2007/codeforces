#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

template<class T> ostream& operator<<(ostream& os, const V<T> &v) {
    cout << "[";
    for (auto p: v) cout << p << ", ";
    cout << "]";
    return os;
}

template<uint MD>
struct ModInt {
    using M = ModInt;
    uint v;
    ModInt() : v{0} {}
    ModInt(ll _v) : v{normS(_v%MD+MD)} {}
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
using Mint = ModInt<TEN(9)+7>;

const int N = 3030;

VV<int> g;
V<Mint> dfs(int p) {
    V<Mint> res(N);
    for (int i = 1; i < N; i++) res[i] = Mint(1);
    for (int d: g[p]) {
        auto ch = dfs(d);
        for (int i = 1; i < N; i++) res[i] *= ch[i];
    }
    for (int i = 1; i < N; i++) res[i] += res[i-1];
    return res;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;

    VV<Mint> C(N, V<Mint>(N));
    C[0][0] = Mint(1);
    for (int i = 1; i < N; i++) {
        C[i][0] = Mint(1);
        for (int j = 1; j < N; j++) {
            C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
    }
    int n, _d;
    cin >> n >> _d;
    Mint d = Mint(_d);
    g = VV<int>(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p; p--;
        g[p].push_back(i);
    }

    auto v = dfs(0);
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < i; j++) {
            v[i] -= v[j] * C[i][j];
        }
    }

/*    for (int i = 0; i < 10; i++) {
        cout << v[i].v << " ";
    } cout << endl;*/


    Mint ans = Mint(0);
    Mint f = Mint(1);
    for (int i = 1; i < N; i++) {
        f *= Mint(d)-Mint(i-1);
        f /= Mint(i);
        ans += f * v[i];
    }
    cout << ans.v << endl;
    return 0;
}