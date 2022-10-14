#include <bits/stdc++.h>

int T;
char str[2][110000];

int main() {
    scanf("%d", &T); while (T--) {
        int l;
        scanf("%d %s %s", &l, str[0], str[1]);
        int a[2]; a[0] = a[1] = 0;
        int ans = 0;
        for (int i = 0; i < l; ++i) {
            if (str[0][i] != str[1][i]) {
                ans += 2;
                if (a[0]) ans += 1;
                a[0] = a[1] = 0;
            } else {
                if (a[1 ^ str[0][i] - '0']) {
                    ans += 2;
                    a[0] = a[1] = 0;
                } else {
                    if (a[0]) ans += 1;
                    a[0] = a[1] = 0;
                    a[str[0][i] - '0']++;
                }
            }
        }
        if (a[0]) ans += 1;
        printf("%d\n", ans);
    }
}