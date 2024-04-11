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
typedef vector<string> vs;

const int mod = 1000000007;

ll mpow (ll x, ll n) {
    ll res = 1;
    while (n) {
        if (n & 1) 
            res = res * x % mod;
        n /= 2;
        x = x * x % mod;
    }
    return res;
}

ll inv(ll x) {
    return mpow(x, mod-2);
}

const int MAX = 3001;

int main() {
    int T;
    cin >> T;
    vvi c(MAX, vi(MAX));
    c[0][0] = 1;
    for (int i = 1; i < c.size(); ++i) {
        c[0][i] = 1;
        for (int j = 1; j < c[i].size(); ++j) {
            c[j][i] = c[j][i-1] + c[j-1][i-1];
            if (c[j][i] >= mod)
                c[j][i] -= mod;
        }
    }
    vl fac(MAX, 1);
    for (int i = 1; i < fac.size(); ++i) {
        fac[i] = fac[i-1]*i%mod;
    }
    vvi p(1001, vi(50));
    vvi p0(1001, vi(1001));
    for (int n = 0; n <= 1000; ++n) for (int m = n; m <= 1000; ++m) {
        p0[n][m] = 1;
        p[n][1] = 1;
    }
    for (int k = 2; k < 50; ++k) {
        vvi np0(1001, vi(1001));
        for (int n = k*(k-1)/2; n <= 1000; ++n) {
/*            if (k == 1) {
                p[n][k] = 1;
                continue;
            }*/
            for (int m = 1; m <= 1000; ++m) {
                if (m > n) {
                    np0[n][m] = np0[n][m-1];
                    continue;
                }
                np0[n][m] = np0[n][m-1] + p0[n-m][m-1];
                if (np0[n][m] >= mod) np0[n][m] -= mod;
            }
            p[n][k] = np0[n][n];
        }
//        if (k == 2) {
//            cerr << np0[3][3] << ' ' << np0[3][2] << ' ' << np0[3][1] << endl;
//        }
        p0.swap(np0);
    }
//    cerr << p[3][2] << endl;
    vvi d(1001, vi(100));
    for (int i = 0; i < d.size(); ++i) {
        for (int k = 1; k*(k-1)/2 <= i; ++k) {
            int k2 = k*(k-1)/2;
            for (int a = k2; a <= i; ++a) {
                d[i][k] = (d[i][k] + (ll)c[i-a][i-a+k]*p[a][k]) % mod;
            }
        }
    }
    for (int test = 0; test < T; ++test) {
        int n, k;
        scanf("%d%d",&n,&k);
        n -= k;
        int k2 = k*(k-1)/2;
        if (n < k2) {
            cout << 0 << endl;
            continue;
        }
        cout << d[n][k]*fac[k]%mod << endl;
    }
    return 0;
}