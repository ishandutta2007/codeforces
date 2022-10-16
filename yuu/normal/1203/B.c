#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int cnt[10001];
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= 10000; i++) cnt[i] = 0;
    int mx = 0, mi = 1e4 + 1;
    for (int i = 1, a; i <= n * 4; i++) {
        scanf("%d", &a);
        cnt[a]++;
        if (mx < a) mx = a;
        if (mi > a) mi = a;
    }
    int area = mx * mi;
    for (int i = 1; i * i <= area; i++)
        if (cnt[i]) {
            if ((area % i) || (cnt[i] % 2)) {
                puts("NO");
                return;
            }
            int j = area / i;
            if (i == j) {
                if (cnt[i] % 4) {
                    puts("NO");
                    return;
                }
            } else if (cnt[j] != cnt[i]) {
                puts("NO");
                return;
            }
        } else if ((area % i == 0) && ((area / i <= 10000) && cnt[area / i])) {
            puts("NO");
            return;
        }
    puts("YES");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}