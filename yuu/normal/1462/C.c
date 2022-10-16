#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void solve() {
    int x;
    scanf("%d", &x);
    if (x > 45) {
        printf("-1\n");
        return;
    }
    int a = 9;
    while (x > a) {
        x -= a;
        a--;
    }
    printf("%d", x);
    for (int i = a + 1; i <= 9; i++) printf("%d", i);
    printf("\n");
}
int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}