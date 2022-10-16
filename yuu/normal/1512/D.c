#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int b[200003];

bool test_sum(int idx) {
    int64_t total = b[idx];
    for (int i = 1; i <= n + 2; i++)
        if (i != idx) total -= b[i];
    for (int i = 1; i <= n + 2; i++)
        if (i != idx) {
            if (b[i] == -total) {
                for (int j = 1; j <= n + 2; j++)
                    if ((j != i) && (j != idx)) printf("%d ", b[j]);
                printf("\n");
                return true;
            }
        }
    return false;
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n + 2; i++) scanf("%d", &b[i]);
    int mx = 0, mx2 = 0;
    for (int i = 1; i <= n + 2; i++) {
        if (b[i] > b[mx]) {
            mx2 = mx;
            mx = i;
        } else if (b[i] > b[mx2]) {
            mx2 = i;
        }
    }
    if (test_sum(mx)) return;
    if (test_sum(mx2)) return;
    printf("-1\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}