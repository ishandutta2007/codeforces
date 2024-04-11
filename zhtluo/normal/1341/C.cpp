#include <bits/stdc++.h>

int P[110000];

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int N;
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) scanf("%d", &P[i]);
        bool f = true;
        for (int i = N - 1, cur = 1; i >= 0;) {
            int j = P[i], l = i;
            for (; j >= cur; --j, --l) {
                if (l < 0 || P[l] != j) {
                    f = false; goto end;
                }
            }
            cur = P[i] + 1; i = l;
        }
        end:;
        puts (f ? "Yes" : "No");
    }
}