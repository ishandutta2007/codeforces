#include <bits/stdc++.h>

int T, N, M;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &M);
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            int a; scanf("%d", &a);
            sum += a;
        }
        puts(sum == M ? "YES" : "NO");
    }
}