#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 10;

int n, a[N], b[N], T, x, y;

ll ans;

void solve0_() {
    ll res = 0;

    for (int i = 1; i <= n; i++) 
        if (!a[i])
            res += abs((i - b[i] - 1) - b[i]);
    
    ans = min(ans, res);
}

void solve1_() {
    ll res = 0;

    for (int i = 1; i <= n; i++) 
        if (!a[i])
            res += abs((i - b[i]) - b[i]);
    
    ans = min(ans, res);
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);
        x = y = 0;

        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]), a[i] &= 1;
            b[i] = b[i - 1] + a[i];
        }

        if (abs(n - b[n] - b[n]) > 1) {
            puts("-1");
            continue;
        }

        ans = 1e18;

        if (b[n] >= n - b[n])
            solve1_();
        
        if (n - b[n] >= b[n])
            solve0_();
        
        printf("%lld\n", ans);
    }
}