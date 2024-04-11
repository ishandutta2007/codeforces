#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 20100;

int n, a[N], b[N];
void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &b[i]);

    bitset<N> dp;
    dp.reset();
    dp[0] = 1;
    for (int i = 0; i < n; i++)
        dp = (dp << a[i]) | (dp << b[i]);

    ll ans = 1e18, s = 0;
    for (int i = 0; i < n; i++)
        s += a[i] + b[i];
    for (int i = 0; i < N; i++)
        if (dp[i])
            ans = min(ans, 1ll * i * i + 1ll * (s - i) * (s - i));

    for (int i = 0; i < n; i++)
        ans += 1ll * (n - 2) * (1ll * a[i] * a[i] + 1ll * b[i] * b[i]);
    printf("%lld\n", ans);
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}