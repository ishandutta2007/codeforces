#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int ans[100001];
void solve() {
    int n;
    scanf("%d", &n);
    ans[1] = 1;
    for (int i = n; i > 1; i -= 2) {
        ans[i] = i - 1;
        ans[i - 1] = i;
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    printf("\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}