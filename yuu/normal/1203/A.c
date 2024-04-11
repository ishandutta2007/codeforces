#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int a[200];
void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int add = 1;
    bool good = 1;
    for (int i = 0; i < n; i++) {
        if (a[i] % n + 1 != a[(i + add) % n]) {
            good = 0;
            break;
        }
    }
    if (good) {
        puts("YES");
        return;
    }
    good = 1;
    add = n - 1;
    for (int i = 0; i < n; i++) {
        if (a[i] % n + 1 != a[(i + add) % n]) {
            good = 0;
            break;
        }
    }
    if(good) puts("YES");
    else puts("NO");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}