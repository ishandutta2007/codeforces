#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int n, q, a[N][26];

char s[N];

int main() {
    scanf("%s%d", s + 1, &q);
    n = strlen(s + 1);

    for (int i = 1; i <= n; i++) {
        memcpy(a[i], a[i - 1], sizeof(a[i]));
        a[i][s[i] - 'a']++;
    }

    for (int l, r, i = 1; i <= q; i++) {
        scanf("%d%d", &l, &r);

        if (l == r || s[l] != s[r]) {
            puts("Yes");
            continue;
        }

        int cnt = 0;

        for (int j = 0; j < 26; j++) {
            cnt += a[r][j] - a[l - 1][j] > 0;
        }

        if (cnt >= 3) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
}