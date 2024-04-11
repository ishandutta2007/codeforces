#include <bits/stdc++.h>
using namespace std;

const int N = 305;

int n, T, a[N];

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);
        memset(a, 0, sizeof(a));
        int ans = 0;

        for (int x, i = 1; i <= n; i++) {
            scanf("%d", &x);
            a[abs(x)]++;
        }

        for (int i = 0; i <= 100; i++) {
            ans += min(2 - (!i), a[i]);
        }

        printf("%d\n", ans);
    }
}