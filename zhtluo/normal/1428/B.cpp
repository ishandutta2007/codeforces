#include <bits/stdc++.h>

int N;
char S[310000];

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d %s", &N, S);
        int l = 0, r = 0;
        for (int i = 0; i < N; ++i) {
            l += (S[i] == '<');
            r += (S[i] == '>');
        }
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            ans += ((S[i] == '-') || (S[(i + 1) % N] == '-') || !l || !r);
        }
        printf("%d\n", ans);
    }
}