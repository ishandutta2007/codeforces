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

#define NAME "b"
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

ll d[100004];
ll a[100004];
int n, k;

inline char check(ll c) {
    for (int i = 0; i <= n; ++i)
        d[i] = i;
    for (int i = 0; i < n; ++i) {
        ll delta = 0;
        for (int j = i + 1; j <= n; ++j) {
            delta += c;
            if (j == n || llabs(a[i] - a[j]) <= delta)
                d[j] = min(d[j], d[i] + j - i - 1);
        }
    }
    return d[n] > k;
}

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    ll rmin = -1, rmax = 2000000000;
    while (rmin + 1 < rmax) {
        ll c = (rmax + rmin) / 2;
        if (check(c))
            rmin = c;
        else
            rmax = c;
    }
    cout << rmax << '\n';
}