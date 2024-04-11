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
    if (n == 1 && k == 1) {
        cout << 'a';
        return 0;
    }
    if (k > n || k == 1) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n - k + 2; ++i)
        cout << char(i % 2 ? 'b' : 'a');
    for (int i = 0; i + n - k + 2 < n; ++i)
        cout << char(i + 'c');
}