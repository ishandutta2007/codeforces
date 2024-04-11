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

int n, a[N], b[N];

vector<int> g[N];

bool was[N];
int sz;

void dfs(int v)
{
    if (was[v])
        return;
    sz++;
    was[v] = 1;
    for (auto to : g[v])
        dfs(to);
}
void solve()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);

    for (int i = 1; i <= n; i++)
    {
        g[i].clear();
        was[i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        g[a[i]].pb(b[i]);
        g[b[i]].pb(a[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        sz = 0;
        dfs(i);
        ans += sz / 2;
    }
    ll s = 0;
    for (int i = 1; i <= ans; i++)
        s += n - i + 1 - i;
    s *= 2;
    printf("%lld\n", s);
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}