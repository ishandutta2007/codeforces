#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int n, T, d[N], da, db, a, b, mxd;

vector <int> e[N];

int dfs_(int u, int fa) {
    d[u] = d[fa] + 1;

    int mx = 0;

    for (int v : e[u]) {
        if (v == fa) {
            continue;
        }

        int x = dfs_(v, u);

        mxd = max(mxd, mx + x + 1);

        mx = max(mx, x + 1);
    }

    return mx;
}

bool solve_() {
    if (da*2 >= db) {
        return 1;
    }

    mxd = 0;
    dfs_(a, 0);

    if (d[b] - 1 <= da || mxd <= 2*da) {
        return 1;
    }

    return 0;
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d%d%d%d", &n, &a, &b, &da, &db);

        for (int i = 1; i <= n; i++) {
            e[i].clear();
        }

        for (int u, v, i = 1; i < n; i++) {
            scanf("%d%d", &u, &v);
            e[u].push_back(v);
            e[v].push_back(u);
        }

        printf("%s\n", solve_() ? "Alice" : "Bob");
    }
}