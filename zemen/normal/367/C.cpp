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

#define INF 1000000001
#define INFL 1000000000000000001ll
#define pb push_back
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef complex <double> point;

#define NAME "c"
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

char check(int n, int k) {
    if (k % 2 == 1)
        return n >= (ll(k) * ll(k - 1)) / 2ll + 1ll;
    else
        return n >= (ll(k) * ll(k - 1)) / 2ll + k / 2;
}

int a[100001];

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    int n, m;
    cin >> n >> m;
    int rmin = 1, rmax = m + 1;
    while (rmin + 1 < rmax) {
        int c = (rmin + rmax) / 2;
        if (check(n, c))
            rmin = c;
        else
            rmax = c;
    }
    //~ cerr << rmin << '\n';
    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t >> a[i];
        a[i] = -a[i];
    }
    sort(a, a + m);
    ll res = 0;
    for (int i = 0; i < min(m, rmin); ++i)
        res -= ll(a[i]);
    cout << res << '\n';
}