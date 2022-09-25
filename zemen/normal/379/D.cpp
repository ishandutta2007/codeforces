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

#define NAME "d"
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

int cnt[100];
char a[100];
char c[100];
char s[100];
char t[100];

char solve(int n, int m) {
    if (cnt[0] * 2 + c[0] + a[0] > n)
        return 0;
    if (cnt[1] * 2 + c[1] + a[1] > m)
        return 0;
    if (c[0]) {
        cout << 'C';
        --n;
    }
    for (int i = 0; i < cnt[0]; ++i)
        cout << "AC";
    n -= cnt[0] * 2;
    for (int i = 0; i < n - a[0]; ++i)
        cout << "B";
    if (a[0])
        cout << "A";
    cout << '\n';
    
    
    if (c[1]) {
        cout << 'C';
        --m;
    }
    for (int i = 0; i < cnt[1]; ++i)
        cout << "AC";
    m -= cnt[1] * 2;
    for (int i = 0; i < m - a[1]; ++i)
        cout << "B";
    if (a[1])
        cout << "A";
    cout << '\n';
    return 1;
}

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    int k, x, n, m;
    cin >> k >> x >> n >> m;
    --k;
    for (cnt[0] = 0; cnt[0] * 2 <= n; ++cnt[0])
        for (cnt[1] = 0; cnt[1] * 2 <= m; ++cnt[1])
            for (a[0] = 0; a[0] < 2; ++a[0])
                for (c[0] = 0; c[0] < 2; ++c[0])
                    for (a[1] = 0; a[1] < 2; ++a[1])
                        for (c[1] = 0; c[1] < 2; ++c[1]) {
                            for (int q = 2; q <= k; ++q) {
                                a[q] = a[q - 1];
                                c[q] = c[q - 2];
                                cnt[q] = cnt[q - 1] + cnt[q - 2] + (c[q - 1] && a[q - 2]);
                                if (cnt[q] > x)
                                    break;
                            }
                            if (cnt[k] == x)
                                if (solve(n, m))
                                    return 0;
                        }
    cout << "Happy new year!\n";
}