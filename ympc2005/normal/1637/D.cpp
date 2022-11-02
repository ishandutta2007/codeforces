#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

const int N = 105;

int n, T, a[N], b[N], sum;

bitset <N*N> f;

ll ans;

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n), sum = 0, ans = 0;

        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            ans += 1ll*a[i]*a[i]*(n - 2);
            sum += a[i];
        }

        for (int i = 1; i <= n; i++) {
            scanf("%d", &b[i]);
            ans += 1ll*b[i]*b[i]*(n - 2);
            sum += b[i];
        }

        f.reset();
        f[0] = 1;

        for (int i = 1; i <= n; i++) {
            f = (f<<a[i])|(f<<b[i]);
        }

        ll res = 1e18;

        for (int i = 0; i <= n*100; i++) {
            if (f[i]) {
                res = min(res, 1ll*i*i + 1ll*(sum - i)*(sum - i));
            }
        }
        
        printf("%lld\n", ans + res);
    }
}