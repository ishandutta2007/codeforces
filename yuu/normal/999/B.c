#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
char s[102];
void reverse(int l, int r) {
    while (l < r) {
        s[l] ^= s[r];
        s[r] ^= s[l];
        s[l] ^= s[r];
        l++;
        r--;
    }
}
void solve() {
    scanf("%d", &n);
    scanf("%s", &s[1]);
    for (int i = 1; i <= n; i++)
        if (n % i == 0) reverse(1, i);
    puts(&s[1]);
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}