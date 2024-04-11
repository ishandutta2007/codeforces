#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m;
int buffer[200000];
int* a[200000];
int cnt[200000];
int solve_col(int c) {
    for (int i = 0; i < n; i++) cnt[i] = 0;
    for (int i = 0; i < n; i++) {
        int val = a[i][c];
        if (val % m != c % m) continue;
        if (val >= n * m) continue;
        int row = val / m;
        int required = i - row;
        if (required < 0) required += n;
        cnt[required]++;
    }
    int ans = n;
    for (int i = 0; i < n; i++) {
        if (ans > n - cnt[i] + i) {
            ans = n - cnt[i] + i;
        }
    }
    return ans;
}

void solve() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        a[i] = &buffer[i * m];
        for (int j = 0; j < m; j++) {
            scanf("%d", &a[i][j]);
            a[i][j]--;
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++) ans += solve_col(i);
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}