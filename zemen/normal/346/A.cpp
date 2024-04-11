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

int a[1001];

inline int gcd(int a, int b) {
    while (a && b) {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return a ? a : b;
}

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    int n;
    cin >> n;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        res = gcd(res, a[i]);
    }
    for (int i = 0; i < n; ++i)
        a[i] /= res;
    int maxv = 0;
    for (int i = 0; i < n; ++i)
        maxv = max(maxv, a[i]);
    cout << ((maxv - n) % 2 ? "Alice" : "Bob") << '\n';
}