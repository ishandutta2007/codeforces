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

ll get(int v, int u, ll x)
{
    return 1ll * a[v] * a[u] + x * (a[v] + a[u]);
}
ll get(ll x)
{
    ll res = get(0, n - 1, x);
    for (int i = 1; i + 1 < n; i++)
        res += min(get(i, n - 1, x), get(0, i, x));
    return res;
}
void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    ll l = -1e7, r = 1e7;
    while (l <= r)
    {
        int m = (l + r) >> 1;
        ll x = get(m);
        ll y = get(m + 1);
        if (x < y)
            l = m + 1;
        else
            r = m - 1;
    }
    for (int i = l - 2; i <= l + 2; i++)
    {
        ll x = get(i);
        ll y = get(i + 1);
        ll z = get(i + 2);
        //    cerr << x << " " << y << " " << z << endl;
        if (x <= y && y >= z)
        {
            printf("%lld\n", y);
            return;
        }
    }
    printf("INF\n");
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}