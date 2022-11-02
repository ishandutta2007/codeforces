#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, m, f[N][2], g[N][2];

char s[N];

bool chk_(int l1, int r1, int l2, int r2) {
    return min(r1 - l1 + 1, r2 - l2 + 1) <= m;
}

int main() {
    scanf("%d%d%s", &n, &m, s + 1);

    f[0][0] = f[0][1] = -1e9;

    for (int i = 1; i <= n; i++) {
        f[i][0] = f[i - 1][0];
        f[i][1] = f[i - 1][1];
        f[i][s[i] - '0'] = i;
    }

    g[n + 1][0] = g[n + 1][1] = 1e9;

    for (int i = n; i; i--) {
        g[i][0] = g[i + 1][0];
        g[i][1] = g[i + 1][1];
        g[i][s[i] - '0'] = i;
    }

    if (chk_(g[1][0], f[n][0], g[1][1], f[n][1])) {
        puts("tokitsukaze");
        exit(0);
    }

    for (int i = 1; i + m - 1 <= n; i++) {
        int l[2], r[2];

        for (int j = 0; j < 2; j++) {
            l[j] = g[1][j] < i ? g[1][j] : g[i + m][j];
            r[j] = f[n][j] >= i + m ? f[n][j] : f[i - 1][j];
        }

        if (!chk_(l[0], r[0], min(i, l[1]), max(i + m - 1, r[1]))) {
            puts("once again");
            exit(0);
        }

        if (!chk_(min(l[0], i), max(r[0], i + m - 1), l[1], r[1])) {
            puts("once again");
            exit(0);
        }
    }

    puts("quailty");
}