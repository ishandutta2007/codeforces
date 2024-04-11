#include <bits/stdc++.h>
using namespace std;

const int N = 3506;

int a[N];

int gao(int L, int R, int before) {
    int ret = 0x3f3f3f3f;
    for (int i = 0; i <= before; ++i) {
        ret = min(ret, max(a[L + i], a[R - (before - i)]));
    }
    return ret;
}

void go() {
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    k = min(k, m - 1);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for (int i = 1; i <= k + 1; ++i) {
        int l = i;
        int r = n - (k - (i - 1));
        ans = max(ans, gao(l, r, m - k - 1));
    }
    printf("%d\n", ans);
}

int main () {
    int T; scanf("%d", &T);
    while (T--) {
        go();
    }
}