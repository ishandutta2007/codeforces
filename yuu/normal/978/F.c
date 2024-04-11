#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct programmer_t {
    int r;
    int id;
} p[200001], buffer[200001];
int r[200001];
void merge_sort(int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    int x = l, y = m + 1, pos = 0;
    while ((x <= m) && (y <= r)) {
        if (p[x].r < p[y].r) buffer[pos++] = p[x++];
        else buffer[pos++] = p[y++];
    }
    while (x <= m) buffer[pos++] = p[x++];
    while (y <= r) buffer[pos++] = p[y++];
    for (int i = l; i <= r; i++) p[i] = buffer[i - l];
}

int n, k;
int ans[200001];
void solve() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &r[i]);
        p[i].r = r[i];
        p[i].id = i;
    }
    merge_sort(1, n);
    for (int i = 1, j = 0; i <= n; i++) {
        while (p[j + 1].r < p[i].r) j++;
        ans[p[i].id] = j;
    }
    for (int i = 1, x, y; i <= k; i++) {
        scanf("%d %d", &x, &y);
        if (r[x] < r[y]) {
            x ^= y;
            y ^= x;
            x ^= y;
        }
        if (r[x] > r[y]) ans[x]--;
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}