#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve() {
    int s;
    scanf("%d", &s);
    int d = 9;
    while ((s >= d) && d) {
        s -= d;
        d--;
    }
    if (s) printf("%d", s);
    for (int i = d + 1; i <= 9; i++) printf("%d", i);
    printf("\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}