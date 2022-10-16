#include <stdint.h>
#include <stdio.h>

int n;
int64_t s;
int64_t a[200001];
int64_t f[20][200001];
int bit_floor[200001];
int64_t get_min(int l, int r) {
    int level = bit_floor[r - l + 1];
    if (f[level][l] > f[level][r - (1 << level) + 1])
        return f[level][r - (1 << level) + 1];
    else
        return f[level][l];
}
void solve() {
    scanf("%d %lld", &n, &s);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++) a[i] += a[i - 1];
    for (int i = 1; i <= n; i++) f[0][i] = a[i];
    for (int i = 1, length = 2, half = 1; length <= n; i++, length *= 2, half *= 2) {
        for (int pos = 1; pos + length - 1 <= n; pos++) {
            f[i][pos] = f[i - 1][pos];
            if (f[i - 1][pos + half] < f[i][pos]) f[i][pos] = f[i - 1][pos + half];
        }
    }
    int l = -1, r = -1e9;
    for (int i = 1; i <= n; i++) {
        int best = -1e9;
        int low = i, high = n, mid;
        while (low <= high) {
            mid = (low + high) / 2;
            int64_t min_val = get_min(i, mid);
            if (min_val - a[i - 1] < -s) {
                high = mid - 1;
            } else {
                best = mid;
                low = mid + 1;
            }
        }
        if (best - i > r - l) {
            l = i;
            r = best;
        }
    }
    if (r - l >= 0)
        printf("%d %d\n", l, r);
    else
        printf("-1\n");
}

int main() {
    for (int i = 1; i <= 200000; i++) {
        bit_floor[i] = bit_floor[i - 1];
        if ((1 << (bit_floor[i] + 1)) <= i) bit_floor[i]++;
    }
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}