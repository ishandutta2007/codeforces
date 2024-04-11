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

void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    ll x = 0, y = 0;
    bool ok1 = 0, ok2 = 0;
    for (int i = 1; i + 1 < n; i++)
    {
        x += a[i] / 2;
        if (a[i] & 1)
            y++;
        else
            ok1 = 1;
        if (a[i] > 1)
            ok2 = 1;
    }
    bool ok = 0;

    if (y == 0)
        ok = 1;
    if (y > 0 && ok1)
        ok = 1;
    if (y > 1 && ok2)
        ok = 1;

    if (!ok)
        printf("-1\n");
    else
        printf("%lld\n", x + y);
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}