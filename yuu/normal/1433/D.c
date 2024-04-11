#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int a[5001];
int r[5001];
int root(int u) {
    if (r[u] < 0) return u;
    return r[u] = root(r[u]);
}
bool unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return false;
    if (r[u] > r[v]) {
        u ^= v;
        v ^= u;
        u ^= v;
    }
    r[u] += r[v];
    r[v] = u;
    return true;
}
struct {
    int x, y;
} e[5000];
int cnt = 0;
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) r[i] = -1;
    cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++) {
            if (a[i] == a[j]) continue;
            if (unite(i, j)) {
                cnt++;
                e[cnt].x = i;
                e[cnt].y = j;
                if (cnt == n - 1) break;
            }
        }
    if (cnt != n - 1) {
        printf("NO\n");
        return;
    }
    printf("YES\n");
    for (int i = 1; i < n; i++) printf("%d %d\n", e[i].x, e[i].y);
}
int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}