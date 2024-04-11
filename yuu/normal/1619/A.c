#include <stdio.h>
#include <string.h>

char s[101];
int n;
void solve() {
    scanf("%s", s);
    n = strlen(s);
    if (n % 2) {
        printf("NO\n");
        return;
    }
    for (int i = 0; i < (n / 2); i++) {
        if (s[i] != s[i + n / 2]) {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}

int main() {
    int t = 1;
    scanf("%d\n", &t);
    while (t--) solve();
}