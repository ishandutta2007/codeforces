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

char a[5001][5001];
int l[5001];
int s[5001];
int cnt[5001];

void fast_sort(int n, int bound) {
    //~ for (int i = 0; i < n; ++i)
        //~ cerr << l[i] << ' ';
    //~ cerr << '\n';
    for (int i = 0; i < bound; ++i)
        cnt[i] = 0;
    for (int i = 0; i < n; ++i)
        cnt[l[i]]++;
    int c = 0;
    for (int i = 0; i < bound; ++i)
        for (int j = 0; j < cnt[i]; ++j)
            s[c++] = i;
    //~ cerr << c << ' ' << n << '\n';
    assert(c == n);
}

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    int n, m;
    scanf("%d%d\n", &n, &m);
    for (int i = 0; i < n; ++i)
        gets(a[i]);
    int res = 0;
    for (int y = 0; y < m; ++y) {
        for (int i = 0; i < n; ++i)
            if (a[i][y] == '1')
                l[i]++;
            else
                l[i] = 0;
        fast_sort(n, m + 1);
        for (int i = 0; i < n; ++i)
            res = max(res, s[i] * (n - i));
    }
    cout << res << '\n';
}