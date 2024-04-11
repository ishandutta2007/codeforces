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
    bool odd = false, even = false;
    for (int i = 0; i < n; i++)
        if (a[i] % 2) odd = 1;
        else even = 1;
    if (odd && even) puts("NO");
    else puts("YES");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}