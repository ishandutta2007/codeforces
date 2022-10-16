#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[200001];
int buffer[200001];
void merge_sort(int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    int pos = 0;
    int x = l, y = m + 1;
    while ((x <= m) && (y <= r)) {
        if (a[x] < a[y]) buffer[pos++] = a[x++];
        else buffer[pos++] = a[y++];
    }
    while (x <= m) buffer[pos++] = a[x++];
    while (y <= r) buffer[pos++] = a[y++];
    for (int i = l; i <= r; i++) a[i] = buffer[i - l];
}
void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    merge_sort(1, n);
    int ans_l = 0, ans_r = -1;
    int current_l = -1, current_r = -1;
    for (int i = 1; i <= n; i++) {
        if (i + k - 1 > n) break;
        if (a[i] == a[i + k - 1]) {
            if (a[i] != current_r + 1) current_l = a[i];
            current_r = a[i];
            if (current_r - current_l > ans_r - ans_l) {
                ans_l = current_l;
                ans_r = current_r;
            }
        }
        while ((i < n) && (a[i + 1] == a[i])) i++;
    }
    if (ans_r == -1) {
        printf("-1\n");
    } else {
        printf("%d %d\n", ans_l, ans_r);
    }
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}