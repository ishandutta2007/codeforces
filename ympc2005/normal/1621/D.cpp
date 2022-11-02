#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 505;

int n, T, c[N][N];

ll ans;

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n), ans = 0;

        for (int i = 1; i <= 2*n; i++) {
            for (int j = 1; j <= 2*n; j++) {
                scanf("%d", &c[i][j]);

                if (i > n && j > n) {
                    ans += c[i][j];
                }
            }
        }

        int m = n<<1, val = 1e9;

        val = min(c[1][m], c[1][n + 1]);
        val = min(val, min(c[n][m], c[n][n + 1]));
        val = min(val, min(c[n + 1][1], c[n + 1][n]));
        val = min(val, min(c[m][1], c[m][n]));

        printf("%lld\n", ans + val);
    }
}