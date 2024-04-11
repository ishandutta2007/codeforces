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

#define NAME "a"
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    ll a, b, m;
    cin >> a >> b >> m;
    if (a >= m || b >= m) {
        cout << 0;
        return 0;
    }
    if (a <= 0 && b <= 0) {
        cout << -1;
        return 0;
    }
    if (a > b)
        swap(a, b);
    ll res = 0;
    while (a < m && b < m) {
        ll cnt = (b - a) / b + 1;
        res += cnt;
        a += b * cnt;
        swap(a, b);
    }
    cout << res;
}