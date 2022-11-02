#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

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

int n, ans, u[N], v[N], m1, m2, s[2][N], top[2];

void add_(int x, int y) {
    ++ans;
    u[ans] = x, v[ans] = y;
    T[0].merge_(x, y), T[1].merge_(x, y);
}

int main() {
    scanf("%d%d%d", &n, &m1, &m2);

    T[0].init_(n);

    for (int i = 1, u, v; i <= m1; i++)
        scanf("%d%d", &u, &v), T[0].merge_(u, v);
    
    T[1].init_(n);

    for (int i = 1, u, v; i <= m2; i++)
        scanf("%d%d", &u, &v), T[1].merge_(u, v);

    for (int i = 1; i <= n; i++)
        if (T[0].chk_(1, i) && T[1].chk_(1, i))
            add_(1, i);
    
    for (int i = 1; i <= n; i++)
        if (T[0].chk_(1, i))
            s[0][++top[0]] = i;
        else if (T[1].chk_(1, i))
            s[1][++top[1]] = i;
    
    while (1) {
        while (top[0] && !T[0].chk_(1, s[0][top[0]]))
            top[0]--;
        
        while (top[1] && !T[1].chk_(1, s[1][top[1]]))
            top[1]--;
        
        if (!top[0] || !top[1]) break;

        add_(s[0][top[0]--], s[1][top[1]--]);
    }

    printf("%d\n", ans);

    for (int i = 1; i <= ans; i++)
        printf("%d %d\n", u[i], v[i]);
}