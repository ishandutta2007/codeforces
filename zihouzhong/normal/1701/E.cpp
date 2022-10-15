#include <bits/stdc++.h>
using namespace std;

const int maxn = 5010;
int T, n, m, lcs[maxn][maxn];
bool f[maxn][maxn], g[maxn][maxn];
char s[maxn], t[maxn];

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> n >> m >> s + 1 >> t + 1;
        for (int i = 0; i <= n + 1; i++) {
            for (int j = 0; j <= m + 1; j++) f[i][j] = g[i][j] = 0;
        }
        f[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                f[i][j] |= f[i - 1][j];
                if (j && s[i] == t[j]) f[i][j] |= f[i - 1][j - 1];
            }
            for (int j = 1; j <= m; j++) {
                if (s[i] == t[j]) lcs[i][j] = lcs[i - 1][j - 1] + 1;
                else lcs[i][j] = 0;
            }
        }
        g[n + 1][m + 1] = 1;
        for (int i = n; i; i--) {
            for (int j = 1; j <= m + 1; j++) {
                g[i][j] |= g[i + 1][j];
                if (j <= m && s[i] == t[j]) g[i][j] |= g[i + 1][j + 1];
            }
        }
        int ans = INT_MAX;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) if (f[i][j] && g[i + 1][j + 1]) {
                int pre = lcs[i][j];
                ans = min(ans, n - i + (i - pre > 0) + i - pre + i - j);
            }
        }
        if (ans == INT_MAX) cout << "-1\n";
        else cout << ans << "\n";
    }
    return 0;
}