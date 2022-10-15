#include <bits/stdc++.h>
using namespace std;

const int maxn = 5010;
int T, n, lcp[maxn][maxn], mx[maxn], f[maxn][maxn], g[maxn][maxn], suf[maxn];
char s[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %s", &n, s + 1);
        for (int i = 1; i <= n + 1; i++) {
            for (int j = 1; j <= n + 1; j++) lcp[i][j] = 0;
        }
        for (int i = n; i; i--) {
            for (int j = n; j; j--) {
                if (s[i] == s[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
                else lcp[i][j] = 0;
            }
        }
        for (int l = 1; l <= n; l++) {
            mx[l] = 0;
            fill(suf + l, suf + n + 1, 0);
            for (int k = 1; k < l; k++) {
                int r1 = l + lcp[l][k] - 1, r2 = k + lcp[l][k] - 1;
                if (r1 < n && s[r1 + 1] > s[r2 + 1]) {
                    suf[r1 + 1] = max(suf[r1 + 1], g[k][r2 + 1]);
                }
                if (r1 < n) {
                    suf[r1 + 1] = max(suf[r1 + 1], f[k][r2]);
                }
            }
            for (int r = l, lst = 0; r <= n; r++) {
                lst = max(lst, suf[r]);
                int ans = lst + 1;
                f[l][r] = ans, mx[l] = max(mx[l], ans);
                lst = max(lst, ans);
            }
            for (int i = n; i >= l; i--) {
                if (i == n) g[l][i] = f[l][i];
                else g[l][i] = max(f[l][i], g[l][i + 1]);
            }
        }
        printf("%d\n", *max_element(mx + 1, mx + n + 1));
    }
    return 0;
}