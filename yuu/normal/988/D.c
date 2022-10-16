#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int64_t a[200001], buffer[200001];

bool compare(int i, int j) { return a[i] < a[j]; }

void merge_sort(int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    int x = l, y = m + 1, pos = 0;
    while ((x <= m) && (y <= r)) {
        if (compare(x, y)) buffer[pos++] = a[x++];
        else buffer[pos++] = a[y++];
    }
    while (x <= m) buffer[pos++] = a[x++];
    while (y <= r) buffer[pos++] = a[y++];
    for (int i = l; i <= r; i++) a[i] = buffer[i - l];
}

bool find(int64_t value) {
    int low = 1, high = n, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == value) return true;
        else if (a[mid] > value) high = mid - 1;
        else low = mid + 1;
    }
    return false;
}
int ans_size = 0;
int64_t ans[4];
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    merge_sort(1, n);
    for (int i = 1; i <= n; i++) {
        for (int64_t power = 1; power <= 3e9; power *= 2) {
            bool found_minus = find(a[i] - power);
            bool found_plus = find(a[i] + power);
            int nans = 1;
            nans += found_minus;
            nans += found_plus;
            if (nans > ans_size) {
                ans_size = nans;
                ans[1] = a[i];
                ans[2] = found_minus ? (a[i] - power) : (a[i] + power);
                ans[3] = a[i] + power;
                if (ans_size == 3) break;
            }
        }
        if (ans_size == 3) break;
    }
    printf("%d\n", ans_size);
    for (int i = 1; i <= ans_size; i++) printf("%lld ", ans[i]);
    printf("\n");
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}