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

#define NAME "b"
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

pair <int, int> a[200001];
pair <int, pair <int, int> > b[200001];
multiset <int> s;
multiset <pair <int, int> > t;
int ans[200001];

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    int n, m, S;
    cin >> n >> m >> S;
    for (int i = 0; i < m; ++i) {
        cin >> a[i].fi;
        a[i].fi = -a[i].fi;
        a[i].se = i;
    }
    sort(a, a + m);
    for (int i = 0; i < m; ++i) {
        a[i].fi = -a[i].fi;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i].fi);
        b[i].fi = -b[i].fi;
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i].se.fi);
        b[i].se.se = i;
    }
    sort(b, b + n);
    for (int i = 0; i < n; ++i) {
        b[i].fi = -b[i].fi;
    }
    int rmin = 0, rmax = m + 1;
    while (rmin + 1 < rmax) {
        int c = (rmin + rmax) / 2;
        s.clear();
        int bd = 0;
        int cost = S;
        char good = 1;
        
        for (int i = 0; i < m; i += c) {
            while (bd < n && b[bd].fi >= a[i].fi) {
                s.insert(b[bd].se.fi);
                ++bd;
            }
            int val = *s.begin();
            if (val > cost) {
                good = 0;
                break;
            }
            cost -= val;
            if (s.empty()) {
                good = 0;
                break;
            }
            s.erase(s.begin());
        }
        if (good)
            rmax = c;
        else
            rmin = c;
    }
    if (rmax == m + 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        
        
        int c = rmax;
        //~ cerr << c << '\n';
        t.clear();
        int bd = 0;
        
        for (int i = 0; i < m; i += c) {
            while (bd < n && b[bd].fi >= a[i].fi) {
                t.insert(b[bd].se);
                ++bd;
            }
            assert(!t.empty());
            int id = t.begin()->se;
            t.erase(t.begin());
            for (int j = 0; j < c && i + j < m; ++j) {
                ans[a[i + j].se] = id;
            }
        }
        
        for (int i = 0; i < m; ++i)
            cout << ans[i] + 1 << ' ';
        cout << '\n';
    }
}