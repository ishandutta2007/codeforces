#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int n, m;
int a[200001];
int b[200001];
int weight[3][200001];
int* buffer = weight[0];
int count[3];

void merge_sort(int* array, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort(array, l, m);
    merge_sort(array, m + 1, r);
    int x = l, y = m + 1;
    int head = 0;
    while ((x <= m) && (y <= r)) {
        if (array[x] > array[y]) {
            buffer[head++] = array[x++];
        } else {
            buffer[head++] = array[y++];
        }
    }
    while (x <= m) {
        buffer[head++] = array[x++];
    }
    while (y <= r) {
        buffer[head++] = array[y++];
    }
    for (int i = l; i <= r; i++) {
        array[i] = buffer[i - l];
    }
}

void solve() {
    scanf("%d %d", &n, &m);
    count[1] = count[2] = 0;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    for (int i = 1; i <= n; i++) {
        weight[b[i]][++count[b[i]]] = a[i];
    }
    merge_sort(weight[1], 1, count[1]);
    merge_sort(weight[2], 1, count[2]);
    int64_t current = 0;
    int x = 0;
    for (int i = 1; i <= count[1]; i++) {
        current += weight[1][i];
    }
    x = count[1];
    int ans = 1e9;
    for (int y = 0; y <= count[2]; y++) {
        current += weight[2][y];
        while ((x) && (current - weight[1][x] >= m)) {
            current -= weight[1][x];
            x--;
        }
        if (current >= m) {
            if (ans > x + y * 2) {
                ans = x + y * 2;
            }
        }
    }
    if (ans == 1e9) ans = -1;
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}