#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, d;
int weight[5001];
int depth[5001];
int cnt[5001];
int ans[5001];
void solve() {
    scanf("%d %d", &n, &d);
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    cnt[0] = 1;
    int rem = n - 1;
    int64_t low = 0;
    for (int i = 1; i <= n; i++) {
        cnt[i] = rem;
        if (cnt[i] > cnt[i - 1] * 2) cnt[i] = cnt[i - 1] * 2;
        rem -= cnt[i];
        low += ((int64_t)cnt[i]) * i;
        if (low > d) {
            puts("NO");
            return;
        }
    }
    int p = n;
    for (int i = low + 1; i <= d; i++) {
        while (p && (cnt[p] <= 1)) p--;
        if (p == 0) {  // at high already
            puts("NO");
            return;
        }
        cnt[p + 1]++;
        cnt[p]--;
        p++;
    }
    for (int i = 1; i <= n; i++) {
        assert(cnt[i] <= cnt[i - 1] * 2);
        d -= cnt[i] * i;
    }
    assert(d == 0);
    for (int i = 1; i <= n; i++) weight[i] = depth[i] = 0;
    depth[1] = 0;
    for (int i = 2, d = 1, p = 1; i <= n; i++) {
        while (!cnt[d]) d++;
        cnt[d]--;
        depth[i] = d;
        while ((weight[p] == 2) || (depth[p] + 1 < depth[i])) p++;
        ans[i] = p;
        weight[p]++;
    }
    puts("YES");
    for (int i = 2; i <= n; i++) printf("%d ", ans[i]);
    puts("");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}