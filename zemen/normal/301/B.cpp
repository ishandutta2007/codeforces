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

int n, mul;
int delta[1001];
int x[1001], y[1001];
int d[1001];
char used[1001];

inline int dist(int u, int v) {
    return mul * (abs(x[u] - x[v]) + abs(y[u] - y[v]));
}

char check(int c) {
    fill(d, d + n, -INF);
    memset(used, 0, sizeof(used));
    d[0] = c;
    while (d[n - 1] < 0) {
        int u = -1;
        for (int i = 0; i < n; ++i)
            if (!used[i] && (u == -1 || d[u] < d[i]))
                u = i;
        assert(u != -1);
        used[u] = 1;
        if (d[u] == -INF)
            return 0;
        for (int i = 0; i < n; ++i) {
            if (used[i])
                continue;
            int nd = d[u] - dist(u, i);
            if (nd < 0)
                continue;
            d[i] = max(d[i], nd + delta[i]);
        }
    }
    return 1;
}

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    cin >> n >> mul;
    for (int i = 0; i < n - 2; ++i)
        cin >> delta[i + 1];
    for (int i = 0; i < n; ++i)
        cin >> x[i] >> y[i];
    int rmin = -1, rmax = 100000000;
    while (rmin + 1 < rmax) {
        int c = (rmin + rmax) / 2;
        if (check(c))
            rmax = c;
        else
            rmin = c;
    }
    cout << rmax << '\n';
}