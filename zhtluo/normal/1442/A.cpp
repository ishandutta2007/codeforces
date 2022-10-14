#include <bits/stdc++.h>

long long A[31000];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) scanf("%lld", &A[i]);
        for (int i = N - 1; i >= 1; --i) A[i] -= A[i - 1];
        long long sum = 0;
        for (int i = 0; i < N; ++i) {
            if (A[i] < 0) sum += A[i];
        }
        if (A[0] + sum >= 0) puts("YES");
        else puts("NO");
    }
    return 0;
}