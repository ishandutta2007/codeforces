#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, k;
int a[101];
int pos[101];
void solve() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        pos[a[i]] = i;
    }
    int cnt = 0;
    for (int i = 1; i <= 100; i++) {
        cnt += (pos[i] > 0);
    }
    if (cnt < k) {
        puts("NO");
        return;
    }
    puts("YES");
    for (int i = 1; i <= 100; i++) {
        if (pos[i]) {
            printf("%d ", pos[i]);
            k--;
            if (k == 0) break;
        }
    }
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}