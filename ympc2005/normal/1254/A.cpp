#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int n, m, cnt, sum, a[N];

char s[N][N], id[N];

void work_() {
    scanf("%d%d%d", &n, &m, &cnt);

    for (int i = 0; i < 26; i++) {
        id[i] = 'a' + i;
    }

    for (int i = 26; i < 52; i++) {
        id[i] = 'A' + i - 26;
    }

    for (int i = 52; i < 62; i++) {
        id[i] = '0' + i - 52;
    }

    sum = 0;

    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);

        for (int j = 1; j <= m; j++) {
            sum += s[i][j] == 'R';
        }
    }

    for (int i = 0; i < cnt; i++) {
        a[i] = sum/cnt + (sum%cnt > i);
    }

    for (int i = 1, p = 0; i <= n; i++) {
        if (i&1) {
            for (int j = 1; j <= m; j++) {
                a[p] -= s[i][j] == 'R';
                s[i][j] = id[p];

                if (!a[p] && p + 1 < cnt) {
                    p++;
                }
            }
        } else {
            for (int j = m; j; j--) {
                a[p] -= s[i][j] == 'R';
                s[i][j] = id[p];

                if (!a[p] && p + 1 < cnt) {
                    p++;
                }
            }   
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%s\n", s[i] + 1);
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        work_();
    }
}