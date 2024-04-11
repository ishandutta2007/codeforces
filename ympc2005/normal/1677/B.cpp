#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;

int T, n, m, ans, c[N], tag[N];

char s[N];

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d%s", &n, &m, s);

        for (int i = 0; i < m; i++) {
            tag[i] = c[i] = 0;
        }

        ans = 0;

        for (int i = 0, j = -1; i < n*m; i++) {
            ans += tag[i%m];

            if (s[i] == '1') {
                if (!c[i%m]) {
                    c[i%m] = 1;
                    ans++;
                }

                if (j == -1 || j <= i - m) {
                    ans++;
                } else {
                    tag[j%m]++;
                    tag[i%m]--;
                }

                j = i;
            }

            printf("%d ", ans);
        }

        putchar('\n');
    }
}