#include <bits/stdc++.h>

int T;

int main() {
    scanf("%d", &T);
    while (T--) {
        int N; scanf("%d", &N);
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            int u; scanf("%d", &u);
            sum += (u - 1);
        }
        puts((sum & 1) ? "errorgorn" : "maomao90");
    }
}