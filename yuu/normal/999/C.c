#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, k;
char s[400002];
int nx[400002];
int first[256];
void solve() {
    scanf("%d %d", &n, &k);
    if (n == k) return;
    scanf("%s", &s[1]);
    for (int i = n; i >= 1; i--) {
        nx[i] = first[s[i]];
        first[s[i]] = i;
    }
    int use = 'a';
    for (int i = 1; i <= k; i++) {
        while (!first[use]) use++;
        s[first[use]] = 0;
        first[use] = nx[first[use]];
    }
    for (int i = 1; i <= n; i++)
        if (s[i]) putchar(s[i]);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}