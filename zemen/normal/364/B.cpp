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

int c[100];
char can[1000001];

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    int n, d;
    cin >> n >> d;
    int sum = 0;
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    sort(c, c + n);
    for (int i = 0; i < n; ++i) {
        if (sum + d < c[i]) {
            n = i;
            break;
        }
        sum += c[i];
    }
    can[0] = 1;
    sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = sum; j >= 0; --j)
            can[j + c[i]] |= can[j];
        sum += c[i];
    }
    int cur = 0;
    int f = 0;
    while (cur < sum) {
        for (int i = cur + d; i > cur; --i)
            if (can[i]) {
                cur = i;
                ++f;
                break;
            }
    }
    cout << sum << ' ' << f << '\n';
}