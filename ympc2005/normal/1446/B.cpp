#include <bits/stdc++.h>
using namespace std;

const int N = 5005;

int n, m, f[N][N], ans;

char s[N], t[N];

int main() {
    scanf("%d%d%s%s", &n, &m, s + 1, t + 1);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]) - 1;

            if (s[i] == t[j]) {
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 2);
            }

            f[i][j] = max(f[i][j], 0);
            ans = max(ans, f[i][j]);
        }
    }

    printf("%d\n", ans);
}