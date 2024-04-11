#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve() {
    int b, w;
    scanf("%d %d", &b, &w);
    int start_x = 2;
    int start_y = 2;
    if (b < w) {
        start_y++;
        b ^= w;
        w ^= b;
        b ^= w;
    }
    assert(w <= b);
    // use wbwbwbwbwbwbw
    int max_add = w * 2 + 2;
    if (w - 1 + max_add < b) {
        puts("NO");
        return;
    }
    puts("YES");
    for (int i = 0; i < w; i++) printf("%d %d\n", start_x + i * 2, start_y);
    for (int i = 0; i + 1 < w; i++) {
        printf("%d %d\n", start_x + i * 2 + 1, start_y);
        b--;
    }
    for (int i = 0; i < w; i++) {
        if (b > 0) {
            printf("%d %d\n", start_x + i * 2, start_y - 1);
            b--;
        }
        if (b > 0) {
            printf("%d %d\n", start_x + i * 2, start_y + 1);
            b--;
        }
        if (i == 0) {
            if (b > 0) {
                printf("%d %d\n", start_x - 1, start_y);
                b--;
            }
        }
        if (i == w - 1) {
            if (b > 0) {
                printf("%d %d\n", start_x + i * 2 + 1, start_y);
                b--;
            }
        }
    }
    assert(b == 0);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}