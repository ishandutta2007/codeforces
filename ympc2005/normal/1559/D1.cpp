#include <bits/stdc++.h>
using namespace std;

const int N = 1005;

struct Dsu {
    int fa[N];

    int find_(int x) {
        return fa[x] == x ? x : fa[x] = find_(fa[x]);
    }

    int chk_(int u, int v) {
        return find_(u) != find_(v);
    }

    void merge_(int u, int v) {
        fa[find_(u)] = find_(v);
    }
    
    void init_(int n) {
        for (int i = 1; i <= n; i++)
            fa[i] = i;
    }
} T[2];

int n, ans, u[N], v[N], m1, m2;

int main() {
    scanf("%d%d%d", &n, &m1, &m2);

    T[0].init_(n);

    for (int i = 1, u, v; i <= m1; i++)
        scanf("%d%d", &u, &v), T[0].merge_(u, v);
    
    T[1].init_(n);

    for (int i = 1, u, v; i <= m2; i++)
        scanf("%d%d", &u, &v), T[1].merge_(u, v);

    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            if (T[0].chk_(i, j) && T[1].chk_(i, j))
                ++ans, u[ans] = i, v[ans] = j, T[0].merge_(i, j), T[1].merge_(i, j);
    
    printf("%d\n", ans);

    for (int i = 1; i <= ans; i++)
        printf("%d %d\n", u[i], v[i]);
}