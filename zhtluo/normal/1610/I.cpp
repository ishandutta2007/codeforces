#include <bits/stdc++.h>

int N;
std::vector<int> edge[310000];
int f[310000], sg[310000], covered[310000];
int ans[310000];

void dfs(int n) {
    for (auto &e: edge[n]) if (e != f[n]) {
        f[e] = n; dfs(e); sg[n] ^= (1 + sg[e]);
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N - 1; ++i) {
        int u, v; scanf("%d%d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    f[1] = -1; dfs(1); ans[1] = sg[1];
    for (int cur = 2; cur <= N; ++cur) {
        int mod = 0, q, prev, len;
        for (q = cur, prev = -1, len = 0; q != 1 && covered[q] == 0; prev = q, q = f[q], ++len) {
            mod ^= sg[q];
            // printf(":%d %d\n", q, mod);
            if (prev != -1) mod ^= (1 + sg[prev]);
            covered[q] = 1;
        }
        if (prev == -1) {
            ans[cur] = ans[cur - 1];
        } else {
            ans[cur] = ans[cur - 1] ^ (sg[prev] + 1) ^ mod ^ (len & 1);
        }
        // printf("%d %d %d %d\n", ans[cur - 1], sg[prev] + 1, mod, len & 1);
    }
    // for (int i = 1; i <= N; ++i) printf("%d ", ans[i]); puts("");
    for (int i = 1; i <= N; ++i) printf("%d", (ans[i] == 0 ? 2 : 1));
}