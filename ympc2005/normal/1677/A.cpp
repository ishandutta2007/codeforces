#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5005;

int n, a[N], T, s[N][N];

ll ans;

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);
        ans = 0;

        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                s[i][j] = s[i][j - 1] + (a[i] > a[j]);
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ans += s[j][i - 1]*(s[i][n] - s[i][j]);
            }
        }

        printf("%lld\n", ans);
    }
}