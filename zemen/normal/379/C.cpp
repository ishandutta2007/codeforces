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
typedef complex <ld> point;

#define NAME "c"
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

pair <int, int> a[1000001];
int ans[1000001];

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a, a + n);
    int lb = 1;
    for (int i = 0; i < n; ++i) {
        if (lb < a[i].fi)
            lb = a[i].fi;
        ans[a[i].se] = lb;
        ++lb;
    }
    for (int i = 0; i < n; ++i)
        cout << ans[i] << ' ';
    cout << '\n';
}