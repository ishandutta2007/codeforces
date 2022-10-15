#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int T, n;
char s[maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %s", &n, s + 1);
        bool flag = 0;
        for (int i = 1; i + n / 2 <= n && !flag; i++) if (s[i] == '0') {
            printf("%d %d %d %d\n", i, i + n / 2, i + 1, i + n / 2), flag = 1;
        }
        for (int i = n / 2 + 1; i <= n && !flag; i++) if (s[i] == '0') {
            printf("%d %d %d %d\n", 1, i, 1, i - 1), flag = 1;
        }
        if (!flag) {
            printf("%d %d %d %d\n", 1, n / 2, 2, n / 2 + 1);
        }
    }
    return 0;
}