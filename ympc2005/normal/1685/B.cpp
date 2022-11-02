#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int c, d, x, y, z, a[N], b[N], cnta, cntb, n, fa[N], ga[N], fb[N], gb[N];

char s[N];

void init_() {
    scanf("%d%d%d%d%s", &c, &d, &x, &y, s + 1);
    z = 0, n = strlen(s + 1);
    cnta = cntb = 0;

    for (int l = 1, r; l <= n; l = r + 1) {
        r = l;

        while (r < n && s[r] != s[r + 1]) {
            r++;
        }

        if (s[l] == s[r]) {
            z += (r - l + 1)/2;
        } else if (s[l] == 'A') {
            a[++cnta] = (r - l + 1)/2;
        } else {
            b[++cntb] = (r - l + 1)/2;
        }
    }
}

void work_() {
    int tot = c + x + y;

    for (int i = 1; i <= n; i++) {
        tot -= s[i] == 'A';
    }

    if (tot) {
        puts("NO");
        return;
    }

    sort(a + 1, a + cnta + 1);
    sort(b + 1, b + cntb + 1);

    for (int i = 1; i <= cnta; i++) {
        fa[i] = fa[i - 1] + a[i];
    }

    for (int i = 1; i <= cntb; i++) {
        fb[i] = fb[i - 1] + b[i];
    }

    ga[cnta + 1] = 0;

    for (int i = cnta; i; i--) {
        ga[i] = ga[i + 1] + a[i] - 1;
    }

    gb[cntb + 1] = 0;

    for (int i = cntb; i; i--) {
        gb[i] = gb[i + 1] + b[i] - 1;
    }

    for (int i = 0; i <= cnta; i++) {
        if (fa[i] >= x) {
            if (ga[i + 1] + fb[cntb] + z >= y) {
                puts("YES");
                return;
            }
        } else {
            int sum = z + ga[i + 1] + fa[i];

            if (sum >= x) {
                if (sum - x + fb[cntb] >= y) {
                    puts("YES");
                    return;
                }
            } else {
                int val = x - sum, l = 1, r = cntb;

                if (gb[1] < val) {
                    continue;
                }

                while (l < r) {
                    int mid = (l + r + 1)>>1;

                    if (gb[mid] >= val) {
                        l = mid;
                    } else {
                        r = mid - 1;
                    }
                }

                if (gb[l] - val + fb[l - 1] >= y) {
                    puts("YES");
                    return;
                }
            }
        }
    }

    puts("NO");
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        init_();
        work_();
    }
}