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

#define NAME "g"
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

char s[2001];
char t[10][2001];
int tl[10];
int l[2001];
int r[2001];
int n, len;
int z[10001];
char b[10001];
char good[2001][2001];

const ll mod = 1000000021;
const ll alpha = 31;
ll h[5001];
ll apow[5001];
set <ll> ht;
int res = 0;

void addh(int l, int r) {
    ll hl = h[l] * apow[r - l];
    hl %= mod;
    ll ch = (h[r] - hl + mod) % mod;
    if (ht.find(ch) == ht.end()) {
        ht.insert(ch);
        ++res;
    }
}

inline void calc(int n) {
    for (int i = 0; i <= n; ++i)
        z[i] = 0;
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && b[z[i]] == b[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

int sum[10001];

void solve(const int lb) {
    int ret = 0;
    for (int i = lb + 1; i <= len; ++i)
        good[lb][i] = 1;
    int bl = 0;
    for (int i = lb; i < len; ++i)
        b[bl++] = s[i];
    b[bl++] = '#';
    int bs = bl;
    for (int ii = 0; ii < n; ++ii) {
        bl = bs;
        for (int i = 0; i < tl[ii]; ++i)
            b[bl++] = t[ii][i];
        calc(bl);
        for (int i = 0; i <= bs; ++i)
            sum[i] = 0;
        for (int i = bs; i < bl; ++i) {
            sum[z[i]]++;
        }
        int cs = 0;
        for (int i = bs; i >= 0; --i) {
            cs += sum[i];
            sum[i] = cs;
        }
        for (int i = 1; i < bs; ++i)
            if (!(l[ii] <= sum[i] && sum[i] <= r[ii])) {
                good[lb][lb + i] = 0;
            }
    }
}

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    gets(s);
    len = strlen(s);
    for (int i = 0; i < len; ++i) {
        h[i + 1] = h[i] * alpha + (s[i] - 'a' + 1);
        h[i + 1] %= mod;
    }
    apow[0] = 1;
    for (int i = 0; i <= len; ++i)
        apow[i + 1] = (apow[i] * alpha) % mod;
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s%d%d\n", t[i], l + i, r + i);
        tl[i] = strlen(t[i]);
    }
    for (int i = 0; i < len; ++i)
        solve(i);
    n = len;
    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i + len <= n; ++i)
            if (good[i][i + len]) {
                //~ cerr << i << ' ' << i + len << '\n';
                addh(i, i + len);
            }
        ht.clear();
    }
    cout << res << '\n';
}