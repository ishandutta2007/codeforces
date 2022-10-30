#include <bits/stdc++.h>
using namespace std;

const int N = 2005;

int n, m, T, cnt, L[N], R[N];

char s[N];

void rev_(int l, int r) {
    reverse(s + l, s + r + 1);
    ++cnt;
    L[cnt] = l, R[cnt] = r;
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d%s", &n, &m, s + 1);
        cnt = 0;

        for (int i = 1, j = 0; i <= n; i++) {
            if (s[i] == '(') {
                rev_(++j, i);
            }
        }

        for (int i = 1; i < m; i++) {
            rev_(2*i, n/2 + i);
        }

        printf("%d\n", cnt);

        for (int i = 1; i <= cnt; i++) {
            printf("%d %d\n", L[i], R[i]);
        }
    }
}