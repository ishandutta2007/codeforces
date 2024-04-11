#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

const int mod = 1000000007;

ll inv (ll a) {
    ll b = mod, x1 = 1, y1 = 0, x2 = 0, y2 = 1;
    while (b) {
        ll t = a / b;
        a -= t * b;
        x1 -= t * x2;
        x1 %= mod;
        y1 -= t * y2;
        y1 %= mod;
        swap(a, b);
        swap(x1, x2);
        swap(y1, y2);
    }
    return x1 % mod;
}

ll p2 (ll x) {
    return (x * x) % mod;
}

ll mpow (ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        n /= 2;
    }
    return res;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vll fac(1e6 + 3, 1), invfac(1e6 + 3, 1);
    for (int i = 2; i < fac.size(); ++i) {
        fac[i] = (fac[i - 1] * i) % mod;
        invfac[i] = inv(fac[i]);
    }
    vector<vll> s(1001, vll(1001, 0));
    s[0][0] = 1;
    for (int i = 1; i < s.size(); ++i) for (int j = 1; j <= i; ++j)
        s[i][j] = (s[i - 1][j - 1] + j * s[i - 1][j]) % mod;
    if (m == 1) {
        cout << mpow(k, n) << endl;
        return 0;
    }
    ll res = 0;
    for (int i = 0; i <= n; ++i) for (int j = 0; j <= n - i; ++j) {
        if (i + j > 0 && 2 * i + j <= k) {
//            cerr << i << " " << j << endl;
            ll add = (fac[k] * p2(invfac[i])) % mod;
//            cerr << add << endl;
            add = (add * invfac[j]) % mod;
//            cerr << add << endl;
            add = (add * invfac[k - 2 * i - j]) % mod;
//            cerr << add << endl;
            add = (add * mpow(j, n * (m - 2))) % mod;
//            cerr << m << " " << i + j << " " << s[n][i + j] << endl;
            add = (add * p2(s[n][i + j])) % mod;
            add = (add * p2(fac[i + j])) % mod;
            res += add;
        }
    }
    cout << (res % mod + mod) % mod << endl;
    return 0;
}