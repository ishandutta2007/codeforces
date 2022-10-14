#include <bits/stdc++.h>

int T, N, M;
int app[110000];

int main() {
    scanf("%d", &T); while (T--) {
        scanf("%d%d", &N, &M);
        std::fill(app, app + N + 1, 0);
        for (int i = 0; i < M; ++i) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            app[b] = 1;
        }
        int un = -1;
        for (int i = 1; i <= N; ++i) if (!app[i]) un = i;
        for (int i = 1; i <= N; ++i) {
            if (i != un) {
                printf("%d %d\n", i, un);
            }
        }
    }
}