#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 10;

int n, m, a[N], T;

char s[N];

bool solve_() {
    for (int i = 0; i < m; i++) {
        a[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            continue;
        }

        if (~a[i%m]) {
            if (a[i%m] != s[i] - '0') {
                return 0;
            }
        } else {
            a[i%m] = s[i] - '0';
        }
    }

    int c0 = 0, c1 = 0;

    for (int i = 0; i < m; i++) {
        if (a[i] == 0) {
            c0++;
        }

        if (a[i] == 1) {
            c1++;
        }
    }

    return max(c0, c1) <= m - max(c0, c1);
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d%s", &n, &m, s);
        printf("%s\n", solve_() ? "YES" : "NO");
    }
}