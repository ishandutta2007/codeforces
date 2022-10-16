#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;
typedef struct Point {
    int x, w, id;
};
struct Point p[200000];

int sort_by_x(const void* A, const void* B) { return ((struct Point*)A)->x - ((struct Point*)B)->x; }

int sort_by_w(const void* A, const void* B) { return ((struct Point*)A)->w - ((struct Point*)B)->w; }

void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &p[i].x, &p[i].w);
        p[i].id = i + 1;
    }
    qsort(p, m, sizeof(struct Point), sort_by_w);
    qsort(p, n * 2, sizeof(struct Point), sort_by_x);
    int64_t ans = 0;
    for (int i = 0; i < n * 2; i++) ans += p[i].w;
    printf("%lld\n", ans);
    for (int i = 0, j = n * 2 - 1; i < j; i++, j--) printf("%d %d\n", p[i].id, p[j].id);
    printf("\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}