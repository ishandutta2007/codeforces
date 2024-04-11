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

int n, a[N];
ll ans;

void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    ans = INF;
    for (int i = 0; i < n; i++)
    {
        ll cur = 0;
        {
            ll last = 0;
            for (int j = i + 1; j < n; j++)
            {
                cur += (last / a[j] + 1);
                last = (last / a[j] + 1) * a[j];
            }
        }
        {
            ll last = 0;
            for (int j = i - 1; j >= 0; j--)
            {
                cur += (last / a[j] + 1);
                last = (last / a[j] + 1) * a[j];
            }
        }
        ans = min(ans, cur);
    }
    printf("%lld\n", ans);
}
int main()
{
    int t = 1;
    // scanf ("%d", &t);
    while (t--)
        solve();
}