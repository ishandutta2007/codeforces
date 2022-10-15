#include <bits/stdc++.h>

int N, K;
int M[210000];
int C[210000];
std::vector <int> out[210000];

int main() {
    scanf("%d%d", &N, &K);
    // N = 200000; K = 200000;
    for (int i = 0; i < N; ++i) {
        int u; scanf("%d", &u); // u = rand() % K + 1;
        ++M[u];
    }
    for (int i = 1; i <= K; ++i) {
        scanf("%d", &C[i]); // C[i] = 1;
    }
    int ans = 0, sum = 0;
    for (int i = K; i >= 1; --i) {
        sum += M[i];
        ans = std::max(ans, (sum + C[i] - 1) / C[i]);
    }
    printf("%d\n", ans);
    for (int i = K; i >= 1; --i) {
        int l = 0, r = ans - 1, p = 0;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (out[m].size() < C[i]) {
                p = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        for (int j = p; j < ans; ++j) {
            while (M[i] > 0 && out[j].size() < C[i]) {
                --M[i]; out[j].push_back(i);
            }
            if (M[i] == 0) break;
        }
    }
    for (int i = 0; i < ans; ++i) {
        printf("%d ", (int) out[i].size());
        for (int j = 0; j < (int) out[i].size(); ++j) {
            printf("%d%c", out[i][j], " \n"[j + 1 == (int) out[i].size()]);
        }
    }
}