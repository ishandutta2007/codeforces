#include <bits/stdc++.h>


int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        long long X, Y, A, B;
        scanf("%lld%lld%lld%lld", &X, &Y, &A, &B);
        B = std::min(B, A * 2);
        printf("%lld\n", std::min(X, Y) * B + std::abs(X - Y) * A);
    }
    return 0;
}