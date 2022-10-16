#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m;
int a[101];
bool p[101];
void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) p[i] = 0;
    for (int i = 1, x; i <= m; i++) {
        scanf("%d", &x);
        p[x] = 1;
    }
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        int j = i;
        while (p[j]) j++;

        int mi = 1e9;
        for (int k = i; k <= j; k++)
            if (a[k] < mi) mi = a[k];
        if (mi < mx) {
            puts("NO");
            return;
        }
        for (int k = i; k <= j; k++)
            if (a[k] > mx) mx = a[k];
        i = j;
    }
    puts("YES");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}