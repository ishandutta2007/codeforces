#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;

int n, x, a[N], f[N][3], T;

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }

        scanf("%d", &x);

        for (int i = 1; i <= n; i++) {
            a[i] -= x;
        }

        if (n == 1) {
            puts("1");
            continue;
        }

        memset(f, -0x3f, sizeof(f));

        f[2][0] = 1;
        f[2][1] = 1;
        f[2][2] = a[1] + a[2] >= 0 ? 2 : -1e9;

        for (int i = 3; i <= n; i++) {
            f[i][0] = max(f[i - 1][0], max(f[i - 1][1], f[i - 1][2]));
            f[i][1] = f[i - 1][0] + 1;
            f[i][2] = -1e9;

            if (a[i] + a[i - 1] >= 0) {
                f[i][2] = f[i - 1][1] + 1;

                if (a[i] + a[i - 1] + a[i - 2] >= 0 && a[i - 1] + a[i - 2] >= 0) {
                    f[i][2] = max(f[i][2], f[i - 1][2] + 1);
                }
            }
        }

        printf("%d\n", max(f[n][0], max(f[n][1], f[n][2])));
    }
}