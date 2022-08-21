#include <bits/stdc++.h>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n - 1); }
template <class T> using V = vector<T>;
template <class T> using VV = V<V<T>>;

/// g:gcd(a, b), ax+by=g
struct EG { ll g, x, y; };
EG ext_gcd(ll a, ll b) {
    if (b == 0) {
        if (a >= 0) return EG{a, 1, 0};
        else return EG{-a, -1, 0};
    } else {
        auto e = ext_gcd(b, a % b);
        return EG{e.g, e.y, e.x - a / b * e.y};
    }
}

template<class T, class U>
T pow_mod(T x, U n, T md) {
    T r = 1 % md;
    while (n) {
        if (n & 1) r = (r * x) % md;
        x = (x * x) % md;
        n >>= 1;
    }
    return r;
}

ll inv_mod(ll x, ll md) {
    auto z = ext_gcd(x, md).x;
    return (z % md + md) % md;
}

int n, m;
ll a, md, q;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20) << fixed;
    cin >> n >> m >> a >> q; a %= q;
    ll b = a;
    md = 1;
    while (b != 1) {
        b = (b * a) % q;
        md++;
    }
    V<ll> c(n+1); c[0] = 1;
    for (int i = 1; i <= n; i++) {
        c[i] = c[i-1] * (m+1-i) % md * inv_mod(i, md) % md;
    }
    V<ll> csm(n+1); csm[0] = c[0];
    for (int i = 1; i <= n; i++) csm[i] = (csm[i-1] + c[i]) % md;

    for (int i = 0; i < n; i++) {
        ll u = csm[n-1-i];
        cout << pow_mod(a, u, q) << " ";
    }
    cout << endl;
    return 0;
}