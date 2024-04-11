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
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
const int mod = 1000000007;

ll mpow(ll x, ll n) {
    ll res = 1;
    while(n) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n /= 2;
    }
    return res;
}

ll inv (ll x) {
    return mpow(x, mod - 2);
}

int main() {
    vl fac(10000, 1);
    vl invfac(10000, 1);
    for (int i = 2; i < fac.size(); ++i) {
        fac[i] = fac[i-1] * i % mod;
        invfac[i] = inv(fac[i]);
    }
    vl pw2(1000001, 1);
    for (int i = 1; i < pw2.size(); ++i)
        pw2[i] = pw2[i-1] * 2 % mod;
    int n;
    cin >> n;
    vi a(n);
    vvl v(1000001, vl(21));
    for (int i = 0; i < a.size(); ++i) {
        scanf("%d", &a[i]);
        ++v[a[i]][0];
    }
    ll res = 0;
    for (int i = v.size()-1; i >= 0; --i) {
        ll tot = v[i][0];
        int maxind = 0;
        for (int h = 1; h < v[i].size(); ++h) if (v[i][h]) {
            v[i][h] %= mod;
            tot = (tot + v[i][h]*invfac[h]) % mod;
            maxind = h;
        }
        maxind = min(maxind, (int)v[i].size() - 2);
        int cnt = 0;
        for (int b = 0; b < 20; ++b) if (i & (1 << b)) {
            ++cnt;
            int j = (i ^ (1 << b));
            for (int h = 0; h <= maxind; ++h)
                v[j][h+1] += v[i][h];
        }
        res = (res + ((cnt % 2) ? -1 : 1) * (pw2[tot]-1)) % mod;
//        if (tot) cerr << i << ' ' << tot << ' ' << cnt << ' ' << res << endl;
    }
    cout << (res % mod + mod) % mod << endl;
    return 0;
}