#include <bits/stdc++.h>

int N;
int A[5000];
int dp[5000][5000];
int col[5000], next[5000], prev[5000];

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
        std::fill(col, col + N + 1, -1);
        std::fill(next, next + N + 1, -1);
        for (int i = 0; i < N; ++i) {
            if (col[A[i]] >= 0) next[col[A[i]]] = i;
            col[A[i]] = i;
        }
        std::fill(col, col + N + 1, -1);
        std::fill(prev, prev + N + 1, -1);
        for (int i = N - 1; i >= 0; --i) {
            if (col[A[i]] >= 0) prev[col[A[i]]] = i;
            col[A[i]] = i;
        }
        for (int i = 0; i <= N; ++i) std::fill(dp[i], dp[i] + N + 1, 0);
        for (int i = 0; i + 1 < N; ++i)
            dp[i][i + 2] = (A[i] != A[i + 1]);
        for (int len = 3; len <= N; ++len) {
            for (int i = 0; i + len <= N; ++i) {
                dp[i][i + len] = dp[i + 1][i + len - 1] + (A[i] == A[i + len - 1] ? 1 : 2);
                for (int j = next[i]; j < i + len - 1 && j != -1; j = next[j]) {
                    dp[i][i + len] = std::min(dp[i][i + len], dp[i][j + 1] + dp[j + 1][i + len] + (A[i] == A[i + len - 1] ? 0 : 1));
                }
                for (int j = prev[i + len - 1]; j > i && j != -1; j = prev[j]) {
                    dp[i][i + len] = std::min(dp[i][i + len], dp[i][j] + dp[j][i + len] + (A[i] == A[i + len - 1] ? 0 : 1));
                }
            }
        }
        // printf(": %d\n", dp[0][2]);
        // printf(": %d\n", dp[2][3]);
        printf("%d\n", dp[0][N]);
    }
}