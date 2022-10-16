#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Mine {
    int64_t x, y;
    int id;
};
struct Mine mine[200000];
int timer[200000];
int by_x_then_y(const void* a, const void* b) {
    int64_t res = 0;
    if (((struct Mine*)a)->x != ((struct Mine*)b)->x)
        res = ((struct Mine*)a)->x - ((struct Mine*)b)->x;
    else
        res = ((struct Mine*)a)->y - ((struct Mine*)b)->y;
    if (res > 0)
        return 1;
    else if (res < 0)
        return -1;
    else
        return 0;
}

int by_y_then_x(const void* a, const void* b) {
    int64_t res = 0;
    if (((struct Mine*)a)->y != ((struct Mine*)b)->y)
        res = ((struct Mine*)a)->y - ((struct Mine*)b)->y;
    else
        res = ((struct Mine*)a)->x - ((struct Mine*)b)->x;
    if (res > 0)
        return 1;
    else if (res < 0)
        return -1;
    else
        return 0;
}

int greater(const void* a, const void* b) { return (*(int*)b) - (*(int*)a); }

int r[200000];
bool done[200000];
int root(int u) {
    if (r[u] < 0) return u;
    return r[u] = root(r[u]);
}
void unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return;
    if (r[u] > r[v]) {
        u ^= v;
        v ^= u;
        u ^= v;
    }
    r[u] += r[v];
    r[v] = u;
    if (timer[u] > timer[v]) timer[u] = timer[v];
}

int n;
int64_t k;
int component[200000];
void solve() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%lld %lld %d", &mine[i].x, &mine[i].y, &timer[i]);
        mine[i].id = i;
    }
    for (int i = 0; i < n; i++) r[i] = -1;
    for (int i = 0; i < n; i++) done[i] = false;
    qsort(mine, n, sizeof(struct Mine), by_x_then_y);
    for (int i = 0; i + 1 < n; i++)
        if ((mine[i].x == mine[i + 1].x) && (mine[i + 1].y - mine[i].y <= k)) unite(mine[i].id, mine[i + 1].id);
    qsort(mine, n, sizeof(struct Mine), by_y_then_x);
    for (int i = 0; i + 1 < n; i++)
        if ((mine[i].y == mine[i + 1].y) && (mine[i + 1].x - mine[i].x <= k)) unite(mine[i].id, mine[i + 1].id);
    int cc = 0;
    for (int i = 0; i < n; i++) {
        int u = root(i);
        if (done[u]) continue;
        done[u] = true;
        component[cc++] = timer[u];
    }
    qsort(component, cc, sizeof(int), greater);
    int ans = cc - 1;
    for (int i = 0; i < cc; i++) {
        int res = component[i];
        if (res < i - 1) res = i - 1;
        if (ans > res) ans = res;
    }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d\n", &t);
    while (t--) solve();
}