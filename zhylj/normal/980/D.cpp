#include <bits/stdc++.h>

const int kN = 5e3 + 5;

int a[kN], ans[kN], d[kN]; bool vis[kN];

int Abs(int x) { return x > 0 ? x : -x; }

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) {
        scanf("%d", a + i);
        for(int j = 2; j * j <= Abs(a[i]); ++j)
            while(a[i] % (j * j) == 0) a[i] /= j * j;
        d[i] = a[i];
    }
    std::sort(d + 1, d + n + 1);
    int len = std::unique(d + 1, d + n + 1) - d - 1;
    for(int i = 1; i <= n; ++i)
        if(a[i]) a[i] = std::lower_bound(d + 1, d + len + 1, a[i]) - d;
    for(int i = 1; i <= n; ++i) {
        memset(vis, false, sizeof(vis));
        int cnt = 0;
        for(int j = i; j <= n; ++j) {
            if(!a[j]) { ++ans[std::max(cnt, 1)]; continue; }
            if(!vis[a[j]]) { vis[a[j]] = true; ++cnt; }
            ++ans[cnt];
        }
    }
    for(int i = 1; i <= n; ++i) printf("%d ", ans[i]);
    return 0;
}