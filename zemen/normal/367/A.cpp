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

#define NAME "a"
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

char s[200001];
int cnt[200001][3];

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    gets(s);
    int n = strlen(s);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j)
            cnt[i + 1][j] = cnt[i][j];
        cnt[i + 1][s[i] - 'x']++;
    }
    
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        --l;
        int c[3];
        for (int j = 0; j < 3; ++j)
            c[j] = cnt[r][j] - cnt[l][j];
        sort(c, c + 3);
        if (r - l < 3 || c[2] - c[0] <= 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}