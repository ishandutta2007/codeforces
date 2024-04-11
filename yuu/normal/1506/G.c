#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[200001];
int n;
int remain[26];
int mask[200001];
void solve() {
    scanf("%s", &s);
    n = strlen(s);
    for (int i = 0; i < n; i++) s[i] -= 'a';
    mask[n] = 0;
    for (int i = n - 1; i >= 0; i--) mask[i] = (mask[i + 1] | (1 << s[i]));
    int mask_remain = mask[0];
    int start = 0;
    while (mask_remain) {
        for (int i = 0; i < n; i++) mask[i] &= mask_remain;
        for (int i = 26; i >= 0; i--) {
            if (mask_remain & (1 << i)) {
                for (int j = start; j <= n; j++)
                    if (s[j] == i) {
                        if ((mask[j] & mask_remain) != mask_remain) break;
                        if ((mask[j + 1] & (mask_remain ^ (1 << i))) != (mask_remain ^ (1 << i))) break;
                        printf("%c", i + 'a');
                        start = j + 1;
                        mask_remain ^= (1 << i);
                        goto next_char;
                    }
            }
        }
    next_char:;
    }
    printf("\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}