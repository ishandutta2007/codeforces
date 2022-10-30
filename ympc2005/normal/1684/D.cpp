#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

int n, m, a[N], b[N], T;

int main() {
    cin>>T;

    while (T--) {
        cin>>n>>m;
        ll ans = 1e18, S = 0;

        for (int i = 1; i <= n; i++) {
            cin>>a[i];
            b[i] = a[i] - n + i;
            S += a[i];
        }

        sort(b + 1, b + n + 1);
        reverse(b + 1, b + n + 1);

        for (int i = 0; i <= m; i++) {
            S -= b[i];
            ans = min(ans, S - 1ll*i*(i - 1)/2);
        }

        printf("%lld\n", ans);
    }
}