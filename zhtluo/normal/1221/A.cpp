#include <bits/stdc++.h>

int Q, N;
int arr[100];

int main() {
    scanf("%d", &Q);
    for (int q = 0; q < Q; ++q) {
        scanf("%d", &N);
        std::fill(arr, arr + 100, 0);
        for (int i = 0; i < N; ++i) {
            int c;
            scanf("%d", &c);
            ++arr[__builtin_ctz(c)];
        }
        for (int i = 0; i + 1 < 100; ++i) {
            arr[i + 1] += arr[i] >> 1;
        }
        if (arr[11]) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
}