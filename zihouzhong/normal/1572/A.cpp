#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n, f[maxn], ind[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            G[i].clear(), ind[i] = f[i] = 0;
        }
        for (int i = 1, k; i <= n; i++) {
            scanf("%d", &k);
            for (int j = 1, x; j <= k; j++) {
                scanf("%d", &x);
                G[x].push_back(i), ind[i]++;
            }
        }
        queue<int> Q;
        for (int i = 1; i <= n; i++) {
            if (!ind[i]) Q.push(i), f[i] = 1;
        }
        while (!Q.empty()) {
            int v = Q.front(); Q.pop();
            for (int u : G[v]) {
                if (u > v) f[u] = max(f[u], f[v]);
                else f[u] = max(f[u], f[v] + 1);
                if (!--ind[u]) Q.push(u);
            }
        }
        int ans = *max_element(f + 1, f + n + 1);
        for (int i = 1; i <= n; i++) {
            if (ind[i]) ans = -1;
        }
        printf("%d\n", ans);
    }
    return 0;
}