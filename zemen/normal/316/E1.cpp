#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <complex>
#include <cassert>

using namespace std;

#define INF __INT_MAX__
#define INFL __LONG_LONG_MAX__
#define pb push_back
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef complex <double> point;

#define NAME "e"
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

const int mod = 1000000000;
int f[100001];
int a[100001];

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    f[0] = f[1] = 1;
    for (int i = 2; i < 100000; ++i)
        f[i] = (f[i - 1] + f[i - 2]) % mod;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int t, q, w;
    for (int i = 0; i < m; ++i) {
        cin >> t >> q >> w;
        if (t == 1)
            a[q - 1] = w;
        else {
            ll res = 0;
            for (int j = 0; j <= w - q; ++j) {
                res += (ll(f[j]) * ll(a[j + q - 1]));
                res %= mod;
            }
            cout << res << '\n';
        }
    }
}