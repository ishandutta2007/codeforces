#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1005;

int n;

ll ans, a[N], b[N];

int main() {
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        b[i] = i&1 ? a[i] : -a[i];
    }   

    for (int l = 1; l < n; l += 2) {
        ll s = 0, v = 0;

        for (int r = l + 1; r <= n; r += 2) {
            ll mn = max(v, 1ll), mx = min(a[l], a[r] - s);

            if (mn <= mx) 
                ans += mx - mn + 1;
            
            s += b[r];
            v = max(v, -s);
            s += b[r + 1];
        } 
    }

    printf("%lld\n", ans);
}