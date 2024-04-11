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
    int n, k;
    cin >> n >> k;
    int nn = 0;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            ++nn;
    if (k >= nn) {
        cout << "no solution\n";
        return 0;
    }
    for (int i = 0; i < n; ++i)
        cout << 0 << ' ' << i << '\n';
}