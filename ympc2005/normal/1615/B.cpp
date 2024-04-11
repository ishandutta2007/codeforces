#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int T, n = 2e5, s[N][20];

int main() {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 20; j++) {
            s[i][j] = s[i - 1][j] + (!(i&1<<j));
        }
    }

    scanf("%d", &T);

    while (T--) {
        int l, r, ans = 1e9; scanf("%d%d", &l, &r);

        for (int i = 0; i < 20; i++) {
            ans = min(ans, s[r][i] - s[l - 1][i]);
        }

        printf("%d\n", ans);
    }
}