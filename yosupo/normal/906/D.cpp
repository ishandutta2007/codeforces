#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <random>
#include <vector>
#include <array>
#include <bitset>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
constexpr ll TEN(int n) { return (n==0) ? 1 : 10*TEN(n-1); }
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

struct rng {
    struct A {
        int n;
        const bool operator!=(A r) { return n != r.n; }
        A& operator++() { n++; return *this; }
        int operator*() { return n; }
    };
    int l, r;
    rng(int r) : l(0), r(max(0, r)) {}
    rng(int l, int r) : l(l), r(max(l, r)) {}
    A begin() { return A{l}; }
    A end() { return A{r}; }
};


ll tot(ll x) {
    ll y = x;
    for (ll i = 2; i*i <= x; i++) {
        if (x % i) continue;
        y /= i; y *= (i-1);
        while (x % i == 0) x /= i;
    }
    if (x > 1) {
        y /= x; y *= (x-1);
    }
    return y;
}

ll super_mod(ll x, ll md) {
    if (md <= x) x = (x-md) % md + md;
    return x;
}
ll super_pow_mod(ll x, ll n, ll md) {
    ll r = 1;
    while (n) {
        if (n & 1) r = super_mod(r * x, md);
        x = super_mod(x * x, md);
        n >>= 1;
    }
    return super_mod(r, md);
}

int n;
V<ll> ms;
V<ll> a;

// calc [l, r] super_mod (ms[mdi])
ll calc(int l, int r, int mdi) {
//    cout << "calc " << l << " " << r << " " << mdi << endl;
    ll md = ms[mdi];
    if (l+1 == r) {
        ll u = a[l];
        if (md <= u) {
            u = (u-md) % md + md;
        }
        return u;
    }
    if (ms[mdi] == 1) return 1;
    ll z = calc(l+1, r, mdi+1);
    return super_pow_mod(a[l], z, md);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    ll m_base;
    cin >> n >> m_base;
    ll m = m_base;
    while (true) {
//        cout << "tot " << m << endl;
        ms.push_back(m);
        if (m == 1) break;
        m = tot(m);
    }
    
    a = V<ll>(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r; l--;
//        cout << "QUERY START " << l << " " << r << endl;
        cout << calc(l, r, 0) % m_base << endl;    
    }
    return 0;
}