#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int r;
struct project_t {
    int a, b;
    bool done;
} p[101], q[101], buffer[101];

void merge_sort(int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    int x = l, y = m + 1, pos = 0;
    while ((x <= m) && (y <= r)) {
        if (q[x].a + q[x].b > q[y].a + q[y].b) buffer[pos++] = q[x++];
        else buffer[pos++] = q[y++];
    }
    while (x <= m) buffer[pos++] = q[x++];
    while (y <= r) buffer[pos++] = q[y++];
    for (int i = l; i <= r; i++) q[i] = buffer[i - l];
}
int f[101][101];
void solve() {
    scanf("%d %d", &n, &r);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &p[i].a, &p[i].b);
        p[i].done = 0;
    }
    int ans = 0;
    bool good = true;
    while (good) {
        good = false;
        for (int i = 1; i <= n; i++) {
            if ((p[i].a <= r) && (p[i].b >= 0) && (!p[i].done)) {
                p[i].done = true;
                ans++;
                r += p[i].b;
                good = true;
            }
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if ((!p[i].done) && (p[i].b < 0)) {
            q[++cnt] = p[i];
        }
    }
    merge_sort(1, cnt);
    // for (int i = 1; i <= cnt; i++) printf("%d %d\n", q[i].a, q[i].b);
    for (int i = 0; i <= cnt; i++)
        for (int j = 0; j <= cnt; j++) f[i][j] = -1e9;
    // printf("%d %d\n", r, ans);
    f[0][0] = r;
    for (int i = 0; i < cnt; i++) {
        for (int j = 0; j <= cnt; j++)
            if (f[i][j] >= 0) {
                if (f[i + 1][j] < f[i][j]) f[i + 1][j] = f[i][j];
                if ((j < cnt) && (f[i][j] >= q[i + 1].a) && (f[i][j] + q[i + 1].b > f[i + 1][j + 1])) {
                    f[i + 1][j + 1] = f[i][j] + q[i + 1].b;
                }
            }
    }
    for (int i = cnt; i >= 0; i--)
        if (f[cnt][i] >= 0) {
            ans += i;
            break;
        }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}