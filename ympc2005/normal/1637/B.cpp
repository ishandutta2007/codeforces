#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 105;

int n, a[N], T, b[N][N];

ll f[N];

map <int, int> mp;

void solve_() {
    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        mp.clear();
        b[i][i - 1] = 0;

        for (int j = i; j <= n; j++) {
            b[i][j] = b[i][j - 1];
            mp[a[j]] = 1;

            while (mp[b[i][j]]) {
                b[i][j]++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        f[i - 1] = 0;

        for (int j = i; j <= n; j++) {
            f[j] = 0;

            for (int k = i; k <= j; k++) {
                f[j] = max(f[j], f[k - 1] + b[k][j] + 1);
            }

            ans += f[j];
        }
    }

    printf("%lld\n", ans);
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }

        solve_();
    }
}