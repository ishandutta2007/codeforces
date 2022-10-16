#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
struct point_t {
    int x, y;
} p[1001], buffer[1001];

bool less(int i, int j) {
    if (p[i].x != p[j].x) return p[i].x < p[j].x;
    return p[i].y < p[j].y;
}

void merge_sort(int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    int x = l, y = m + 1, pos = 0;
    while ((x <= m) && (y <= r)) {
        if (less(x, y)) buffer[pos++] = p[x++];
        else buffer[pos++] = p[y++];
    }
    while (x <= m) buffer[pos++] = p[x++];
    while (y <= r) buffer[pos++] = p[y++];
    for (int i = l; i <= r; i++) p[i] = buffer[i - l];
}
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d %d", &p[i].x, &p[i].y);
    merge_sort(1, n);
    for (int i = 2; i <= n; i++)
        if (p[i].y < p[i - 1].y) {
            puts("NO");
            return;
        }
    puts("YES");
    int x = 0, y = 0;
    for (int i = 1; i <= n; i++) {
        while (x < p[i].x) {
            putchar('R');
            x++;
        }
        while (y < p[i].y) {
            putchar('U');
            y++;
        }
    }
    putchar('\n');
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}