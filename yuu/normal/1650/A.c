#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[50];
char c;
void solve() {
    scanf("%s", s);
    scanf("%s", &c);
    int n = strlen(s);
    for (int i = 0; i < n; i += 2)
        if (s[i] == c) {
            printf("YES\n");
            return;
        }
    printf("NO\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}