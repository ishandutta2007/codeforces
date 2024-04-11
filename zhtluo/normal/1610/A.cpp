#include <bits/stdc++.h>

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        int x, y; scanf("%d%d", &x, &y);
        if (x == 1 && y == 1) {
            puts("0");
        } else if (x == 1 || y == 1) {
            puts("1");
        } else if (x == 2 || y == 2) {
            puts("2");
        } else {
            puts("2");
        }
    }
}