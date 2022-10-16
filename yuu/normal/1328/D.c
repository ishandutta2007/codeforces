#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int t[200000];
int c[200000];
void output() {
    int ans = 0;
    for (int i = 0; i < n; i++) {
        c[i]++;
        if (ans < c[i]) ans = c[i];
    }
    printf("%d\n", ans);
    for (int i = 0; i < n; i++) printf("%d ", c[i]);
    printf("\n");
}
void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &t[i]);
    int start = -1;
    for (int i = 0; i < n; i++)
        if (t[i] == t[(i + n - 1) % n]) {
            start = i;
            break;
        }
    if (start != -1) {
        c[start] = 0;
        for (int i = 1; i < n; i++) {
            if (t[(start + i) % n] != t[(start + i - 1) % n]) {
                c[(start + i) % n] = 1 - c[(start + i - 1) % n];
            } else {
                c[(start + i) % n] = c[(start + i - 1) % n];
            }
        }
    } else {
        for (int i = 0; i < n; i++) c[i] = i % 2;
        if (n % 2) c[n - 1] = 2;
    }
    output();
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}