#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 100006;

ll a[N], b[N];

int main () {
    int n, d, m; scanf("%d%d%d", &n, &d, &m);
    int x = 0, y = 0;
    for (int i = 1; i <= n; ++i) {
        ll tmp; scanf("%lld", &tmp);
        if (tmp <= m) {
            a[++x] = tmp;
        }
        else {
            b[++y] = tmp;
        }
    }
    sort(a + 1, a + x + 1); reverse(a + 1, a + x + 1);
    sort(b + 1, b + y + 1); reverse(b + 1, b + y + 1);
    for (int i = 1; i <= y; ++i) {
        b[i] += b[i - 1];
    }
    for (int i = 1; i <= x; ++i) {
        a[i] += a[i - 1];
    }
    ll ans = 0;
    for (int i = 0; i <= x; ++i) {
        ll day_left = n - i;
        ll can_do = (day_left + (d + 1) - 1) / (d + 1);
        can_do = min(can_do, y * 1ll);
        // cerr << "i = " << i << " , a = " << a[i] << " , b = " << b[can_do] << endl;
        ans = max(ans, a[i] + b[can_do]);
    }
    printf("%lld\n", ans);
}