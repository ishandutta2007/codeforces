#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

vector <int> e[N];

int T, n, sz[N], cnt1, cnt2;

void dfs_(int u, int fa) {
    sz[u] = 1;

    for (int v : e[u])
        if (v != fa) {
            dfs_(v, u);

            if (sz[v] > 1) continue;
        
            sz[u]++;
        }
    
    cnt1 += sz[u] == 1;
    cnt2 += sz[u] > 1;
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        for (int i = 1; i <= n; i++)
            e[i].clear();
        
        for (int u, v, i = 1; i < n; i++) {
            scanf("%d%d", &u, &v);
            e[u].push_back(v), e[v].push_back(u);
        }

        cnt1 = cnt2 = 0;

        dfs_(1, 0);

        printf("%d\n", cnt1 - cnt2 + (sz[1] > 1));
    }
}