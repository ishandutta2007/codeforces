#include <bits/stdc++.h>

typedef long long ll;

const int kN = 2e5 + 5;
const int kMod = 998244353;

int p[kN];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i) scanf("%d", p + i);
    ll ans = 0, cnt = 1;
    for(int i = n; i > n - k; --i) ans += i;
    int lst = 0;
    for(int i = 1; i <= n; ++i)
        if(p[i] > n - k) {
            if(lst) cnt = cnt * (i - lst) % kMod;
            lst = i;
        }
    printf("%lld %lld\n", ans, cnt);
    return 0;
}