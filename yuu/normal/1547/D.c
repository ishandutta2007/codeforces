#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int n;
int x[200001];
int y[200001];

int find_min(int x, int a) {
    // min y that (x^y) & a == a
    int y = 0;
    for (int i = 0; i < 30; i++)
        if ((a >> i) & 1) {
            if (((x >> i) & 1) == 0) {
                y ^= (1 << i);
            }
        }
    return y;
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
    y[1] = 0;
    for (int i = 2; i <= n; i++) y[i] = find_min(x[i], x[i - 1] ^ y[i - 1]);
    for (int i = 1; i <= n; i++) printf("%d ", y[i]);
    printf("\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}