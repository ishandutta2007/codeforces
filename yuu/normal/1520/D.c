#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[200001];
int val[200001];
int buffer[200001];
void merge_sort(int l, int r) {
    if (l == r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    int pos = 0;
    int x = l, y = m + 1;
    while ((x <= m) && (y <= r)) {
        if (a[x] < a[y]) {
            buffer[pos++] = a[x++];
        } else {
            buffer[pos++] = a[y++];
        }
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
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i] -= i;
    }
    merge_sort(1, n);
    int64_t ans = 0;
    for (int i = 1; i <= n; i++) {
        int j = i;
        while ((j + 1 <= n) && (a[j + 1] == a[j])) j++;
        int64_t count = j - i + 1;
        ans += count * (count - 1);
        i = j;
    }
    ans /= 2;
    printf("%lld\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}