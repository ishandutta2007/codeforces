#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

ll f[N][20], a[N];

int T, n, ans;

ll gcd_(ll a, ll b) {
    return b ? gcd_(b, a%b) : a;
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n), ans = 1;

        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]), f[i][0] = abs(a[i] - a[i - 1]);
        
        for (int k = 1; k < 20; k++)    
            for (int i = 1; i + (1<<k) - 1 <= n; i++)
                f[i][k] = gcd_(f[i][k - 1], f[i + (1<<k - 1)][k - 1]);
            
        for (int i = 2; i <= n; i++) {
            int res = 1, p = i;
            ll x = 0;

            for (int k = 19; k >= 0; k--)
                if (p + (1<<k) - 1 <= n && gcd_(x, f[p][k]) > 1) {
                    res += 1<<k;
                    x = gcd_(x, f[p][k]);
                    p += (1<<k);
                }
            
            ans = max(ans, res);
        }

        printf("%d\n", ans);
    }
}