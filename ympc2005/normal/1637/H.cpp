#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5 + 10;

int n, T, a[N], t[N], b[N];

ll ans;

void upd_(int x, int k) {
    for (; x <= n; x += x&-x) {
        t[x] += k;
    }
}

int ask_(int x, int res = 0) {
    for (; x; x -= x&-x) {
        res += t[x];
    }

    return res;
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d", &n);

        for (int i = 1; i <= n; i++) {
            t[i] = 0;
        }

        ans = 0;

        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
        }

        for (int i = n; i; i--) {
            int x = ask_(a[i]);
            b[i] = (a[i] - x - 1) - (n - a[i] - (n - i - x));
            b[i] += 2*x, ans += x;
            upd_(a[i], 1);
        }

        sort(b + 1, b + n + 1);

        for (int i = 0; i <= n; i++) {
            ans += b[i];
            printf("%lld ", ans - 1ll*i*(i - 1)/2);
        }

        puts("");
    }
}