#include <bits/stdc++.h>

const long long MOD = 1E9 + 7;

int A[210000];

long long fac[210000];
long long inv[210000];
long long po2[210000];
int cnt[31];

long long C(long long a, long long b) {
    if (a - b < 0) return 0;
    return fac[a] * inv[a - b] % MOD * inv[b] % MOD;
}

int main() {
    fac[0] = 1;
    for (int i = 1; i <= 200100; ++i) fac[i] = fac[i - 1] * i % MOD;
    for (int i = 0; i <= 200100; ++i) {
        long long tms = MOD - 2, cur = fac[i]; inv[i] = 1;
        while (tms) {
            if (tms & 1) inv[i] = inv[i] * cur % MOD;
            cur = cur * cur % MOD;
            tms >>= 1;
        }
    }
    po2[0] = 1;
    for (int i = 1; i <= 200100; ++i) po2[i] = po2[i - 1] * 2 % MOD;
    int N; scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
        for (int j = 30; j >= 0; --j) if ((A[i] & ((1 << j) - 1)) == 0) {
            ++cnt[j]; break;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= 30; ++i) {
        int sum = 0;
        for (int j = i + 1; j <= 30; ++j) sum += cnt[j];
        for (int j = 1; j <= cnt[i]; j += 2) ans = (ans + C(cnt[i], j) * po2[sum]) % MOD;
    }
    long long po = 1;
    for (int i = 0; i < N; ++i) po = po * 2 % MOD;
    printf("%lld\n", (po - 1 - ans + MOD + MOD) % MOD);
}