#include <bits/stdc++.h>

int T, N;
std::vector<int> edge[210000];
int is_bud[210000], is_leaf[210000], free_bud;
int leaf = 0;

void dfs(int n, int f = -1) {
    int leaf_count = 0, bud_count = 0;
    for (auto &i: edge[n]) {
        if (i == f) continue;
        dfs(i, n);
        if (i != 1 && is_leaf[i]) ++leaf_count;
        if (i != 1 && is_bud[i]) ++bud_count;
    }
    if (n != 1 && leaf_count + bud_count == edge[n].size() - 1) {
        if (leaf_count >= 1) is_bud[n] = 1;
        else is_leaf[n] = 1;
    }
    if (n == 1) free_bud += std::min(std::max(0, (int) edge[n].size() - 1), bud_count);
    else free_bud += std::min(std::max(0, (int) edge[n].size() - 2), bud_count);
    if (n != 1 && edge[n].size() == 1) ++leaf;
}

int main() {
    scanf("%d", &T); while (T--) {
        scanf("%d", &N);
        for (int i = 0; i < N - 1; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        dfs(1);
        printf("%d\n", leaf - free_bud);
        std::fill(edge, edge + N + 1, std::vector<int>());
        std::fill(is_bud, is_bud + N + 1, 0);
        std::fill(is_leaf, is_leaf + N + 1, 0);
        free_bud = leaf = 0;
    }
}