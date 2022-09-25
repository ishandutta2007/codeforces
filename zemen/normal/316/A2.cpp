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

char s[1000001];
char used[10000];

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    gets(s);
    int n = strlen(s);
    ll res = 1;
    int deg10 = 0;
    for (int i = 0; i < n; ++i) {
        if (isdigit(s[i]))
            continue;
        used[s[i]] = 1;
        if (s[i] == '?')
            ++deg10;
    }
    ll cur = 10;
    for (int i = 'A'; i <= 'J'; ++i) {
        if (used[i]) {
            res *= cur;
            --cur;
        }
    }
    if (!isdigit(s[0])) {
        if (!deg10)
            res /= 10;
        else
            deg10--;
        res *= 9;
    }
    cout << res;
    for (int i = 0; i < deg10; ++i)
        cout << '0';
}