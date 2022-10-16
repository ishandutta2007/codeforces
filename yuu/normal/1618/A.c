#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int b[7];
void solve() {
    for (int i = 0; i < 7; i++) scanf("%d", &b[i]);

    if (b[0] + b[1] + b[2] == b[6]) {
        printf("%d %d %d\n", b[0], b[1], b[2]);
        return;
    } else {
        printf("%d %d %d\n", b[0], b[1], b[3]);
    }
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}