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

#define NAME "b"
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

pair <int, int> cnt[400001];

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    int n, cur;
    cin >> n;
    int c = 0;
    int res = 0;
    for (int i = 0; i < n; ++i) {
        cin >> cur;
        int life = 0;
        while (c && cnt[c - 1].fi < cur) {
            life += cnt[c - 1].se;
            --c;
        }
        if (c) {
            cnt[c - 1].se--;
            if (cnt[c - 1].se == 0)
                --c;
            res = max(res, life + 1);
            cnt[c++] = mp(cur, life + 1);
        } else
            cnt[c++] = mp(cur, INF);
    }
    cout << res << '\n';
}