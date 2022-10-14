#include <bits/stdc++.h>

const int MOD = 1E9 + 7;

int T;
int N;
int A[410000], B[410000];
int cyc[410000];
int vis[410000];

int main () {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            scanf("%d", &A[i]);
        }
        for (int i = 0; i < N; ++i) {
            scanf("%d", &B[i]);
        }
        for (int i = 0; i < N; ++i) {
            cyc[A[i] - 1] = B[i] - 1;
        }
        std::fill(vis, vis + N, 0);
        int count = 0;
        for (int i = 0; i < N; ++i) if (!vis[i]) {
            int j = i; while (!vis[j]) { vis[j] = 1; j = cyc[j]; }
            ++count;
        }
        int ans = 1;
        for (int i = 0; i < count; ++i) {
            ans = (ans + ans) % MOD;
        }
        printf("%d\n", ans);
    }
}