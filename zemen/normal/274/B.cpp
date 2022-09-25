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
//#undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

vector <int> g[100001];
int m[100001];
int n;

pair <ll, ll> dfs(int u, int prev = -1) {
    pair <ll, ll> res = mp(0, 0);
    for (int i = 0; i < (int) g[u].size(); ++i) {
        int v = g[u][i];
        if (v == prev)
            continue;
        pair <ll, ll> cur = dfs(v, u);
        res.fi = max(res.fi, cur.fi);
        res.se = max(res.se, cur.se);
    }
    ll fm = m[u] + res.fi - res.se;
    if (fm < 0)
        res.fi -= fm;
    else
        res.se += fm;
    return res;
}

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    int n, u, v;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        --u;
        --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (int i = 0; i < n; ++i)
        cin >> m[i];
    pair <ll, ll> res = dfs(0);
    cout << res.fi + res.se;
}