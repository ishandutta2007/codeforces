#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
char s[7];
void solve() {
    scanf("%s", &s);
    int val = 0;
    for (int i = 0; i < 3; i++) val += s[i];
    for (int i = 3; i < 6; i++) val -= s[i];
    if (val == 0) printf("YES\n");
    else printf("NO\n");
}
int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}