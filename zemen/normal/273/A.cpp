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
//#undef NAME
#ifndef NAME
	#error "Write problem name"
#endif

ll a[100001];

int main() {
	#ifdef _GEANY
	assert(freopen(NAME ".in", "r", stdin));
	#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int m, w, h;
    cin >> m;
    ll curh = 0;
    for (int i = 0; i < m; ++i) {
        cin >> w >> h;
        if (w > n)
            w = n;
        --w;
        curh = max(curh, a[w]);
        cout << curh << '\n';
        curh += (ll) h;
    }
}