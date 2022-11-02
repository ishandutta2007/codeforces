#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int T, n, ca, cb, cnt, pre[N], suf[N];

char a[N], b[N];

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%s%s", &n, a + 1, b + 1);
        ca = cb = 0, cnt = 0;

        for (int i = 1; i <= n; i++) {
            ca += a[i] == '1';
            cb += b[i] == '1';
            cnt += a[i] != b[i];
        }

        if (ca != cb && n - ca + 1 != cb) {
            puts("-1");
            continue;
        }

        int ans = 1e9;

        if (ca == cb) {
            ans = cnt;
        }

        if (n - ca + 1 == cb) {
            pre[0] = suf[n + 1] = 0;

            for (int i = 1; i <= n; i++) {
                pre[i] = pre[i - 1] + (a[i] == b[i]);
            }

            for (int i = n; i; i--) {
                suf[i] = suf[i + 1] + (a[i] == b[i]);
            }
            
            for (int i = 1; i <= n; i++) {
                ans = min(ans, 1 + pre[i - 1] + suf[i + 1] + (a[i] != b[i]));
            }
        }

        printf("%d\n", ans);
    }
}