#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int n;
int ans[200001];
struct {
    int h, w, id;
} f[400001], buffer[400001];
void merge_sort(int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    int x = l, y = m + 1;
    int t = 0;
    while ((x <= m) && (y <= r)) {
        if (f[x].h < f[y].h) buffer[t++] = f[x++];
        else buffer[t++] = f[y++];
    }
    while (x <= m) buffer[t++] = f[x++];
    while (y <= r) buffer[t++] = f[y++];
    for (int i = l; i <= r; i++) f[i] = buffer[i - l];
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d %d", &f[i * 2].h, &f[i * 2].w);
    for (int i = 1; i <= n * 2; i += 2) {
        f[i].h = f[i + 1].w;
        f[i].w = f[i + 1].h;
    }
    for (int i = 1; i <= n * 2; i++) f[i].id = (i + 1) / 2;
    merge_sort(1, n * 2);
    for (int i = 1; i <= n; i++) ans[i] = -1;
    f[0].w = 1e9 + 1;
    for (int i = 1, j = 1, min_w = 0; i <= n * 2; i++) {
        while (f[j].h < f[i].h) {
            if (f[j].w < f[min_w].w) min_w = j;
            j++;
        }
        if (f[min_w].w < f[i].w) ans[f[i].id] = f[min_w].id;
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    printf("\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}