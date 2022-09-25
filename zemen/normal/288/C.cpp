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

int res[2000001];

void solve(int n) {
    if (n == 1) {
        res[0] = 0;
        return;
    }
    if (!n)
        return;
    int d = 1;
    while ((d << 1) < n)
        d <<= 1;
    cerr << d << '\n';
    for (int i = d; i < n; ++i) {
        res[i] = 2 * d - i - 1;
        res[2 * d - i - 1] = i;
        //~ cerr << i << ' ' << 2 * d - i - 1 << '\n';
    }
    solve(2 * d - n);
}

int main() {
    int n;
    cin >> n;
    ++n;
    solve(n);
    ll sum = 0;
    for (int i = 0; i < n; ++i)
        sum += ll(res[i] ^ i);
    cout << sum << '\n';
    for (int i = 0; i < n; ++i)
        printf("%d ", res[i]);
}