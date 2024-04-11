#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// #define IS_E1

int n, k;
int x[200001];
int deg[200001];
int head[200001];
int tail[200001];
int next[400001];
struct {
    int u, v;
} e[200001];
bool done[200001];
int first[200001];
int last[200001];
int leaves_cnt;
void dfs(int u) {
    done[u] = 1;
    if ((u != 1) && (head[u] == tail[u])) {
        first[u] = last[u] = ++leaves_cnt;
        return;
    }
    first[u] = leaves_cnt + 1;
    for (int i = head[u], v; i <= tail[u]; i++) {
        v = next[i];
        // fprintf(stderr, "Edge: %d %d\n", u, v);
        if (!done[v]) dfs(v);
    }
    last[u] = leaves_cnt;
    // fprintf(stderr, "VERTEX: %d %d %d\n", u, first[u], last[u]);
}

int stack[200001];
int stack_size;
struct {
    int l, r;
} range[200001];

void get_range(int u) {
    done[u] = 1;
    stack[++stack_size] = u;
    range[u].l = first[stack[stack_size / 2 + 1]];
    range[u].r = last[stack[stack_size / 2 + 1]];
    // fprintf(stderr, "RANGE: %d %d %d\n", u, range[u].l, range[u].r);
    for (int i = head[u], v; i <= tail[u]; i++) {
        v = next[i];
        if (!done[v]) get_range(v);
    }
    stack_size--;
}

int f[200001];

struct Friend {
    int l, r;
} fr[200001];

int sort_by_r(const void* a, const void* b) { return ((struct Friend*)a)->r - ((struct Friend*)b)->r; }

int ft[200001];
int get(int u) {
    if (u == 0) return 0;
    int res = ft[u];
    for (; u <= leaves_cnt; u += (u & -u)) {
        if (res > ft[u]) res = ft[u];
    }
    return res;
}

void update(int u, int x) {
    for (; u > 0; u -= u & -u)
        if (ft[u] > x) ft[u] = x;
}

void solve() {
    scanf("%d %d\n", &n, &k);
    for (int i = 1; i <= k; i++) scanf("%d", &x[i]);
    for (int i = 1; i <= n; i++) deg[i] = 0;
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &e[i].u, &e[i].v);
        deg[e[i].u]++;
        deg[e[i].v]++;
    }
    for (int i = 1; i <= n; i++) {
        head[i] = head[i - 1] + deg[i - 1];
        tail[i] = head[i] - 1;
        // fprintf(stderr, "%d %d\n", head[i], tail[i]);
    }
    for (int i = 1; i < n; i++) {
        next[++tail[e[i].u]] = e[i].v;
        next[++tail[e[i].v]] = e[i].u;
    }
    leaves_cnt = 0;
    for (int i = 1; i <= n; i++) done[i] = 0;
    dfs(1);
    for (int i = 1; i <= n; i++) done[i] = 0;
    get_range(1);
    for (int i = 1; i <= leaves_cnt; i++) f[i] = 0;
    for (int i = 1; i <= k; i++) {
        f[range[x[i]].l]++;
        f[range[x[i]].r + 1]--;
    }
    for (int i = 1; i <= leaves_cnt; i++) {
        f[i] += f[i - 1];
        if (f[i] == 0) {
#ifdef IS_E1
            printf("YES\n");
#else
            printf("-1\n");
#endif
            return;
        }
    }
#ifdef IS_E1
    printf("NO\n");
    return;
#endif
    for (int i = 1; i <= k; i++) {
        fr[i].l = range[x[i]].l;
        fr[i].r = range[x[i]].r;
    }
    qsort(&fr[1], k, sizeof(struct Friend), sort_by_r);
    for (int i = 1; i <= leaves_cnt; i++) ft[i] = 1e9;
    for (int i = 1; i <= k; i++) {
        int res = get(fr[i].l - 1);
        update(fr[i].r, res + 1);
    }
    printf("%d\n", get(leaves_cnt));
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}