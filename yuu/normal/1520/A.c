#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;
char s[51];

void solve() {
    scanf("%d %s", &n, &s);
    for (int i = 0; i < n; i++) {
        int j = i;
        while ((j + 1 < n) && (s[j + 1] == s[j])) j++;
        for (int k = j + 2; k < n; k++)
            if (s[k] == s[i]) {
                printf("NO\n");
                return;
            }
        i = j;
    }
    printf("YES\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}