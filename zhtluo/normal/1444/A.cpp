#include <bits/stdc++.h>

std::map<long long, int> fac;

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        long long P, Q;
        scanf("%lld%lld", &P, &Q);
        fac.clear();
        for (long long i = 2; i * i <= Q; ++i) {
            while (Q % i == 0) ++fac[i], Q /= i;
        }
        if (Q > 1) ++fac[Q];
        long long ans = 1;
        for (auto &pair: fac) {
            long long mul = 1;
            for (int i = 0; i < pair.second; ++i) mul *= pair.first;
            long long a = P;
            while (a % mul == 0) a /= pair.first;
            ans = std::max(ans, a);
        }
        printf("%lld\n", ans);
    }
    return 0;
}