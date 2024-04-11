#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
char s[100001];
void solve() {
    scanf("%d %s", &n, &s);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'W') continue;
        int j = i;
        while ((j + 1 < n) && (s[j + 1] != 'W')) j++;
        bool good = false;
        for (int k = i + 1; k <= j; k++)
            if (s[k] != s[k - 1]) {
                good = true;
                break;
            }
        if (!good) {
            printf("No\n");
            return;
        }
        i = j;
    }
    printf("Yes\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}