#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, k;
int a[200001];
int64_t s[200001];
int buffer[200001];
void merge_sort(int l, int r) {
    if (l == r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    int x = l, y = m + 1;
    int pos = 0;
    while ((x <= m) && (y <= r)) {
        if (a[x] < a[y]) buffer[pos++] = a[x++];
        else buffer[pos++] = a[y++];
    }
    while ((x <= m)) buffer[pos++] = a[x++];
    while ((y <= r)) buffer[pos++] = a[y++];
    for (int i = l; i <= r; i++) a[i] = buffer[i - l];
}
void solve() {
    // Call ans the element that appear k time by the end, min be minimum number by then and vice versa for max
    // ans should be one of the original element
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    merge_sort(1, n);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    int64_t ans = 1e18;
    for (int i = 1; i <= n; i++) {
        int j = i;
        while ((j < n) && (a[j + 1] == a[j])) j++;
        if (j - i + 1 >= k) {
            printf("0\n");
            return;
        }

        int count_prev = i - 1;
        int count_next = n - j;
        int64_t sum_prev = s[i - 1];
        int64_t sum_next = s[n] - s[j];
        int64_t cost_prev = a[i] - 1;
        cost_prev *= count_prev;
        cost_prev -= sum_prev;

        int64_t cost_next = a[i] + 1;
        cost_next *= count_next;
        cost_next = sum_next - cost_next;
        if (count_prev + j - i + 1 >= k) {
            // use only prev
            int64_t cost = cost_prev + k - (j - i + 1);
            if (ans > cost) ans = cost;
        }
        if (count_next + j - i + 1 >= k) {
            // only use next
            int64_t cost = cost_next + k - (j - i + 1);
            if (ans > cost) ans = cost;
        }
        int64_t cost = cost_prev + cost_next + k - (j - i + 1);
        if (ans > cost) ans = cost;

        i = j;
    }
    printf("%lld\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}