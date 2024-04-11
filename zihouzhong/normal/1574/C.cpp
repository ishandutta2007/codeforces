#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int n, m;
ll a[maxn];

int main() {
    scanf("%d", &n);
    ll all = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]), all += a[i];
    }
    sort(a + 1, a + n + 1);
    scanf("%d", &m);
    while (m--) {
        ll x, y;
        scanf("%lld %lld", &x, &y);
        int pos = lower_bound(a + 1, a + n + 1, x) - a;
        ll ans = LLONG_MAX;
        if (pos <= n) ans = max(0LL, y - (all - a[pos]));
        if (pos > 1) ans = min(ans, max(0LL, x - a[pos - 1]) + max(0LL, y - (all - a[pos - 1])));
        printf("%lld\n", ans);
    }
    return 0;
}