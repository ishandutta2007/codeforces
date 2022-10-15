#include <bits/stdc++.h>
using namespace std;

int T, a, b, c, m;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &a, &b, &c, &m);
        int n = a + b + c - m;
        if (max(0, a - 1) + max(0, b - 1) + max(0, c - 1) < m) { puts("NO"); continue; }
        int mn = (n + 1) / 2;
        if (max(0, a - mn) + max(0, b - mn) + max(0, c - mn) <= m) puts("YES");
        else puts("NO");
    }
    return 0;
}