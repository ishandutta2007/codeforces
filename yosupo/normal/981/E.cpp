#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

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

int n, q;
VV<int> st, ed;
V<bool> res;

template<uint MD>
void calc() {
    using Mint = ModInt<MD>;
    V<Mint> dp(n+1); dp[0] = Mint(1);
    for (int ph = 0; ph < n; ph++) {
        for (int d: st[ph]) {
            //add d
            for (int i = n; i >= d; i--) {
                dp[i] += dp[i-d];
            }
        }
        for (int d: ed[ph]) {
            for (int i = d; i <= n; i++) {
                dp[i] -= dp[i-d];
            }
        }

        for (int i = 0; i <= n; i++) {
            if (dp[i]) res[i] = true;
        }
    }
}

ll rand_int(ll l, ll r) { //[l, r]
    using D = uniform_int_distribution<ll>;
    static random_device rd;
    static mt19937 gen(rd());
    return D(l, r)(gen);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);
    cin >> n >> q;
//    n = 10000; q = 10000;
    st = VV<int>(n);
    ed = VV<int>(n+1);
    res = V<bool>(n+1);

    for (int i = 0; i < q; i++) {
        int a, b, x;
        cin >> a >> b >> x; a--;
        // a = rand_int(0, n-1);
        // b = rand_int(0, n-1);
        // if (a > b) swap(a, b); b++;
        // x = rand_int(0, n);
        st[a].push_back(x);
        ed[b].push_back(x);
    }

    const int MOD1 = 999998197;
    const int MOD2 = 998080199;
    calc<MOD1>();
    calc<MOD2>();

    V<int> v;
    for (int i = 1; i <= n; i++) {
        if (res[i]) v.push_back(i);
    }
    cout << v.size() << endl;
    for (int d: v) {
        cout << d << " ";
    } cout << endl;
    return 0;
}