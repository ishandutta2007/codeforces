#include <bits/stdc++.h>
using namespace std;

const int N = 55;

int n, f[N][N][N][N];

char s[N][N];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);

        for (int j = 1; j <= n; j++) {
            f[i][i][j][j] = s[i][j] == '#';
        }
    }

    for (int xl = n; xl; xl--) {
        for (int xr = xl; xr <= n; xr++) {
            for (int yl = n; yl; yl--) {
                for (int yr = yl; yr <= n; yr++) {
                    if (xl == xr && yl == yr) {
                        continue;
                    }

                    int &res = f[xl][xr][yl][yr];
                    res = max(xr - xl + 1, yr - yl + 1);

                    for (int i = xl; i < xr; i++) {
                        res = min(res, f[xl][i][yl][yr] + f[i + 1][xr][yl][yr]);
                    }

                    for (int i = yl; i < yr; i++) {
                        res = min(res, f[xl][xr][yl][i] + f[xl][xr][i + 1][yr]);
                    }
                }
            }
        }
    }

    printf("%d\n", f[1][n][1][n]);
}