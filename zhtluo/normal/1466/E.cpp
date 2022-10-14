#include <bits/stdc++.h>

const long long MOD = 1E9 + 7;
const int SIZE = 62;

int T, N;
int bit[SIZE];
long long num[510000], mod[SIZE];

int main() {
    mod[0] = 1;
    for (int i = 1; i < SIZE; ++i) mod[i] = mod[i - 1] * 2 % MOD;
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < SIZE; ++i) bit[i] = 0;
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            scanf("%lld", &num[i]);
            for (int j = 0; j < SIZE; ++j) bit[j] += num[i] >> j & 1;
        }
        long long ans = 0;
        for (int i = 0; i < N; ++i) {
            long long mul1 = 0, mul2 = 0;
            for (int j = 0; j < SIZE; ++j) {
                if (num[i] >> j & 1) {
                    (mul1 += bit[j] * mod[j]) %= MOD;
                    (mul2 += N * mod[j]) %= MOD;
                } else {
                    (mul2 += bit[j] * mod[j]) %= MOD;
                }
            }
            (ans += mul1 * mul2) %= MOD;
        }
        printf("%lld\n", ans);
    }
}