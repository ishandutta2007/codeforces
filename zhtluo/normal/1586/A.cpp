#include <bits/stdc++.h>

int T, N;

int main() {
    scanf("%d", &T); while (T--) {
        int sum = 0, odd = -1;
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i) {
            int u; scanf("%d", &u);
            sum += u; if (u % 2) odd = i;
        }
        int is_comp = 0;
        for (int i = 2; i * i <= sum; ++i)
            if (sum % i == 0) is_comp = 1;
        if (is_comp) {
            printf("%d\n", N);
            for (int i = 1; i <= N; ++i) printf("%d%c", i, " \n"[i == N]);
        } else {
            printf("%d\n", N - 1);
            for (int i = 1; i <= N; ++i) 
                if (i != odd)
                    printf("%d ", i);
            puts("");
        }
    }
}