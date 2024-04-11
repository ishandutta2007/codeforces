#include <bits/stdc++.h>

int T;
int N, A, B, DA, DB;
std::vector <int> edge[110000];
int dep[110000];

void dfs(int x, int f = -1) {
    for (int i : edge[x]) if (i != f) {
        dep[i] = dep[x] + 1;
        dfs(i, x);
    }
}

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d%d%d", &N, &A, &B, &DA, &DB);
        for (int i = 0; i < N - 1; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        dep[A] = 0; dfs(A);
        if (DB > 2 * DA && dep[B] > DA) {
            int dn = 1;
            for (int i = 2; i <= N; ++i) {
                if (dep[i] > dep[dn]) dn = i;
            }
            dep[dn] = 0; dfs(dn);
            int maxdep = 0;
            for (int i = 1; i <= N; ++i) maxdep = std::max(maxdep, dep[i]);
            if (maxdep > 2 * DA)
                puts("Bob");
            else
                puts("Alice");
        } else {
            puts("Alice");
        }
        for (int i = 1; i <= N; ++i) edge[i].clear();
    }
}