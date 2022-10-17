#include <bits/stdc++.h>
using namespace std;

const int maxn = 3010;
int T, n, a[maxn], pre[maxn], lst[maxn], f[maxn][maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        fill(lst + 1, lst + n + 1, 0);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            pre[i] = lst[a[i]], lst[a[i]] = i;
        }
        for (int len = 2; len <= n; len++) {
            for (int l = 1, r = len; r <= n; l++, r++) {
                f[l][r] = f[l][r - 1] + 1;
                for (int k = pre[r]; k >= l; k = pre[k]) {
                    f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r]);
                }
            }
        }
        printf("%d\n", f[1][n]);
    }
    return 0;
}