#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int a[5000];
void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        for (int j = i + 2; j < n; j++)
            if (a[i] == a[j]) {
                puts("YES");
                return;
            }
    puts("NO");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}