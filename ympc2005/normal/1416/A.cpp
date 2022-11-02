#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int n, T, p[N], a[N], f[N];

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
            p[i] = 0, a[i] = 0;
            f[i] = 1e9;
        }

        for (int x, i = 1; i <= n; i++) {
            scanf("%d", &x);
            a[x] = max(a[x], i - p[x]);
            p[x] = i;
        }

        for (int i = 1; i <= n; i++) {
            a[i] = max(a[i], n + 1 - p[i]);
            f[a[i]] = min(f[a[i]], i);
        }

        for (int i = 1; i <= n; i++) {
            if (i > 1) {
                f[i] = min(f[i], f[i - 1]);
            }

            printf("%d ", f[i] <= n ? f[i] : -1);
        }

        puts("");
    }
}