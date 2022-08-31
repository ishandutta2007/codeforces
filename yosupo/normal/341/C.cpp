#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <queue>

using namespace std;
typedef long long ll;

ll mod = 1000000007;
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
ll c[2003][2003];
int main() {
    ll n;
    cin >> n;
    ll d[2000];
    bool f[2000] = {};
    for (int i = 0; i < n; i++) {
        cin >> d[i];
        if (d[i] != -1) {
            d[i]--;
            f[d[i]] = true;
        }
    }
    ll a = 0, b = 0;
    for (int i = 0; i < n; i++) {
        if (!f[i]) {
            if (d[i] != -1) {
                a++;
            } else {
                b++;
            }
        }
    }
    ll dp[2003] = {}, p[2003] = {};
    p[0] = 1;
    for (int i = 1; i <= a+b; i++) {
        p[i] = (p[i-1]*i)%mod;
    }
    dp[0] = p[a];
    for (int i = 0; i < 2003; i++) {
        c[i][0] = 1;
        c[0][i] = 0;
    }
    c[0][0] = 1;
    for (int i = 1; i < 2003; i++) {
        for (int j = 1; j < 2003; j++) {
            c[i][j] = (c[i-1][j] + c[i-1][j-1])%mod;
        }
    }
    for (int i = 1; i <= b; i++) {
        ll buf = 0;
        for (int j = 0; j < i; j++) {
            buf += c[i][i-j]*dp[j];
            buf %= mod;
        }
        dp[i] = (p[a+i] + mod - buf) % mod;
    }
    cout << dp[b] << endl;
    return 0;
}