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
#include <list>

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

#define NAME "c"
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

int c[100001];
list <int> p;
typedef list <int>::iterator iter;

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        scanf("%d", c + i);
    sort(c, c + n);
    n = unique(c, c + n) - c;
    for (int i = 0; i < n; ++i)
        p.pb(c[i]);
    int a, b;
    int res = 0;
    cin >> a >> b;
    while (a > b) {
        int to = a - 1;
        for (iter it = p.begin(); it != p.end(); ) {
            if (a - a % (*it) < b) {
                iter qw = it;
                ++it;
                p.erase(qw);
                continue;
            }
            to = min(to, a - a % (*it));
            ++it;
        }
        a = to;
        ++res;
    }
    cout << res << '\n';
}