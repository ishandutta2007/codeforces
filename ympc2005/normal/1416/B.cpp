#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10;

int n, a[N], sum, T;

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n), sum = 0;

        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }

        if (sum%n) {
            puts("-1");
            continue;
        }

        sum /= n;
        printf("%d\n", 3*n - 3);

        for (int i = 2; i <= n; i++) {
            int x = a[i]%i ? i - a[i]%i : 0;
            printf("%d %d %d\n", 1, i, x);
            printf("%d %d %d\n", i, 1, (a[i] + x)/i);
        }

        for (int i = 2; i <= n; i++) {
            printf("%d %d %d\n", 1, i, sum);
        }
    }
}