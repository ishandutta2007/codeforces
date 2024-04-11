#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int a[200001];
int cnt[200001];
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) cnt[i] = 0;
    for (int i = n; i >= 1; i--) {
        cnt[a[i]]++;
        if (cnt[a[i]] == 2) {
            printf("%d\n", i);
            return;
        }
    }
    printf("0\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}