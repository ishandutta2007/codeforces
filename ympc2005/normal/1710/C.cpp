#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10, mod = 998244353;

char s[N];

int f[N][2][2][2], n, val, ans;

void add_(int &x, int y) {
    x = (x + y)%mod;
}

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);

    for (int i = 1; i <= n; i++) {
        val = (2ll*val + s[i] - '0')%mod;
    }

    ans = 1ll*(val + 1)*(val + 1)%mod*(val + 1)%mod;
    f[0][0][0][0] = 1;

    for (int i = 0; i < n; i++) {
        int c = s[i + 1] - '0';

        for (int x = 0; x < 2; x++) for (int y = 0; y < 2; y++) for (int z = 0; z < 2; z++) 
        for (int u = 0; u < 2; u++) for (int v = 0; v < 2; v++) for (int w = 0; w < 2; w++) {
            if (u == v && v != w) {
                continue;
            }

            if (u - x > c || v - y > c || w - z > c) {
                continue;
            }

            add_(f[i + 1][x|(u < c)][y|(v < c)][z|(w < c)], f[i][x][y][z]);
        }
    }

    int res = 0;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                add_(res, f[n][i][j][k]);
            }
        }
    }

    res = (res - val - 1)%mod;
    res = (res - 2ll*(val + 1)*val)%mod;
    ans = (ans - 3ll*res)%mod;
    ans = (ans - val - 1)%mod;
    ans = (ans - 3ll*(val + 1)*val)%mod;
    printf("%d\n", (ans%mod + mod)%mod);
}