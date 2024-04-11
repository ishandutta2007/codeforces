#include <bits/stdc++.h>

int T, N;
char S[110000];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf(" %s", S); N = strlen(S);
        int ans = 0;
        for (int i = 1; i < N; ++i) {
            bool flag = false;
            for (int j = std::max(i - 2, 0); j < i; ++j)
                if (S[j] == S[i]) flag = true;
            if (flag) S[i] = ' ', ++ans;
        }
        printf("%d\n", ans);
    }
}