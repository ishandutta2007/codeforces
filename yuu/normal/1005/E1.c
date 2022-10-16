#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m;
int a[200001];
int b[200001];
int64_t ans = 0;

struct pos_t {
    int i;
    int value;
} p[200001], buffer[200001];

bool compare(int version, int x, int y) {
    if (p[x].value != p[y].value) return p[x].value < p[y].value;
    if (version == 0) {
        // less
        return p[x].i < p[y].i;
    } else {
        return p[x].i > p[y].i;
    }
}

void merge_sort(int version, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort(version, l, m);
    merge_sort(version, m + 1, r);
    int x = l, y = m + 1, pos = 0;
    while ((x <= m) && (y <= r)) {
        if (compare(version, x, y)) buffer[pos++] = p[x++];
        else buffer[pos++] = p[y++];
    }
    while (x <= m) buffer[pos++] = p[x++];
    while (y <= r) buffer[pos++] = p[y++];
    for (int i = l; i <= r; i++) p[i] = buffer[i - l];
}

int ft[200002];
void update(int u) {
    u++;
    for (; u <= n + 1; u += u & -u) ft[u]++;
}
int get(int u) {
    u++;
    int res = 0;
    for (; u > 0; u -= u & -u) res += ft[u];
    return res;
}

int64_t get_less() {
    for (int i = 1; i <= n; i++) b[i] = b[i - 1] + (a[i] < m);
    // (b[i] - b[j]) * 2 >=  i - j (for j < i)
    // b[i] * 2 - i >= b[j] * 2 - j (for j < i)
    for (int i = 0; i <= n; i++) {
        p[i].i = i;
        p[i].value = b[i] * 2 - i;
    }
    merge_sort(0, 0, n);
    int64_t res = 0;
    for (int i = 1; i <= n + 1; i++) ft[i] = 0;
    for (int i = 0; i <= n; i++) {
        res += get(p[i].i);
        update(p[i].i);
    }
    return res;
}

int64_t get_greater() {
    for (int i = 1; i <= n; i++) b[i] = b[i - 1] + (a[i] > m);
    // (b[i] - b[j]) * 2 > i - j (for j < i)
    // b[i] * 2 - i > b[j] * 2 - j (for j < i)
    for (int i = 0; i <= n; i++) {
        p[i].i = i;
        p[i].value = b[i] * 2 - i;
    }
    merge_sort(1, 0, n);
    int64_t res = 0;
    for (int i = 1; i <= n + 1; i++) ft[i] = 0;
    for (int i = 0; i <= n; i++) {
        res += get(p[i].i);
        update(p[i].i);
    }
    return res;
}

void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    ans = n;
    ans *= (n + 1);
    ans /= 2;
    ans -= get_less();
    ans -= get_greater();
    printf("%lld\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}