#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10, M = 205, mod = 998244353;

int n, a[N], f[2][M][2], m = 200;

void add_(int &x, int y) {
    x = (x + y)%mod;
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    cin>>n;

    for (int i = 1; i <= n; i++) {
        cin>>a[i];
    }

    int cur = 0, pre = 1;

    if (a[1] > 0) {
        f[cur][a[1]][0] = 1;
    } else {
        for (int i = 1; i <= m; i++) {
            f[cur][i][0] = 1;
        }
    }

    for (int i = 2; i <= n; i++) {
        cur ^= 1, pre ^= 1;
        memset(f[cur], 0, sizeof(f[cur]));

        for (int sum = 0, j = 1; j <= m; j++) {
            add_(sum, f[pre][j - 1][0]);
            add_(sum, f[pre][j - 1][1]);
            f[cur][j][0] = sum;
        }

        for (int sum = 0, j = m; j; j--) {
            add_(sum, f[pre][j][1]);
            f[cur][j][1] = (sum + f[pre][j][0])%mod;
        }

        if (a[i] > 0) {
            for (int j = 1; j <= m; j++) {
                if (a[i] != j) {
                    f[cur][j][0] = f[cur][j][1] = 0;
                }
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= m; i++) {
        add_(ans, f[cur][i][1]);
    }

    printf("%d\n", (ans%mod + mod)%mod);
}