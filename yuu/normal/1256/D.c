#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int64_t k;
char s[1000001];
void solve() {
    scanf("%d %lld", &n, &k);
    scanf("%s", &s);
    int one_count = 0;
    int zero_count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            one_count++;
        } else {
            if (k >= one_count) {
                k -= one_count;
                zero_count++;
            } else {
                for (int i = 1; i <= zero_count; i++) putchar('0');
                for (int j = 1; j <= one_count - k; j++) putchar('1');
                putchar('0');
                for (int j = 1; j <= k; j++) putchar('1');
                for (int j = i + 1; j < n; j++) putchar(s[j]);
                putchar('\n');
                return;
            }
        }
    }
    for (int i = 1; i <= zero_count; i++) putchar('0');
    for (int i = 1; i <= one_count; i++) putchar('1');
    putchar('\n');
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}