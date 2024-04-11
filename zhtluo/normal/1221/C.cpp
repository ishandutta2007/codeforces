#include <bits/stdc++.h>

int main() {
    int Q;
    scanf("%d", &Q);
    while (Q--) {
        int C, M, X;
        scanf("%d%d%d", &C, &M, &X);
        int pos = std::min(C, M);
        printf("%d\n", std::min(pos, (C + M + X) / 3));
    }
}