#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[10];
int b[10];

void make(int val, int* buff) {
    for (int i = 0; i < 10; i++) {
        buff[i] = val % 10;
        val /= 10;
    }
}
int64_t weight[10];
int64_t ans = 0;
void solve_for(int pos) {
    if (pos < 0) return;
    if (a[pos] == b[pos]) {
        solve_for(pos - 1);
    } else {
        for (int i = 0; i < pos; i++) {
            if (a[i]) {
                ans += weight[i] * (10 - a[i]);
                a[i] = 0;
                ans++;
                a[i + 1]++;
                for (int j = i + 1; a[j] >= 10; j++) {
                    ans++;
                    a[j] -= 10;
                    a[j + 1]++;
                }
            }
        }
        ans += weight[pos] * (b[pos] - a[pos]);
        solve_for(pos - 1);
    }
}

void solve() {
    int l, r;
    scanf("%d %d\n", &l, &r);
    make(l, a);
    make(r, b);
    ans = 0;
    weight[0] = 1;
    for (int i = 1; i <= 9; i++) weight[i] = weight[i - 1] * 10 + 1;
    ans = 0;
    solve_for(9);
    printf("%lld\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}