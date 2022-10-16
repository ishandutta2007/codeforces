#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
char s[100001];
int cnt[256];
void solve() {
    scanf("%s", &s);
    n = strlen(s);
    cnt['L'] = cnt['R'] = cnt['U'] = cnt['D'] = 0;
    for (int i = 0; i < n; i++) cnt[s[i]]++;
    int a = cnt['L'];
    if (a > cnt['R']) a = cnt['R'];
    int b = cnt['U'];
    if (b > cnt['D']) b = cnt['D'];
    if (a == 0) {
        if (b) b = 1;
    } else if (b == 0) {
        a = 1;
    }
    printf("%d\n", (a + b) * 2);
    for (int i = 0; i < a; i++) putchar('L');
    for (int i = 0; i < b; i++) putchar('U');
    for (int i = 0; i < a; i++) putchar('R');
    for (int i = 0; i < b; i++) putchar('D');
    putchar('\n');
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}