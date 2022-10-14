#include <bits/stdc++.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long x1, y1, x2, y2;
        scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
        if (x1 == x2 || y1 == y2) {
            printf ("%lld\n", std::abs(x1 - x2) + std::abs(y1 - y2));
        } else {
            printf ("%lld\n", std::abs(x1 - x2) + std::abs(y1 - y2) + 2);
        }
    }
}