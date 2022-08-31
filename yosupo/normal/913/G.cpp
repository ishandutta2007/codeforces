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

ll mul_mod(ll x, ll y, ll md) {
    if (x == 0) return 0;
    if (x & 1) return (y + 2*mul_mod((x-1)/2, y, md)) % md;
    return (2 * mul_mod(x/2, y, md)) % md;
//    return __int128(x) * y % md;
}

ll pow_mod(ll x, ll n, ll md) {
    ll r = 1 % md;
    while (n) {
//        if (n & 1) r = (r * x) % md;
        if (n & 1) r = mul_mod(r, x, md);
//        x = (x * x) % md;
        x = mul_mod(x, x, md);
        n >>= 1;
    }
    return r;
}

V<ll> freq(ll st, ll pw, ll md) {
    V<ll> ans;
    ll nw = st;
    do {
        ans.push_back(nw);
//        nw = (nw * pw) % md;
        nw = mul_mod(nw, pw, md);
    } while (st != nw);
    return ans;
}

ll solve_i(ll x) {
    ll nw = 101, step = 1;
    ll b = 1;
    for (int i = 0; i < 18; i++) {
//    do {
        b *= 5;
        ll tar = x % b;
        ll z = pow_mod(2, nw, b);
        ll di = pow_mod(2, step, b);

        auto v = freq(z, di, b);

        bool ok = false;
        int u = int(v.size());
        for (int i = 0; i < u; i++) {
            if (v[i] == tar) {
                nw += i * step;
                step *= u;
                ok = true;
                break;
            }
        }
        if (!ok) return -1;
//    } while (b <= x);
    }
    return nw;    
}

ll solve(ll x) {
    x = (x * TEN(7) + (1<<18) - 1) / (1<<18) * (1<<18);

    while (true) {
//        cout << x << endl;
        ll z = x % 3814697265625LL;
        ll y = solve_i(z);
        
        if (y != -1) {
//            cout << "find: " << z << " : " << y << endl;
            return y;
        }
        x += (1<<18);
    }
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(20);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;
        cout << solve(x) << endl;
    }
    return 0;
}