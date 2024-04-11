#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int a[200001];
int f[200001][18];
int __lg(int x) { return 31 - __builtin_clz(x); }
int get_min(int l, int r) {
    int lg = __lg(r - l + 1);
    int res = f[l][lg];
    if (res > f[r - (1 << lg) + 1][lg]) res = f[r - (1 << lg) + 1][lg];
    return res;
}
int get_last_greater(int l, int min) {
    // last r that min(l, r) > min
    int low = l, high = n, mid, res = l - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (get_min(l, mid) > min) {
            res = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return res;
}
int get_last_geq(int l, int min) {
    // last r that min(l, r) >= min
    int low = l, high = n, mid, res = l - 1;
    while (low <= high) {
        mid = (low + high) / 2;
        if (get_min(l, mid) >= min) {
            res = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return res;
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) f[i][0] = a[i];
    for (int i = 1, length = 2, half = 1; length <= n; length *= 2, half *= 2, i++) {
        for (int j = 1; j + length - 1 <= n; j++)
            f[j][i] = (f[j][i - 1] < f[j + half][i - 1]) ? f[j][i - 1] : f[j + half][i - 1];
    }
    int max = 0;
    int right_max = a[n];
    int right_max_low = n;
    int right_max_high = n;
    while ((right_max_low > 1) && (a[right_max_low - 1] <= right_max)) right_max_low--;
    for (int x = 1; x < n; x++) {
        if (a[x] > max) max = a[x];
        int min_range_first = get_last_greater(x + 1, max) + 1;
        int min_range_last = get_last_geq(x + 1, max);
        if (min_range_first > min_range_last) continue;
        while (right_max < max) {
            right_max_low--;
            if (a[right_max_low] > right_max) {
                right_max = a[right_max_low];
                right_max_high = right_max_low;
            }
            while ((right_max_low > 1) && (a[right_max_low - 1] <= right_max)) right_max_low--;
        }
        if (right_max > max) continue;
        if (right_max_low > min_range_last + 1) continue;
        if (right_max_high < min_range_first + 1) continue;
        printf("YES\n");
        if (right_max_low >= min_range_first + 1) printf("%d %d %d\n", x, right_max_low - 1 - x, n - right_max_low + 1);
        else printf("%d %d %d\n", x, min_range_first - x, n - min_range_first);
        return;
    }
    printf("NO\n");
}
int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}