#include <bits/stdc++.h>
using namespace std;

int T, n;
char s[110];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %s", &n, s + 1);
        for (int i = 1, cnt = 0; i <= n; i++) {
            if (s[i] == 'U') {
                putchar('D');
            } else if (s[i] == 'D') {
                putchar('U');
            } else {
                putchar(++cnt % 2 == 1 ? 'L' : 'R');
            }
        }
        putchar('\n');
    }
    return 0;
}