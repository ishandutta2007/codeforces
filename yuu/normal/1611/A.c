#include <stdio.h>
int n;
void solve() {
    scanf("%d", &n);
    if (n % 2 == 0) {
        printf("0\n");
        return;
    }
    int z = 0;
    while (n >= 10) {
        if (n % 2 == 0) z++;
        n /= 10;
    }
    if (n % 2 == 0) {
        printf("1\n");
        return;
    }
    if (z)
        printf("2\n");
    else
        printf("-1\n");
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}