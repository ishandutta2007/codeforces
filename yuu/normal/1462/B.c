#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int n;
char s[201];
void solve() {
    scanf("%d %s", &n, &s);
    int front = 0, back = 0;
    while ((front < 4) && (s[front] == "2020"[front])) front++;
    while ((back < 4) && (s[n - back - 1] == "0202"[back])) back++;
    if (front + back >= 4) printf("YES\n");
    else printf("NO\n");
}
int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}