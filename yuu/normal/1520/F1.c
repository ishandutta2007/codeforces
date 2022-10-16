#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
int ask(int pos) {
    printf("? 1 %d\n", pos);
    fflush(stdout);
    int res = 0;
    scanf("%d", &res);
    return pos - res;
}

void guess(int ans) {
    printf("! %d\n", ans);
    fflush(stdout);
}

int binary_search(int l, int r, int value) {
    int ans = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        int res = ask(m);
        if (res >= value) {
            ans = m;
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    assert(ans != -1);
    return ans;
}

void solve() {
    int t;
    scanf("%d %d", &n, &t);
    for (int i = 1, k; i <= t; i++) {
        scanf("%d", &k);
        guess(binary_search(1, n, k));
    }
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}