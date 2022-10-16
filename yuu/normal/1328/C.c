#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
char x[50001];
char a[50001];
char b[50001];
void solve() {
    scanf("%d", &n);
    scanf("%s", &x);
    bool first = true;
    for (int i = 0; i < n; i++) {
        if (x[i] == '0') {
            a[i] = '0';
            b[i] = '0';
            continue;
        } else if (x[i] == '2') {
            if (first) {
                a[i] = '1';
                b[i] = '1';
            } else {
                a[i] = '0';
                b[i] = '2';
            }
        } else {
            if (first) {
                a[i] = '1';
                b[i] = '0';
                first = false;
            } else {
                a[i] = '0';
                b[i] = '1';
            }
        }
    }
    a[n] = b[n] = 0;
    printf("%s\n%s\n", a, b);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}