#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void solve() {
    int x, y;
    scanf("%d %d", &x, &y);
    if(y%x) {
        printf("0 0\n");
        return;
    }
    int val = y / x;
    printf("%d %d\n", 1, val);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}