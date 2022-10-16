#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int a[1001];
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int cnt = 0;
    for (int i = 1; i <= n; i++) cnt += (a[i] == 1);
    printf("%d\n", cnt);
    for (int i = 1; i <= n; i++)
        if ((i == n) || (a[i + 1] == 1)) printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}