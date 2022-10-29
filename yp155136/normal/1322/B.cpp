#include <bits/stdc++.h>
using namespace std;

const int N = 400006;
const int C = 10000006;

int a[N];
int pre[C];

inline int Q(int l, int r, int mx) {
    if (l > r) return 0;
    if (l > mx || r < 0) return 0;
    r = min(r, mx);
    l = max(l, 0);
    return pre[r] - (l > 0 ? pre[l - 1] : 0);
}

int main () {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for (int i = 0; (1 << i) < 2 * C; ++i) {
        int tar = (1 << (i + 1)) - 1;
        memset(pre, 0, sizeof(pre));
        for (int i = 1; i <= n; ++i) {
            pre[ a[i] & tar ]++;
        }
        for (int i = 1; i <= min(tar, C - 1); ++i) {
            pre[i] += pre[i - 1];
        }
        int num = 0;
        for (int i = 1; i <= n; ++i) {
            int x = (a[i] & tar);
            int l = tar / 2 + 1 - x;
            int r = tar - x;
            int gap = min(C - 1, tar);
            num += Q(l, r, gap);
            if (l <= x && x <= r) --num;
            l += tar + 1, r += tar + 1;
            num += Q(l, r, gap);
            if (l <= x && x <= r) --num;
            num &= 3;
        }
        num >>= 1;
        if (num) {
            ans ^= (1 << i);
        }
    }
    printf("%d\n", ans);
}