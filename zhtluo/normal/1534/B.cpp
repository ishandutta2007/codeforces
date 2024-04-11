#include <bits/stdc++.h>

int T;
int N;
int len[410000];
long long ans;

int get_pos(int x) {
    if (x < 0 || x >= N) return 0;
    return len[x];
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) scanf("%d", &len[i]);
        ans = 0;
        for (int i = 0; i < N; ++i) {
            int x = std::max(get_pos(i - 1), get_pos(i + 1));
            if (len[i] > x) {
                ans += (len[i] - x);
                len[i] = x;
            }
        }
        for (int i = 0; i <= N; ++i) {
            ans += std::abs(get_pos(i) - get_pos(i - 1));
        }
        printf("%lld\n", ans);
    }
}