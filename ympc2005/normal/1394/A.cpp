#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int n, m, d, na, nb;

ll a[N], b[N];

int main() {
    scanf("%d%d%d", &n, &d, &m);

    for (int x, i = 1; i <= n; i++) {
        scanf("%d", &x);

        if (x <= m) {
            a[++na] = x;
        } else {
            b[++nb] = x;
        }
    }

    sort(a + 1, a + na + 1);
    sort(b + 1, b + nb + 1);
    reverse(a + 1, a + na + 1);
    reverse(b + 1, b + nb + 1);

    for (int i = 1; i <= na; i++) {
        a[i] += a[i - 1];
    }

    for (int i = 1; i <= nb; i++) {
        b[i] += b[i - 1];
    }

    ll ans = 0;

    for (int i = 0; i <= na; i++) {
        int t = n - i >= d + 2 ? (n - i - 1)/(d + 1) + 1 : n - i > 0;
        ans = max(ans, a[i] + b[t]);
    }

    printf("%lld\n", ans);
}