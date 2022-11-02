#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, T;

char s[N];

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%s", &n, s + 1);

        if (n == 1 || s[1] <= s[2]) {
            printf("%c%c\n", s[1], s[1]);
            continue;
        }

        int pos = 1;

        while (pos < n && s[pos + 1] <= s[pos]) {
            pos++;
        }

        for (int i = 1; i <= pos; i++) {
            putchar(s[i]);
        }

        for (int i = pos; i; i--) {
            putchar(s[i]);
        }

        puts("");
    }
}