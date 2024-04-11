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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
int m;

vvl mul (const vvl &x, const vvl &y) {
    vvl res(x.size(), vl(y[0].size()));
    for (int i = 0; i < res.size(); ++i) for (int j = 0; j < res[i].size(); ++j)
        for (int l = 0; l < x[i].size(); ++l)
            res[i][j] = (res[i][j] + x[i][l] * y[l][j]) % m;
    return res;
}

vvl id(int n) {
    vvl v(n, vl(n));
    for (int i = 0; i < n; ++i)
        v[i][i] = 1;
    return v;
}

vvl mpow (vvl x, ll n) {
    vvl res = id(2);
    while (n) {
        if (n & 1)
            res = mul(res, x);
        x = mul(x, x);
        n /= 2;
    }
    return res;
}

int main() {
    ll l,r,k;
    cin >> m >> l >> r >> k;
/*    ll a = 1, b = r + 1;
    while (b - a > 1) {
        ll x = (a + b) / 2;
        if (r / x - (l - 1) / x >= k)
            a = x;
        else b = x;
    }
    cerr << a << endl;*/
    ll n = 1;
    for (n = 1100000; n >= 1; --n) {
        if (r / n - (l - 1) / n >= k)
            break;
    }
    for (ll t = 1; t <= 1000000; ++t) {
        ll rem = r % t;
        ll b = r - rem;
        ll d = r / t;
        if (n < d && (k - 1) <= (b - l) / d)
            n = d;
    }
    cerr << n << endl;
    vvl f(2, vl(2, 1));
    f[0][0] = 0;
    cout << mpow(f, n)[0][1] << endl;
    return 0;
}