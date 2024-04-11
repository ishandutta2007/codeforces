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

#define NAME "b"
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

int a[200001];
map <int, int> b;
map <int, int> s;
vector <int> res;

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    int n, m, p;
    cin >> n >> m >> p;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < m; ++i) {
        int t;
        cin >> t;
        b[t]++;
    }
    for (int st = 0; st < p; ++st) {
        s.clear();
        int good = 0;
        int cnt = 0;
        for (int i = st; i < n; i += p) {
            if (s[a[i]] < b[a[i]])
                ++good;
            ++s[a[i]];
            ++cnt;
            if (cnt > m) {
                int id = i - p * m;
                if (s[a[id]] <= b[a[id]])
                    --good;
                --s[a[id]];
                --cnt;
            }
            //~ cerr << cnt << ' ' << good << '\n';
            if (good == m)
                res.pb(i - p * (m - 1));
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << '\n';
    for (int i = 0; i < (int) res.size(); ++i)
        cout << res[i] + 1 << ' ';
}