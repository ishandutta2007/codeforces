#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int n, k;
struct {
    int a, t;
} c[300001];

int temp[300001];
int ans[300001];

void solve() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= k; i++) scanf("%d", &c[i].a);
    for (int i = 1; i <= k; i++) scanf("%d", &c[i].t);
    for (int i = 1; i <= n; i++) temp[i] = 2e9;
    for (int i = 1; i <= k; i++)
        if (temp[c[i].a] > c[i].t) temp[c[i].a] = c[i].t;

    int min_temp = 2e9;
    for (int i = 1; i <= n; i++) {
        if (min_temp > temp[i]) min_temp = temp[i];
        ans[i] = min_temp;
        min_temp++;
    }
    min_temp = 2e9;
    for (int i = n; i >= 1; i--) {
        if (min_temp > temp[i]) min_temp = temp[i];
        if (ans[i] > min_temp) ans[i] = min_temp;
        min_temp++;
    }
    for (int i=1; i<=n; i++) printf("%d ", ans[i]);
    printf("\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}