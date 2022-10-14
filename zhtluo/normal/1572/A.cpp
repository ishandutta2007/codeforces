#include <bits/stdc++.h>

int T, N;
std::vector<int> edge[210000];
int deg[210000];
std::set<int> S;

int main() {
    scanf("%d", &T); while (T--) {
        scanf("%d", &N);
        for (int i = 1; i <= N; ++i) {
            scanf("%d", &deg[i]);
            for (int j = 0, u; j < deg[i]; ++j) {
                scanf("%d", &u);
                edge[u].push_back(i);
            }
        }
        for (int i = 1; i <= N; ++i) {
            if (deg[i] == 0) S.insert(i);
        }
        int prev = -1, ans = 1;
        while (!S.empty()) {
            auto u = S.lower_bound(prev);
            if (u == S.end()) {
                ++ans; u = S.begin();
            }
            int n = *u; S.erase(n);
            for (auto e: edge[n]) {
                if (--deg[e] == 0) S.insert(e);
            }
            prev = n;
        }
        for (int i = 1; i <= N; ++i) {
            if (deg[i]) {
                printf("-1\n");
                goto end;
            }
        }
        printf("%d\n", ans);
        end:;
        std::fill(edge, edge + N + 1, std::vector<int>());
        std::fill(deg, deg + N + 1, 0);
        S.clear();
    }
}