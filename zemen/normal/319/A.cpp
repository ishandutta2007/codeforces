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
#define INFL 1000000000000000001
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

int mod = 1000000007;
char s[1000];

inline int pow2(int n) {
    int res = 1;
    for (int i = 0; i < n; ++i) {
        res *= 2;
        res %= mod;
    }
    return res;
}

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    gets(s);
    int n = strlen(s);
    reverse(s, s + n);
    ll res = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            int a = pow2(2 * i);
            int b = pow2(n - i - 1);
            res += (ll(a) * ll(b)) % ll(mod);
            res %= mod;
        }
    }
    cout << res << '\n';
}