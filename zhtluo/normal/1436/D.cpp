#include <bits/stdc++.h>

int N;
int F[210000], P[210000];
long long A[210000];
__int128 dp[210000];

int main() {
    scanf("%d", &N);
    for (int i = 2; i <= N; ++i) {
        scanf("%d", &F[i]);
        P[F[i]] = 1;
    }
    __int128 sum = 0;
    for (int i = 1; i <= N; ++i) scanf("%lld", &A[i]), sum += A[i];
    __int128 l = 0, r = sum, ans = -1;
    while (l <= r) {
        __int128 m = (l + r) / 2;
        for (int i = 1; i <= N; ++i) dp[i] = A[i];
        for (int i = N; i >= 1; --i) {
            if (!P[i]) dp[i] -= m;
            if (i > 1) {
                dp[F[i]] += dp[i];
            }
        }
        bool test = true;
        for (int i = 1; i <= N; ++i) test &= dp[i] <= 0;
        if (test) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    printf("%lld\n", (long long) ans);
}