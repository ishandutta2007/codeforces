#include <bits/stdc++.h>

long long N, S;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%lld%lld", &N, &S);
        printf("%lld\n", S / ((N + 2) / 2));
    }
}