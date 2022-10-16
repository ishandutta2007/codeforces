#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m;
int w[200001];
char s[200002];
int64_t ans[256];
void solve() {
    scanf("%d %d", &n, &m);
    scanf("%s", &s[1]);
    for (int i = 1; i <= n; i++) w[i] = 0;
    for (int i = 1, p; i <= m; i++) {
        scanf("%d", &p);
        w[1]++;
        w[p + 1]--;
    }
    w[1]++;
    for (int i = 1; i <= n; i++) w[i] += w[i - 1];
    for (int i = 'a'; i <= 'z'; i++) ans[i] = 0;
    for (int i = 1; i <= n; i++) ans[s[i]] += w[i];
    for (int i = 'a'; i <= 'z'; i++) {
        printf("%lld ", ans[i]);
    }
    puts("");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}