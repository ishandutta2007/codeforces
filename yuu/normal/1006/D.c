#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
char a[100001];
char b[100001];
int get_cost(char x, char y, char u, char v) {
    if (u == v) return x != y;
    // u != v

    int eq = 0;
    eq += (x == u);
    eq += (x == v);
    eq += (y == u);
    eq += (y == v);
    if (eq == 2) {
        if (x != y) return 0;
        return 1;
    } else {
        return 2 - eq;
    }
}
void solve() {
    scanf("%d", &n);
    scanf("%s %s", a, b);
    int ans = 0;
    for (int i = 0; i <= n - i - 1; i++) {
        int j = n - i - 1;
        if (i == j) {
            ans += (a[i] != b[i]);
            break;
        }
        ans += get_cost(a[i], a[j], b[i], b[j]);
    }
    printf("%d\n", ans);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}