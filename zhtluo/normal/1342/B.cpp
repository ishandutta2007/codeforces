#include <bits/stdc++.h>

char inp[200];

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%s", inp);
        int l = strlen(inp);
        bool f0 = false, f1 = false;
        for (int i = 0; i < l; ++i) {
            f0 |= inp[i] == '0';
            f1 |= inp[i] == '1';
        }
        if (!f0) {
            for (int i = 0; i < l; ++i) printf("1");
            puts("");
        } else if (!f1) {
            for (int i = 0; i < l; ++i) printf("0");
            puts("");
        } else {
            for (int i = 0; i < l; ++i) printf("01");
            puts("");
        }
    }
}