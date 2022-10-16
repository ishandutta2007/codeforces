#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[27];
int n;
void solve() {
    scanf("%s", s);
    n = strlen(s);
    int front = 0, back = n - 1;
    while (n--) {
        if (s[front] == ('a' + n)) {
            front++;
        } else if (s[back] == ('a' + n)) {
            back--;
        } else {
            printf("No\n");
            return;
        }
    }
    printf("Yes\n");
    return;
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}