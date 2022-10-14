#include <bits/stdc++.h>

int T, N, K;
char c[400000];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &N, &K);
        scanf(" %s", c);
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < K; ++i)
            for (int j = i; j < N; j += K) {
                if ((c[i] == '0' && c[j] == '1') || (c[i] == '1' && c[j] == '0')) {
                    puts("NO");
                    goto endc;
                }
                if (c[i] == '?') c[i] = c[j];
                if (c[j] == '?') c[j] = c[i];
            }
        for (int i = 0; i < K; ++i) {
            cnt0 += (c[i] == '0');
            cnt1 += (c[i] == '1');
        }
        if (cnt0 > K / 2 || cnt1 > K / 2) {
            puts("NO");
            goto endc;
        }
        puts("YES");
        endc:;
    }
}