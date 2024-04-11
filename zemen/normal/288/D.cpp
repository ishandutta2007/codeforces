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

typedef unsigned long long ll;
typedef long double ld;
typedef complex <double> point;

#define NAME "d"
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

ll res = 0;
vector <int> g[100001];
int cnt[100001];
int n;

#define ROOT 0

void dfs(int u = ROOT, int prev = -1) {
    cnt[u] = 1;
    for (int i = 0; i < (int) g[u].size(); ++i) {
        int v = g[u][i];
        if (v == prev)
            continue;
        dfs(v, u);
        cnt[u] += cnt[v];
    }
    ll cres = cnt[u] - 1;
    ll sqsum = 0;
    ll antires = 0;
    for (int i = 0; i < (int) g[u].size(); ++i) {
        int v = g[u][i];
        if (v == prev)
            continue;
        cres += ll(cnt[u] - cnt[v]) * ll(cnt[v]);
        sqsum += (ll(cnt[v]) * ll(cnt[v] - 1)) / 2;
    }
    for (int i = 0; i < (int) g[u].size(); ++i) {
        int v = g[u][i];
        if (v == prev)
            continue;
        ll csq = (ll(cnt[v]) * ll(cnt[v] - 1)) / 2;
        antires += (sqsum - csq) * csq;
    }
    assert(cres % 2 == 0);
    cres /= 2;
    antires /= 2;
    ll cres2 = (ll(n - cnt[u]) * ll(n - cnt[u] - 1)) / 2;
    //~ cerr << u << ' ' << cres << ' ' << cres2 << ' ' << res << ' ' << '\n';
    res -= antires;
    res += cres * cres2;
}

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    int u, v;
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        --u;
        --v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs();
    cout << res * 2 << '\n';
}