#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m, d;
int c[1001];
int total[1002];
int ans[1001];
void solve() {
    scanf("%d %d %d", &n, &m, &d);
    for (int i = 1; i <= m; i++) scanf("%d", &c[i]);
    total[m + 1] = 0;
    for (int i = m; i >= 1; i--) total[i] = total[i + 1] + c[i];
    int pos = 0;
    int now = 1;
    while (true) {
        if (pos + d >= n + 1 - total[now]) {
            int start = n + 1 - total[now];
            for (int i = now; i <= m; i++)
                while (c[i]--) ans[start++] = i;
            break;
        }
        if (now > m) {
            puts("NO");
            return;
        }
        int start = pos + d;
        while (c[now]--) ans[start++] = now;
        pos = start - 1;
        now++;
    }
    puts("YES");
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}