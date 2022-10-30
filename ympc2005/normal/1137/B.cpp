#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

int n, m, nex[N], a[2], b[2], c[2];

char s[N], t[N];

int main() {
    scanf("%s%s", s + 1, t + 1);
    n = strlen(s + 1);
    m = strlen(t + 1);

    for (int j = 0, i = 2; i <= m; i++) {
        while (j && t[j + 1] != t[i]) {
            j = nex[j];
        }

        if (t[j + 1] == t[i]) {
            nex[i] = ++j;
        }
    }

    for (int i = 1; i <= m; i++) {
        b[t[i] - '0']++;

        if (i > nex[m]) {
            c[t[i] - '0']++;
        }
    }   

    for (int i = 1; i <= n; i++) {
        a[s[i] - '0']++;
    }

    if (a[0] < b[0] || a[1] < b[1]) {
        printf("%s\n", s + 1);
        exit(0);
    }

    a[0] -= b[0];
    a[1] -= b[1];

    for (int i = 1; i <= m; i++) {
        putchar(t[i]);
    }

    int len = 1e9;

    if (c[0]) {
        len = min(len, a[0]/c[0]);
    }

    if (c[1]) {
        len = min(len, a[1]/c[1]);
    }

    for (int i = 1; i <= len; i++) {
        for (int j = nex[m] + 1; j <= m; j++) {
            putchar(t[j]);
        }
    }

    a[0] -= c[0]*len;
    a[1] -= c[1]*len;

    while (a[0]--) {
        putchar('0');
    }

    while (a[1]--) {
        putchar('1');
    }

    putchar('\n');
}