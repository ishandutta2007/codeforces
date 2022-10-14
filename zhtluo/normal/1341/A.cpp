#include <bits/stdc++.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, a, b, c, d;
        scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
        int l = n * (a - b), r = n * (a + b);
        int ll = c - d, rr = c + d;
        if (std::max(l, ll) <= std::min(r, rr)) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
}