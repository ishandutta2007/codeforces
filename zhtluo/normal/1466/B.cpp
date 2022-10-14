#include <bits/stdc++.h>

int T, N;
int A[310000];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i <= 2 * N; ++i) A[i] = 0;
        for (int i = 0; i < N; ++i) {
            int u; scanf("%d", &u);
            ++A[u];
        }
        int l = 0;
        int sum = 0;
        for (int i = 0; i <= 2 * N; ++i) {
            sum += (A[i] || l);
            if (A[i] + l > 1) l = 1;
            else l = 0;
        }
        printf("%d\n", sum + l);
    }
}