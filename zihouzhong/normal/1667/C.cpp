#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
    scanf("%d", &n);
    int m = n / 3 * 2 + (n % 3 > 0);
    printf("%d\n1 1\n", m);
    if (!(n % 3)) {
        for (int i = 1, j = 0; i < m; i++) {
            if (2 * i - 1 < m) printf("%d %d\n", i + 1, 2 * i);
            else printf("%d %d\n", i + 1, 2 * ++j + 1);
        }
    } else {
        for (int i = 1, j = 0; i < m; i++) {
            if (2 * i <= m) printf("%d %d\n", i + 1, 2 * i + 1);
            else printf("%d %d\n", i + 1, 2 * ++j);
        }
    }
    return 0;
}