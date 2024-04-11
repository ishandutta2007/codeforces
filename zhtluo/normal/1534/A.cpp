#include <bits/stdc++.h>

int T;
int N, M;
char str[100][100];
char col[2] = {'R', 'W'};

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &N, &M);
        for (int i = 0; i < N; ++i)
            scanf(" %s", str[i]);
        for (int t = 0; t < 2; ++t) {
            bool pos = true;
            for (int i = 0; i < N; ++i)
                for (int j = 0; j < M; ++j) {
                    if (str[i][j] != '.' && str[i][j] != col[(i & 1) ^ (j & 1) ^ t]) {
                        pos = false;
                    }
                }
            if (pos) {
                printf("YES\n");
                for (int i = 0; i < N; ++i) {
                    for (int j = 0; j < M; ++j)
                        printf("%c", col[(i & 1) ^ (j & 1) ^ t]);
                    printf("\n");
                }
                goto end;
            }
        }
        printf("NO\n");
        end:;
    }
}