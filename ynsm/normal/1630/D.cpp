#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e6 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

int n, m, g, a[N];
void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    g = 0;
    for (int i = 0; i < m; i++)
    {
        int x;
        scanf("%d", &x);
        g = __gcd(g, x);
    }
    ll X = 0, Y = 0;
    for (int i = 0; i < g; i++)
    {
        ll x = 0, y = -INF;
        for (int j = i; j < n; j += g)
        {
            ll nx = max(x + a[j], y - a[j]);
            ll ny = max(x - a[j], y + a[j]);
            x = nx, y = ny;
        }
        X += x, Y += y;
    }
    printf("%lld\n", max(X, Y));
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}