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

ll mpow(ll x, ll n, int mod) {
    ll res = 1;
    while (n) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n /= 2;
    }
    return res;
}

ll inv(ll x, int mod) {
    return mpow(x, mod - 2, mod);
}

vl fac(2000002, 1);
vl invfac(fac.size(), 1);

ll c(int a, int b) {
    if (a < 0 || a > b) return 0;
    return fac[b] * invfac[a] % mod * invfac[b-a] % mod;
}

int main() {
    for (int i = 2; i < fac.size(); ++i) {
        fac[i] = fac[i-1] * i % mod;
    }
    invfac.back() = inv(fac.back(), mod);
    for (int i = fac.size() - 2; i > 1; --i) {
        invfac[i] = invfac[i+1] * (i + 1) % mod;
    }
    int n;
    cin >> n;
    ll sum = 0;
    for (int i = 0; i <= n; ++i) {
        sum += c(n, n + i + 1);
//        cerr << i << ' ' << sum << endl;
    }
    cout << sum % mod << endl;
    return 0;
}