#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 25;

int T, n, m = 22, d[M][M];

char a[N], b[N];

void solve_() {
    for (int i = 1; i <= n; i++) {
        if (a[i] > b[i]) {
            puts("-1");
            return;
        }

        if (a[i] < b[i]) {
            d[a[i] - 'a'][b[i] - 'a'] = 1;
        }
    }

    int ans = 0;

    for (int i = 0; i < m; i++) {
        int mn = m;

        for (int j = i + 1; j < m; j++) {
            if (d[i][j]) {
                mn = j;
                break;
            }
        }

        if (mn == m) {
            continue;
        }

        ans++;

        for (int j = mn + 1; j < m; j++) {
            d[mn][j] |= d[i][j];
        }
    }

    printf("%d\n", ans);
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%s%s", &n, a + 1, b + 1);
        memset(d, 0, sizeof(d));
        solve_();
    }
}