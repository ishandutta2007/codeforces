#include <bits/stdc++.h>

int N, K;
int app[110];

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &K);
        for (int i = 1; i <= N; ++i) app[i] = 0;
        for (int i = 1; i <= N; ++i) {
            int u; scanf("%d", &u);
            app[u] = 1;
        }
        int sum = 0;
        for (int i = 1; i <= N; ++i) sum += app[i];
        if (sum > K) printf("-1\n");
        else {
            for (int i = 1; i <= N; ++i) if (app[i]) {
                app[i] += K - sum;
                break;
            }
            printf("%d\n", N * K);
            for (int i = 1, cnt = 0; i <= N; ++i)
                for (int j = 1; j <= N; ++j)
                    for (int k = 1; k <= app[j]; ++k)
                        printf("%d%c", j, " \n"[++cnt == N * K]);
        }
    }
}