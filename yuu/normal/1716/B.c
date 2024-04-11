#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a[102];
int n;

void write(int x) {
    if (x > 9) write(x / 10);
    putchar(x % 10 + '0');
}

void output() {
    for (int i = 1; i <= n; i++) {
        write(a[i]);
        putchar(' ');
    }
    putchar('\n');
}
void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) a[i] = i;
    write(n);
    putchar('\n');
    for (int i = 1; i <= n; i++) {
        output();
        a[i + 1] ^= a[i];
        a[i] ^= a[i + 1];
        a[i + 1] ^= a[i];
    }
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}