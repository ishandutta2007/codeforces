#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int a[200001];
int ans, x, y;
void recursive_solve(int l, int r) {
    if (l == r) {
        if (a[l] == 2) {
            if (ans < 1) {
                ans = 1;
                x = l - 1;
                y = n - r;
            }
        }
        return;
    }
    int m = (l + r) / 2;
    recursive_solve(l, m);
    recursive_solve(m + 1, r);
    if (a[m] == 0) return;
    int pos_r = 0, pos_r_trace = n - m;
    int neg_r = -1e9, neg_r_trace = 0;
    int current = 0, sign = 1;
    for (int i = m + 1; i <= r; i++) {
        if (a[i] == 0) break;
        if (a[i] < 0) sign = -sign;
        if (a[i] == 2 || a[i] == -2) current++;
        if (sign < 0) {
            neg_r = current;
            neg_r_trace = n - i;
        } else {
            pos_r = current;
            pos_r_trace = n - i;
        }
    }
    int pos_l = -1e9, pos_l_trace = 0;
    int neg_l = -1e9, neg_l_trace = 0;
    current = 0;
    sign = 1;
    for (int i = m; i >= l; i--) {
        if (a[i] == 0) break;
        if (a[i] < 0) sign = -sign;
        if (a[i] == 2 || a[i] == -2) current++;
        if (sign < 0) {
            neg_l = current;
            neg_l_trace = i - 1;
        } else {
            pos_l = current;
            pos_l_trace = i - 1;
        }
    }
    if (pos_l + pos_r > ans) {
        ans = pos_l + pos_r;
        x = pos_l_trace;
        y = pos_r_trace;
    }
    if (neg_r + neg_l > ans) {
        ans = neg_l + neg_r;
        x = neg_l_trace;
        y = neg_r_trace;
    }
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    ans = 0;
    x = 0;
    y = n;
    recursive_solve(1, n);
    printf("%d %d\n", x, y);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}