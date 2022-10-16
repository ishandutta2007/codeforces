#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m;
int64_t k;
int64_t a[22][22];
int length;
int front_length;
int back_length;
int front_count[21];
int back_count[21];
int64_t front_xor[21][200000], back_xor[21][200000];

void backtrack_front(int u, int x, int y, int64_t value) {
    if ((x > n) || (x < 1)) return;
    if ((y > m) || (y < 1)) return;
    if (u == front_length) {
        front_count[x]++;
        front_xor[x][front_count[x]] = value;
    } else {
        backtrack_front(u + 1, x + 1, y, value ^ a[x + 1][y]);
        backtrack_front(u + 1, x, y + 1, value ^ a[x][y + 1]);
    }
}

void backtrack_back(int u, int x, int y, int64_t value) {
    if ((x > n) || (x < 1)) return;
    if ((y > m) || (y < 1)) return;
    if (u == back_length) {
        back_count[x]++;
        back_xor[x][back_count[x]] = (value ^ a[x][y]);
    } else {
        backtrack_back(u + 1, x - 1, y, value ^ a[x - 1][y]);
        backtrack_back(u + 1, x, y - 1, value ^ a[x][y - 1]);
    }
}

int64_t buffer[(1 << 20) + 1];
void merge_sort(int64_t* a, int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort(a, l, m);
    merge_sort(a, m + 1, r);
    int x = l, y = m + 1, pos = 0;
    while ((x <= m) && (y <= r)) {
        if (a[x] < a[y]) buffer[pos++] = a[x++];
        else buffer[pos++] = a[y++];
    }
    while (x <= m) buffer[pos++] = a[x++];
    while (y <= r) buffer[pos++] = a[y++];
    for (int i = l; i <= r; i++) a[i] = buffer[i - l];
}

int64_t solve_row(int u) {
    int n = front_count[u];
    int m = back_count[u];
    int64_t* a = front_xor[u];
    int64_t* b = back_xor[u];
    merge_sort(a, 1, n);
    merge_sort(b, 1, m);
    int low = 1, high = 1;
    int64_t ans = 0;
    for (int i = 1; i <= n; i++) {
        while ((low <= m) && (b[low] < a[i])) low++;
        while ((high <= m) && (b[high] <= a[i])) high++;
        if (low > m) break;
        ans += high - low;
    }
    return ans;
}

void solve() {
    scanf("%d %d %lld", &n, &m, &k);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) scanf("%lld", &a[i][j]);
    length = n + m;
    front_length = length / 2;
    back_length = length - front_length;
    backtrack_front(1, 1, 1, a[1][1] ^ k);
    backtrack_back(1, n, m, a[n][m]);
    int64_t ans = 0;
    for (int i = 1; i <= n; i++) ans += solve_row(i);
    printf("%lld\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}