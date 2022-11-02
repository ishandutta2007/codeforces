#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, m, d[N], ans, q;

void add_(int u, int v, int w) {
    if (u < v) swap(u, v);

    if (w == 1 && !d[v])    
        ans--;
    
    if (w == -1 && d[v] == 1)
        ans++;
    
    d[v] += w;
}

int main() {
    scanf("%d%d", &n, &m), ans = n;

    for (int i = 1, u, v; i <= m; i++) {
        scanf("%d%d", &u, &v);
        add_(u, v, 1);
    }

    scanf("%d", &q);

    for (int op, u, v, i = 1; i <= q; i++) {
        scanf("%d", &op);

        if (op == 3)
            printf("%d\n", ans);
        else {
            scanf("%d%d", &u, &v);
            add_(u, v, op == 1 ? 1 : -1);
        }
    }
}