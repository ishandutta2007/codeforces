#include <bits/stdc++.h>
using namespace std;

int n, k, T;

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &n, &k);

        if ((n + 1)/2 < k) {
            puts("-1");
            continue;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                putchar(i == j && (i&1) && (i/2 + 1 <= k) ? 'R' : '.');
            }

            putchar('\n');
        }
    }
}