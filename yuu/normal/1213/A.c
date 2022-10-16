#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int cnt[2];
void solve() {
    scanf("%d", &n);
    while (n--) {
        int a;
        scanf("%d", &a);
        cnt[a % 2]++;
    }
    if (cnt[0] > cnt[1]) cnt[0] = cnt[1];
    printf("%d\n", cnt[0]);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}