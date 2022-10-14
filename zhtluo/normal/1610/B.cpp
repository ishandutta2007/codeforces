#include <bits/stdc++.h>

int N;
int A[210000];
int op[2], size = 0;
int B[210000], bs = 0;

bool check(int o) {
    bs = 0;
    for (int i = 0; i < N; ++i) if (A[i] != o) {
        B[bs++] = A[i];
    }
    for (int i = 0; i < bs; ++i) {
        // printf(": %d\n", B[i]);
        if (B[i] != B[bs - 1 - i]) return false;
    }
    return true;
}

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
        size = 0;
        for (int i = 0; i < N; ++i) {
            if (A[i] != A[N - 1 - i]) {
                op[0] = A[i]; op[1] = A[N - 1 - i]; size = 2; break;
            }
        }
        if (size == 0 || check(op[0]) || check(op[1])) {
            puts("YES");
        } else {
            puts ("NO");
        }
    }
}