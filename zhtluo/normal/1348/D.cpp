#include <bits/stdc++.h>

std::vector <long long> ans;
long long N;

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%lld", &N);
        long long m = 1, v = 1;
        ans.clear();
        while (m < N) {
            if (N - m - v <= v) {
                ans.push_back(N - m - v);
                break;
            }
            long long vv = std::min(v, (N - m - 2 * v) / 2);
            ans.push_back(vv);
            v += vv; m += v;
        }
        printf("%d\n", (int) ans.size());
        for (int i = 0; i < (int) ans.size(); ++i)
            printf("%lld%c", ans[i], " \n"[i + 1 == ans.size()]);
    }
}