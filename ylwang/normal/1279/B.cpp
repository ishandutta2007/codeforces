#include <bits/stdc++.h>

#define ll long long

const int MaxN = 1000000 + 10;

using namespace std;

inline ll read() {
    ll cnt = 0, opt = 1;
    char ch = getchar();

    for (; ! isalnum(ch); ch = getchar())
        if (ch == '-')  opt = 0;
    for (; isalnum(ch); ch = getchar())
        cnt = cnt * 10 + ch - 48;

    return opt ? cnt : -cnt;
}

int T;

ll a[MaxN];

ll sum[MaxN];

int main() {
    T = read();

    while (T --) {
        memset(sum, 0, sizeof(sum));
        ll n, s, ans = 0, RMax = 0;

        n = read(), s = read();

        for (int i = 1; i <= n; ++ i) {
            a[i] = read();
            sum[i] = sum[i - 1] + a[i];
        }

        if (sum[n] <= s) {
            printf("%d\n", 0);
            continue;
        }

        for (int i = 1; i <= n; ++ i) {

            ll Now = sum[i - 1], Max = -1;
            if (Now > s)
                break;
            ll s_now = s - Now;
            ll l = i + 1, r = n;

            while (r >= l) {
                ll mid = (l + r) >> 1;

                if (sum[mid] - sum[i] <= s_now) {
                    Max = max(Max, mid);
                    l = mid + 1;
                }
                else r = mid - 1;
            }

            Max = Max == -1 ? i - 1 : Max - 1;

            if (RMax < Max)
                ans = i, RMax = Max;
        }

        printf("%lld\n", ans);
    }
    return 0;
}