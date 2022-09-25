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

char s[5001];
int cnt[100001];

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    int a;
    scanf("%d\n", &a);
    gets(s);
    int n = strlen(s);
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i + 1; j <= n; ++j) {
            sum += s[j - 1] - '0';
            cnt[sum]++;
        }
    }
    ll res = 0;
    if (a == 0) {
        res += ll(cnt[0]) * ll(cnt[0]);
        for (int i = 1; i < 100000; ++i)
            res += 2 * ll(cnt[i]) * ll(cnt[0]);
    } else {
        for (int i = 1; i < 100000; ++i)
            if (a % i == 0 && a / i < 100000) {
                res += ll(cnt[i]) * ll(cnt[a / i]);
            }
    }
    cout << res << '\n';
}