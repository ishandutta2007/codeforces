#include <bits/stdc++.h>

const int kN = 5e3 + 5;
char s[kN]; int n; bool p[kN][kN];

void Init() {
    for(int i = 1; i <= n; ++i) p[i][i] = true;
    for(int len = 1; len <= n; ++len)
        for(int i = 1; i + len <= n; ++i) {
            int j = i + len;
            if(s[i] == s[j] && (p[i + 1][j - 1] || len == 1)) p[i][j] = true;
            else p[i][j] = false;
        }
}

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        scanf("%s", s + 1); n = strlen(s + 1);
        Init();
        int x = 0;
        for(int i = 1; i <= n / 2; ++i) {
            if(s[i] == s[n - i + 1]) x = i;
            else break;
        }
        if(x == n - x) {
            printf("%s\n", s + 1);
            continue;
        }
        int l, r;
        for(int i = x + 1; i <= n - x; ++i)
            if(p[x + 1][i]) l = i;
        for(int i = n - x; i > x; --i)
            if(p[i][n - x]) r = i;
        if(l > (n - r + 1)) {
            for(int i = 1; i <= l; ++i)
                printf("%c", s[i]);
            for(int i = n - x + 1; i <= n; ++i)
                printf("%c", s[i]);
        } else {
            for(int i = 1; i <= x; ++i)
                printf("%c", s[i]);
            for(int i = r; i <= n; ++i)
                printf("%c", s[i]);
        }
        printf("\n");
    }
    return 0;
}