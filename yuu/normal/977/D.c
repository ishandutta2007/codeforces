#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
uint64_t a[101];
bool done[101];
int f[101];
int trace[101];
int F(int u) {
    if (done[u]) return f[u];
    done[u] = 1;
    f[u] = 1;
    for (int v = 1; v <= n; v++) {
        if ((a[v] == a[u] * 2) || (a[v] * 3 == a[u])) {
            if (f[u] < F(v) + 1) {
                f[u] = F(v) + 1;
                trace[u] = v;
            }
        }
    }
    return f[u];
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%llu", &a[i]);
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (F(i) == n) {
            int u = i;
            while (u) {
                printf("%llu ", a[u]);
                u = trace[u];
            }
            return;
        }
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}