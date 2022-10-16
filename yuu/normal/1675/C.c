#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
int n;
char s[200002];
void solve() {
    scanf("%s", &s[1]);
    n = strlen(&s[1]);
    int last_1 = 0;
    for (int i = 1; i <= n; i++)
        if (s[i] == '1') last_1 = i;
    int first_0 = 0;
    for (int i = n; i >= 1; i--)
        if (s[i] == '0') first_0 = i;
    if (last_1 == 0) {
        if (first_0 == 0) {
            printf("%d\n", n);
        } else {
            printf("%d\n", first_0); 
        }
    } else {
        if (first_0 == 0) {
            printf("%d\n", n - last_1 + 1);
        } else {
            assert(first_0 >= last_1);
            printf("%d\n", first_0 - last_1 + 1);
        }
    }
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}