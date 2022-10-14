#include <bits/stdc++.h>

int N;
std::map<int, int> input;

int main() {
    int T; scanf("%d", &T); while (T--) {
        scanf("%d", &N);
        input.clear();
        for (int i = 0; i < N; ++i) {
            int u; scanf("%d", &u); ++input[u];
        }
        int ans = 0;
        for (auto e = input.begin(); e != input.end(); ++e) {
            int cur_ans = e -> second;
            auto f = e; ++f; if (f != input.end()) {
                int now = f -> first; ++cur_ans;
                while (true) {
                    f = input.lower_bound(now * 2 - e -> first);
                    if (f == input.end()) break;
                    now = f -> first; ++cur_ans;
                }
            }
            ans = std::max(ans, cur_ans);
        }
        printf("%d\n", N - ans);
    }
}