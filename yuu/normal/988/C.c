#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct item_t {
    int64_t sum;
    int i, x;
} s[200001], buffer[200001];

bool compare(int i, int j) { return s[i].sum < s[j].sum; }

void merge_sort(int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    int x = l, y = m + 1, pos = 0;
    while ((x <= m) && (y <= r)) {
        if (compare(x, y)) buffer[pos++] = s[x++];
        else buffer[pos++] = s[y++];
    }
    while (x <= m) buffer[pos++] = s[x++];
    while (y <= r) buffer[pos++] = s[y++];
    for (int i = l; i <= r; i++) s[i] = buffer[i - l];
}

int a[200001];

void solve() {
    int k;
    scanf("%d", &k);
    int m = 0;
    for (int i = 1, n; i <= k; i++) {
        scanf("%d", &n);
        for (int j = 1; j <= n; j++) scanf("%d", &a[j]);
        int64_t sum = 0;
        for (int j = 1; j <= n; j++) sum += a[j];
        for (int j = 1; j <= n; j++) {
            m++;
            s[m].sum = sum - a[j];
            s[m].i = i;
            s[m].x = j;
        }
    }
    merge_sort(1, m);
    for (int i = 1; i < m; i++)
        if ((s[i].sum == s[i + 1].sum) && (s[i].i != s[i + 1].i)) {
            printf("YES\n%d %d\n%d %d\n", s[i].i, s[i].x, s[i + 1].i, s[i + 1].x);
            return;
        }
    puts("NO");
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}