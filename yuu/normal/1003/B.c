#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a, b, x;

void solve() {
    scanf("%d %d %d", &a, &b, &x);
    int region = x + 1;
    int odd = (region + 1) / 2;
    int even = region - odd;
    char ch_a = '0', ch_b = '1';
    if (a < b) {
        int t = a;
        a = b;
        b = t;
        ch_a = '1';
        ch_b = '0';
    }

    for (int i = 1; i <= region; i++) {
        if (i % 2) {
            odd--;
            while (a > odd) {
                putchar(ch_a);
                a--;
            }
        } else {
            even--;
            while (b > even) {
                putchar(ch_b);
                b--;
            }
        }
    }
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}