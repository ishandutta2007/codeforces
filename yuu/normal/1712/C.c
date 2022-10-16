#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int a[100001];
bool req[100001];
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) req[i] = 0;
    int l = 1, ans = 0;
    req[0] = 1;
    while (l <= n) {
        int r = l;
        while (r <= n) {
            if (req[a[r]]) a[r] = 0;
            if (a[r] < a[r - 1]) {  // everything from l -> r must be 0
                for (int i = l; i < r; i++) {
                    if (!req[a[i]]) {
                        req[a[i]] = 1;
                        ans++;
                    }
                    a[i] = 0;
                }
                break;
            } else {
                r++;
            }
        }
        l = r;
    }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}