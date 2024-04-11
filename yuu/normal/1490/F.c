#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int n;
int a[200001], buffer[200001];
int cnt[200001];
void merge_sort(int l, int r) {
    if (l == r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    int x = l, y = m + 1;
    int pos = 0;
    while ((x <= m) && (y <= r)) {
        if (a[x] <= a[y]) buffer[pos++] = a[x++];
        else buffer[pos++] = a[y++];
    }
    while (x <= m) {
        buffer[pos++] = a[x++];
    }
    while (y <= r) {
        buffer[pos++] = a[y++];
    }
    for (int i = l; i <= r; i++) a[i] = buffer[i - l];
}
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    merge_sort(1, n);
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    for (int i = 1; i <= n; i++) {
        int j = i;
        while ((j < n) && (a[j + 1] == a[j])) j++;
        cnt[j - i + 1]++;
        i = j;
    }
    int ans = n;
    int prefix_sum = 0;
    int suffix_sum = 0, suffix_weight = 0;
    for (int i = 1; i <= n; i++) {
        prefix_sum += cnt[i] * i;
    }
    for (int i = n; i >= 1; i--) {
        prefix_sum -= cnt[i] * i;
        if (ans > prefix_sum + suffix_sum - suffix_weight * i) {
            ans = prefix_sum + suffix_sum - suffix_weight * i;
        }
        suffix_sum += cnt[i] * i;
        suffix_weight += cnt[i];
    }
    printf("%d\n", ans);
}
int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}