#include <bits/stdc++.h>
using namespace std;

const int N = 65, mod = 1e9 + 7;

int n, m, x;

char s[N][N];

int ask_(int xl, int xr, int yl, int yr) {
    int res = 0;

    for (int i = xl; i <= xr; i++) {
        for (int j = yl; j <= yr; j++) {
            res += s[i][j] == 'P';
        }
    }

    return res;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &n, &m);

        for (int i = 1; i <= n; i++) {
            scanf("%s", s[i] + 1);
        }

        if (ask_(1, n, 1, m) == n*m) {
            puts("MORTAL");
        } else if (!ask_(1, n, 1, m)) {
            puts("0");
        } else if (!ask_(1, 1, 1, m) || !ask_(n, n, 1, m) || !ask_(1, n, 1, 1) || !ask_(1, n, m, m)) {
            puts("1");
        } else if (s[1][1] == 'A' || s[1][m] == 'A' || s[n][1] == 'A' || s[n][m] == 'A') {
            puts("2");
        } else {
            bool tag = 0;

            for (int i = 1; i <= n; i++) {
                tag |= !ask_(i, i, 1, m);
            }

            for (int i = 1; i <= m; i++) {
                tag |= !ask_(1, n, i, i);
            }

            if (tag) {
                puts("2");
            } else {
                if (ask_(1, 1, 1, m) < m || ask_(n, n, 1, m) < m || ask_(1, n, 1, 1) < n || ask_(1, n, m, m) < n) {
                    puts("3");
                } else {
                    puts("4");
                }
            }
        }
    }
}