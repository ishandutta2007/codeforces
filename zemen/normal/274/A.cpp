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

int a[100001];
set <int> ex;
int cnt = 0;

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    int n, k, a;
    cin >> n >> k;
    if (k == 1) {
        cout << n;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a;
        ex.insert(a);
    }
    while (!ex.empty()) {
        int c = 1;
        int q = *(ex.begin());
        ex.erase(q);
        while ((ll) q * (ll) k <= 1000000000ll && ex.find(q * k) != ex.end()) {
            ex.erase(q * k);
            ++c;
            q *= k;
        }
        cnt += c / 2 + c % 2;
    }
    cout << cnt;
}