#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
const int mod = 1000000007;
vl fac(100000, 1);

ll mpow(ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) res = res * x % mod;
        n /= 2;
        x = x * x % mod;
    }
    return res;
}

ll inv(ll x) {
    return mpow(x, mod - 2);
}

/*ll bin(int k, int n) {
    return fac[n] * inv(fac[k] * fac[n-k] % mod) % mod;
}*/

ll bin[4001][4001];

ll dw(ll x) {
    if (x >= mod) return x-mod;
    return x;   
}

int main() {
    for (int i = 0; i <= 4000; ++i) bin[0][i] = 1;
    for (int i = 1; i <= 4000; ++i) for (int j = 1; j <= i; ++j) {
        bin[j][i] = dw(bin[j-1][i-1] + bin[j][i-1]);
    }
    for (int i = 2; i < fac.size(); ++i) fac[i] = fac[i-1] * i % mod;
    int n;
    cin >> n;
    vvl c(n + 1, vl(n + 1));
    c[0][0] = c[1][1] = 1;
    for (int i = 2; i <= n; ++i) for (int k = 1; k <= i; ++k) {
        c[i][k] = (c[i-1][k-1] + k*c[i-1][k]) % mod;
    }
    vl v(n + 1);
    for (int i = 0; i <= n; ++i) {
        for (int k = 0; k < c[i].size(); ++k) v[i] += c[i][k];
        v[i] %= mod;
    }
    vl s(n + 1);
    for (int k = 0; k <= n; ++k) {
        for (int i = 0; i <= k; ++i) {
            s[k] = (s[k] + v[i] * bin[i][k]) % mod;
        }
    }
    ll res = 0;
    ll m = 1;
    for (int i = 1; i <= n; ++i) {
        res = (res + m * s[n-i] * bin[i][n]) % mod;
//        cerr << v[n-i] << ' ' << bin(i, n) << endl;
        m *= -1;
    }
    cout << (res % mod + mod) % mod << endl;
    return 0;
}