#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int a[1001];
int buffer[1001];

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

const int base = 1e9 + 7;
int c[1001][1001];

void prepare() {
    for (int i = 1; i <= 1000; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            c[i][j] %= base;
        }
    }
}
int C(int n, int k) { return c[n][k]; }

void solve() {
    int n ,k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    merge_sort(a, 1, n);
    int i = k, j = k;
    while ((i > 1) && (a[i - 1] == a[i])) i--;
    while ((j < n) && (a[j + 1] == a[j])) j++;
    int total = j - i + 1;
    int chosen = k - i + 1;
    printf("%d\n", C(total, chosen));
}

int main() {
    prepare();
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}