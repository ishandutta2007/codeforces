#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

void solve()
{
    int n, m;
    ll ans = 0;
    scanf("%d%d", &n, &m);
    int a[n], b[m];
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i <= m; i++)
        scanf("%d", &b[i]);

    sort(a + 1, a + n + 1);
    reverse(a + 1, a + n + 1);
    for (int i = 1, j = 1; i <= n; i++)
    {
        j = min(j, a[i]);
        ans += b[j];
        j++;
    }
    printf("%lld\n", ans);
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
}