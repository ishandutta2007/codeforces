#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
int c[200001];
char s[200001];
char last_char[26];
void solve() {
    scanf("%d", &n);
    scanf("%s", &s);
    int required = 0;
    for (int i = 0; i < n; i++) {
        int found = -1;
        for (int j = 0; j < required; j++) {
            if (last_char[j] > s[i]) continue;
            if (found == -1) {
                found = j;
            } else if (last_char[j] > last_char[found]) {
                found = j;
            }
        }
        if (found == -1) {
            found = required;
            required++;
        }
        last_char[found] = s[i];
        c[i] = found;
    }
#ifdef FOR_E1
    if (required <= 2) {
        puts("YES");
    } else {
        puts("NO");
        return;
    }
#else
    printf("%d\n", required);
    for (int i = 0; i < n; i++) c[i]++;
#endif
    for (int i = 0; i < n; i++) {
        printf("%d", c[i]);
#ifndef FOR_E1
        putchar(' ');
#endif
    }
}

int main() {
    int t = 1;
    // scanf("%d", &t);
    while (t--) solve();
}