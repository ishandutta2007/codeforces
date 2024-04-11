#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve() {
    int h, m;
    scanf("%d %d", &h, &m);
    printf("%d\n", (23-h)*60 + (60 - m));
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}