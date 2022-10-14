#include <bits/stdc++.h>

int arr[2000];
int N, X, pos;
int MOD = 1000000007;

int main() {
    scanf("%d%d%d", &N, &X, &pos);
    int left = 0, right = N;
    while (left < right) {
        int middle = (left + right) / 2;
        arr[middle] = 1;
        if (middle <= pos) left = middle + 1;
        else right = middle;
    }
    int small = 0, big = 0;
    for (int i = 0; i < pos; ++i) small += arr[i];
    for (int i = pos + 1; i < N; ++i) big += arr[i];
    int ans = 1;
    for (int i = 0; i < small; ++i) ans = 1ll * ans * (X - 1 - i) % MOD;
    for (int i = 0; i < big; ++i) ans = 1ll * ans * (N - X - i) % MOD;
    for (int i = 0; i < N - 1 - small - big; ++i) ans = 1ll * ans * (N - 1 - small - big - i) % MOD;
    printf("%d\n", ans);
}