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

ll a[100001];
ll b[100001];
int n, m;

inline char check(ll c) {
    int lb = 0;
    for (int i = 0; i < n; ++i) {
        ll rem = c - llabs(b[lb] - a[i]);
        if (rem < 0)
            continue;
        int to = upper_bound(b + lb, b + m, rem + b[lb]) - b;
        to = max(to, int(upper_bound(b + lb, b + m, rem / 2 + a[i]) - b));
        if (to == m)
            return 1;
        lb = to;
    }
    return lb == m;
}

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i)
        cin >> b[i];
    ll rmax = 100000000000ll, rmin = -1;
    while (rmin + 1 < rmax) {
        ll c = (rmin + rmax) / 2ll;
        if (check(c))
            rmax = c;
        else
            rmin = c;
    }
    cout << rmax << '\n';
}