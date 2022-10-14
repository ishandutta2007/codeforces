#include <bits/stdc++.h>

int N, M;
char map[1100000];
int interval[1100000];


int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j)
        scanf(" %c", &map[i * M + j]);
    for (int i = 0; i + 1 < N; ++i) for (int j = 0; j + 1 < M; ++j) {
        if (map[i * M + j + 1] == 'X' && map[(i + 1) * M + j] == 'X') {
            interval[j] = 1;
        }
    }
    for (int i = 1; i <= M; ++i) interval[i] += interval[i - 1];
    int Q; scanf("%d", &Q);
    while (Q--) {
        int u, v; scanf("%d%d", &u, &v);
        // printf("%d\n", query(u - 1, v - 1));
        --u; --v;
        if (v == 0) {
            puts ("YES");
            continue;
        }
        int sum = interval[v - 1];
        if (u > 0) sum -= interval[u - 1];
        if (sum) {
            puts("NO");
        } else {
            puts("YES");
        }
    }
}