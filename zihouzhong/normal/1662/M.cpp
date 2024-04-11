#include <bits/stdc++.h>
using namespace std;

int T, n, m;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        int mx1 = 0, mx2 = 0;
        while (m--) {
            int r, w;
            scanf("%d %d", &r, &w);
            mx1 = max(mx1, r), mx2 = max(mx2, w);
        }
        if (mx1 + mx2 > n) { puts("IMPOSSIBLE"); continue; }
        for (int i = 1; i <= mx1; i++) putchar('R');
        for (int i = 1; i <= n - mx1; i++) putchar('W');
        putchar('\n');
    }
    return 0;
}