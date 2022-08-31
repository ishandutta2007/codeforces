//#define NDEBUG

#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <chrono>
#include <map>

using namespace std;

typedef long long ll;
const ll MD = 1e9+7;

ll pow_mod(ll x, ll n, ll mod) {
    ll r = 1;
    while (n) {
        if (n & 1) r = (r * x) % mod;
        x = (x * x) % mod;
        n >>= 1;
    }
    return r;
}

ll invp(ll r, ll mod) {
    return pow_mod(r, mod-2, mod);
}

ll comb_pmod(int n, int k, ll mod) {
    if (n < k || k < 0) return 0;
    ll r = 1;
    for (int i = 1; i <= k; i++) {
        r *= i;
        r %= mod;
    }
    r = invp(r, mod);
    for (int i = n-k+1; i <= n; i++) {
        r = (r * i) % mod;
    }
    return r;
}

map<int, int> mp;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll a, aa;
        cin >> a; aa = a;
        for (ll j = 2; j*j <= aa; j++) {
            while (a%j == 0) {
                mp[j]++;
                a /= j;
            }
        }
        if (a != 1) {
            mp[a]++;
        }
    }
    ll res = 1;
    for (auto p: mp) {
        res *= comb_pmod(n+p.second-1, p.second, MD);
        res %= MD;
    }
    cout << res << endl;
    return 0;
}