#include <bits/stdc++.h>

const long long INF = 2E18;
long long len[310000], price[310000];
long long dp[310000][3];

int main() {
    int Q, N;
    scanf("%d", &Q);
    while (Q--) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i)
            scanf("%lld%lld", &len[i], &price[i]);
        for (int i = 0; i < N; ++i) {
            for (int k = 0; k < 3; ++k) {
                dp[i + 1][k] = INF;
                for (int j = 0; j < 3; ++j) {
                    if (i == 0 || len[i - 1] + j != len[i] + k) {
                        dp[i + 1][k] = std::min(dp[i + 1][k], dp[i][j] + price[i] * k);
                    }
                }
//                printf("%d %d %lld\n", i + 1, k, dp[i + 1][k]);
            }
        }
        printf("%lld\n", std::min(std::min(dp[N][0], dp[N][1]), dp[N][2]));
    }
}