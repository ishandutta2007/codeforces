#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <set>
#include <map>
#include <queue>

using namespace std;

template <typename T> void chkmax(T &x, T y) {x = x > y ? x : y;}
template <typename T> void chkmin(T &x, T y) {x = x > y ? y : x;}

typedef long long ll;

const int INF = 2139062143;

#define DEBUG(x) std::cerr << #x << " = " << x << std::endl

inline ll read() {
    ll f = 1, x = 0; char ch;
    do {ch = getchar(); if (ch == '-') f = -1;} while (ch > '9' || ch < '0');
    do {x = x * 10 + ch - '0'; ch = getchar();} while (ch >= '0' && ch <= '9');
    return f * x;
}

#define int ll

const int MAX_N = 2e5 + 25;

int n, f[MAX_N], pos[MAX_N], group[MAX_N];

struct Node {
    int pos, val;
    bool operator < (const Node &rhs) const {
        return val < rhs.val;
    }
} a[MAX_N];

signed main() {
    n = read ();
    a[n].val = a[n + 1].val = a[n + 2].val = a[n + 3].val = INF;
    for (int i = 0; i < n; i ++ ) a[i].val = read (), a[i].pos = i;
    sort (a, a + n);
    memset (f, 127, sizeof (f));
    f[0] = 0;
    for (int i = 0; i < n; i ++ ) {
        if (f[i + 5] > f[i] + a[i + 4].val - a[i].val) {
            pos[i + 5] = i;
            f[i + 5] = f[i] + a[i + 4].val - a[i].val;
        }
        if (f[i + 4] > f[i] + a[i + 3].val - a[i].val) {
            pos[i + 4] = i;
            f[i + 4] = f[i] + a[i + 3].val - a[i].val;          
        }
        if (f[i + 3] > f[i] + a[i + 2].val - a[i].val) {
            pos[i + 3] = i;
            f[i + 3] = f[i] + a[i + 2].val - a[i].val;
        }
    }
    int cur = n, cnt = 1;
    while (cur) {
        for (int i = cur - 1; i >= pos[cur]; i -- ) group[a[i].pos] = cnt;
        cnt ++ ;
        cur = pos[cur];
    }
    printf ("%I64d %I64d\n", f[n], cnt - 1);
    for (int i = 0; i < n; i ++ ) printf ("%I64d ", group[i]);
    return 0;
}