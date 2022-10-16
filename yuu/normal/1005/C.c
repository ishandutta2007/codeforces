#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int a[120000], buffer[120000];

void merge_sort(int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    int x = l, y = m + 1, pos = 0;
    while ((x <= m) && (y <= r)) {
        if (a[x] < a[y]) buffer[pos++] = a[x++];
        else buffer[pos++] = a[y++];
    }
    while (x <= m) buffer[pos++] = a[x++];
    while (y <= r) buffer[pos++] = a[y++];
    for (int i = l; i <= r; i++) a[i] = buffer[i - l];
}

int search(int value) {
    int low = 0, high = n - 1;
    int mid, res = 0;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] >= value) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (a[res] != value) return n;
    return res;
}

void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    merge_sort(0, n - 1);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool good = 0;
        for (int j = 0; j <= 30; j++) {
            int other = (1 << j) - a[i];
            int idx = search(other);
            if (idx < n) {
                if (idx == i) {
                    idx++;
                    if ((idx < n) && (a[idx] != other)) idx = n;
                }
            }
            if (idx < n) {
                good = 1;
                break;
            }
        }
        if (!good) ans++;
    }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}