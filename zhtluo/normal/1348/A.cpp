#include <bits/stdc++.h>

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int N; scanf("%d", &N);
        long long sum = 1ll << N;
        for (int i = 1; i <= N / 2 - 1; ++i) {
            sum += 1ll << i;
        }
        for (int i = N / 2; i < N; ++i) {
            sum -= 1ll << i;
        }
        printf("%lld\n", sum);
    }
    return 0;
}