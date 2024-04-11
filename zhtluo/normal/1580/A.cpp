#include <bits/stdc++.h>

char map[500][500];
int precol[500][500], prerow[500][500], pre_comp[500];
int N, M;

int main() {
    int T;
    scanf("%d", &T); while (T--) {
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) scanf(" %c", &map[i][j]), map[i][j] -= '0', map[i][j] ^= 1;
        for (int i = 0; i < N; ++i) for (int j = 1; j <= M; ++j) precol[i][j] = precol[i][j - 1] + map[i][j - 1];
        for (int i = 1; i <= N; ++i) for (int j = 0; j < M; ++j) prerow[i][j] = prerow[i - 1][j] + map[i - 1][j];
        int ans = 1000000;
        for (int i = 0; i < N; ++i) for (int j = i + 4; j < N; ++j) {
            pre_comp[M - 1] = prerow[j][M - 1] - prerow[i + 1][M - 1];
            for (int k = M - 2; k >= 0; --k) pre_comp[k] = prerow[j][k] - prerow[i + 1][k];
            int min = 1000000;
            for (int k = 0; k + 3 < M; ++k) {
                min += map[i][k] + map[j][k] + (j - i - 1) - (prerow[j][k] - prerow[i + 1][k]);
                min = std::min(min, prerow[j][k] - prerow[i + 1][k]);
                ans = std::min(ans, min + pre_comp[k + 3] +
                    map[i][k + 1] + map[i][k + 2] + map[j][k + 1] + map[j][k + 2]
                    + (j - i - 1) - (prerow[j][k + 1] - prerow[i + 1][k + 1])
                    + (j - i - 1) - (prerow[j][k + 2] - prerow[i + 1][k + 2])
                    );
            }
        }
        printf("%d\n", ans);
    }
}