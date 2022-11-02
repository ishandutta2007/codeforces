#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

ll S, a[N];

int n, m;

set <ll> h;

set <ll> :: iterator it;

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) 
        scanf("%lld", &a[i]), S += a[i], h.insert(a[i]);
    
    scanf("%d", &m);
    
    for (int i = 1; i <= m; i++) {
        ll x, y, z, ans = 4e18;
        scanf("%lld%lld", &x, &y);

        it = h.lower_bound(x);

        if (it != h.end()) {
            z = max(y - S + *it, 0ll);
            ans = min(ans, z);
        }

        if (it != h.begin()) {
            z = *(--it);
            ans = min(ans, x - z + max(0ll, y + z - S));
        }

        printf("%lld\n", ans);
    }
}