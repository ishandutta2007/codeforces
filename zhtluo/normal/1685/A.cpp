#include <bits/stdc++.h>

int T, N;
int A[110000];
int ord[110000];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) scanf("%d", &A[i]);
        std::sort(A, A + N);
        int cnt = 0;
        for (int i = 0; i < N; i += 2) ord[i] = cnt++;
        for (int i = 1; i < N; i += 2) ord[i] = cnt++;
        for (int i = 0; i < N; ++i) {
            int mid = A[ord[i]], left = A[ord[(i + N - 1) % N]], right = A[ord[(i + 1) % N]];
            if (!((mid > left && mid > right) || (mid < left && mid < right))) {
                puts("NO");
                goto end;
            }
        }
        puts ("YES");
        for (int i = 0; i < N; ++i) printf("%d%c", A[ord[i]], " \n"[i + 1 == N]);
        end:;
    }
}