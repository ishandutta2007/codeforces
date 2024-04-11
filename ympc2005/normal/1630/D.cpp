#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e6 + 10;

int n, m, d, T, a[N];

ll f[N][2];

int gcd_(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }

    return a;
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d", &n, &m);

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        } 

        d = 0;

        for (int x, i = 1; i <= m; i++) {
            scanf("%d", &x);
            d = gcd_(x, d);
        }

        for (int i = 0; i < d; i++) {
            f[i][0] = a[i];
            f[i][1] = -a[i];
        }

        for (int i = d; i < n; i++) {
            f[i][0] = max(f[i - d][1] - a[i], f[i - d][0] + a[i]);
            f[i][1] = max(f[i - d][0] - a[i], f[i - d][1] + a[i]);
        }

        ll ans1 = 0, ans2 = 0;
        
        for (int i = 1; i <= d; i++) {
            ans1 += f[n - i][0];
            ans2 += f[n - i][1];
        }

        printf("%lld\n", max(ans1, ans2));
    }
}