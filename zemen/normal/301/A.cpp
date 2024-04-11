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
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

int a[100001];

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    int n;
    int sum = 0;
    cin >> n;
    int minabs = 100000;
    int cnt = 0;
    for (int i = 0; i < 2 * n - 1; ++i) {
        cin >> a[i];
        sum += abs(a[i]);
        if (abs(a[i]) < abs(minabs))
            minabs = a[i];
        if (a[i] < 0)
            cnt++;
    }
    if (n % 2 == 0 && cnt % 2 == 1)
        cout << sum - 2 * abs(minabs);
    else
        cout << sum;
}