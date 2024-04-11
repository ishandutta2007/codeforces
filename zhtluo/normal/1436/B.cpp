#include <bits/stdc++.h>

int coprime[1000];

int main() {
    for (int i = 2; i < 1000; ++i)
        for (int j = 2; i * j < 1000; ++j)
            coprime[i * j] = true;
    int T;
    scanf("%d", &T);
    while (T--) {
        int N; scanf("%d", &N);
        int sum = N;
        for (; coprime[sum] || !coprime[sum - (N - 1)]; sum++);
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                printf("%d%c", i == j ? sum - (N - 1) : 1, " \n"[j + 1 == N]);
    }
}