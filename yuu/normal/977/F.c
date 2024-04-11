#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m;
int a[200001];
int u[200001];
int buffer[200001];

int find_pos(int x) {
    int low = 1, high = m, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (u[mid] == x) return mid;
        else if (u[mid] > x) high = mid - 1;
        else low = mid + 1;
    }
    return 0;
}

int trace[200001];
int top[200001];
int f[200001];

void merge_sort(int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);
    int x = l, y = m + 1, pos = 0;
    while ((x <= m) && (y <= r)) {
        if (u[x] < u[y]) buffer[pos++] = u[x++];
        else buffer[pos++] = u[y++];
    }
    while (x <= m) buffer[pos++] = u[x++];
    while (y <= r) buffer[pos++] = u[y++];
    for (int i = l; i <= r; i++) u[i] = buffer[i - l];
}

void print_output(int u) {
    if (u == 0) return;
    print_output(trace[u]);
    printf("%d ", u);
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) u[i] = a[i];
    merge_sort(1, n);
    m = 0;
    int old = 0;
    for (int i = 1; i <= n; i++)
        if (u[i] != old) {
            old = u[i];
            u[++m] = old;
        }

    int ans = 0, best = 0;
    for (int i = 1; i <= n; i++) {
        int prev = top[find_pos(a[i] - 1)];
        int now = find_pos(a[i]);
        f[i] = f[prev] + 1;
        trace[i] = prev;
        top[find_pos(a[i])] = i;
        if (ans < f[i]) {
            ans = f[i];
            best = i;
        }
    }
    printf("%d\n", ans);
    print_output(best);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}