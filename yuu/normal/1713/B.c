#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int a[100001];
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int pos = 1;
    for (int i = 2; i <= n; i++)
        if (a[i] > a[pos]) pos = i;
    for (int i = pos + 1; i <= n; i++) {
        if (a[i] > a[i - 1]) {
            puts("NO");
            return;
        }
    }
    for (int i = pos - 1; i >= 1; i--) {
        if (a[i] > a[i + 1]) {
            puts("NO");
            return;
        }
    }
    puts("YES");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}