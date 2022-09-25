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

#define NAME "a"
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

ll a[200001];

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    ll r = 0;
    for (int i = 0; i < n; ++i)
        r += a[n - 1] - a[i];
    ll res = a[n - 1];
    if (a[n - 1] > r) {
        res += (a[n - 1] - r + n - 2) / (n - 1);
    }
    cout << res << '\n';
}