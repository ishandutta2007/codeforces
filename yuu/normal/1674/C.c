#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
char s[51];
char t[51];
int n, m;
void solve() {
    scanf("%s %s", &s, &t);
    n = strlen(s);
    m = strlen(t);
    bool has_a = 0;
    for (int i = 0; i < m; i++)
        if (t[i] == 'a') {
            has_a = 1;
            break;
        }
    if (has_a) {
        if (m == 1) {
            printf("1\n");
        } else {
            printf("-1\n");
        }
    } else {
        printf("%lld\n", 1LL << n);
    }
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}