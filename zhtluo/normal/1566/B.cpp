#include <bits/stdc++.h>

int T;
char str[110000];

int main() {
    scanf("%d", &T); while (T--) {
        scanf(" %s", str);
        int a[2]; a[0] = a[1] = 0;
        a[str[0] - '0']++;
        int l = strlen(str);
        for (int i = 1; i < l; ++i) {
            if (str[i] != str[i - 1]) {
                a[str[i] - '0']++;
            }
        }
        if (a[0] == 0) printf("0\n");
        else if (a[0] == 1) printf("1\n");
        else printf("2\n");
    }
}