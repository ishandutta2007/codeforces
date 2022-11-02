#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 10;

int T, n, m, a[N], b[N];

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &n, &m);

        for (int i = 1; i <= m; i++) {
            a[i] = 0;
        }

        for (int x, i = 1; i <= n; i++) {
            scanf("%d", &x);
            a[x]++;
        }

        for (int i = 1; i <= m; i++) {
            b[i] = b[i - 1] + a[i];
        }

        bool ok = 1;

        for (int i = 1; i <= m; i++) {
            if (!a[i]) {
                continue;
            }

            for (int j = i; j <= m; j += i) {
                if (b[min(m, j + i - 1)] - b[j - 1] > 0) {
                    if (!a[j/i]) {
                        ok = 0;
                    }
                }
            }
        }

        printf("%s\n", ok ? "Yes" : "No");
    }
}