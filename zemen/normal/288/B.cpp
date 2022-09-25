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

#define NAME "b"
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

#define MOD 1000000007

int n, k;
int res = 0;
int p[10][10];
int sz[10];
int q[10];

inline int mul(int a, int b) {
    return int((ll(a) * ll(b)) % ll(MOD));
}

inline void check() {
    q[0] = 0;
    int c = 1;
    for (int i = 0; i < c; ++i) {
        int u = q[i];
        for (int j = 0; j < sz[u]; ++j)
            q[c++] = p[u][j];
    }
    if (c == k)
        res += k;
}

inline void dfs(int c) {
    if (c == k) {
        check();
        return;
    }
    for (int i = 0; i < k; ++i) {
        p[i][sz[i]] = c;
        ++sz[i];
        dfs(c + 1);
        --sz[i];
    }
}

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    cin >> n >> k;
    dfs(1);
    for (int i = 0; i < n - k; ++i)
        res = mul(res, n - k);
    cout << res;
}