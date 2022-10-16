#include <stdio.h>
int a, b;
void solve() {
    scanf("%d %d", &a, &b);
    if (a < b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
    int diff = a - b;
    int ans = diff / 2;
    if (ans > b) ans = b;
    b -= ans;
    a -= ans * 2;
    int ans_2 = a / 2;
    if (ans_2 > b / 2) ans_2 = b / 2;
    printf("%d\n", ans + ans_2);
}

int main() {
    int t = 1;
    scanf("%d", &t);
    while (t--) solve();
}