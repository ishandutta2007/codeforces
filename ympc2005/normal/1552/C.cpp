#include <bits/stdc++.h>
using namespace std;

const int N = 205;

int T, n, m, p[N], id[N], cnt, t[N];

int ask_(int x, int res = 0) {
    for (; x; x -= x&-x)
        res += t[x];
    
    return res;
}

void add_(int x, int k) {
    for (; x <= n; x += x&-x)
        t[x] += k;
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &n, &m);

        memset(p, 0, sizeof(p));
        memset(t, 0, sizeof(t));
        
        for (int u, v, i = 1; i <= m; i++) {
            scanf("%d%d", &u, &v);
            p[u] = v, p[v] = u;
        }

        cnt = 0, n <<= 1;

        for (int i = 1; i <= n; i++)
            if (!p[i]) id[++cnt] = i;
        
        for (int i = 1; i <= cnt/2; i++)
            p[id[i]] = id[i + cnt/2], p[id[i + cnt/2]] = id[i];
        
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (i < p[i]) 
                add_(i, 1);
            else 
                ans += ask_(n) - ask_(p[i]), add_(p[i], -1);
        }
        
        printf("%d\n", ans);
    }
}