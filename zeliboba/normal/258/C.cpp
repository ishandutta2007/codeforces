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
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

const int mod = 1000000007;

ll mpow (ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1)
            res = res * x % mod;
        x = x * x % mod;
        n /= 2;
    }
    return res;
}

ll inv (ll x) {
    return mpow(x, mod - 2);
}

int main() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    ll res = 0;
    vi pos(100001);
    for (int i = 0; i < pos.size(); ++i)
        pos[i] = lower_bound(a.begin(), a.end(), i) - a.begin();
    for (int q = 1; q <= a.back(); ++q) {
        int d = 1, cnt = 0, prev = 0;
        ll mul = 1;
        for (; d * d <= q; ++d) if (q % d == 0) {
            mul = mul * mpow(cnt, pos[d] - prev) % mod;
            ++cnt;
            prev = pos[d];
        }
        for (; d >= 1; --d) if (q % d == 0 && d * d < q) {
            mul = mul * mpow(cnt, pos[q / d] - prev) % mod;
            ++cnt;
            prev = pos[q / d];
        }
        res = (res + mul * (mpow(cnt, n - pos[q]) - mpow(cnt - 1, n - pos[q]))) % mod;
//        cerr << res << endl;
    }
    cout << (res % mod + mod) % mod << endl;
    return 0;
}