#include <bits/stdc++.h>

int arr[40010], pre[40010];
int A, B, Q;

long long comp(long long x) {
    return x / (A * B) * pre[A * B] + pre[x % (A * B)];
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &A, &B, &Q);
        for (int i = 0; i < A * B; ++i) {
            arr[i] = i % A % B != i % B % A;
        }
        for (int i = 1; i <= A * B; ++i) {
            pre[i] = arr[i - 1] + pre[i - 1];
        }
        for (int q = 0; q < Q; ++q) {
            long long L, R; scanf("%lld%lld", &L, &R);
            printf("%lld%c", comp(R + 1) - comp(L), " \n"[q + 1 == Q]);
        }
    }
}