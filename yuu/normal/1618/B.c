#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
int n;
char s[100][3];

void make(int before) {
    for (int i = 0; i <= before; i++) printf("%c", s[i][0]);
    printf("%c", s[before][1]);
    for (int i = before + 1; i + 2 < n; i++) printf("%c", s[i][0]);
    printf("%c", s[n - 3][1]);
    printf("\n");
}

void solve() {
    scanf("%d", &n);
    for (int i = 0; i < n - 2; i++) scanf("%s", &s[i]);

    for (int i = 0; i + 1 < n - 2; i++) {
        if (s[i][1] != s[i + 1][0]) {
            make(i);
            return;
        }
    }
    make(0);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}