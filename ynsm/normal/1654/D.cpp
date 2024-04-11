#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 998244353;
const ll INF = 1e18;

int sum(int a, int b)
{
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}
int mult(int a, int b) { return 1ll * a * b % mod; };
int pw(int a, int b)
{
    int c = 1;
    while (b)
    {
        if (b & 1)
            c = mult(c, a);
        a = mult(a, a);
        b >>= 1;
    }
    return c;
}

int n, ld[N];
vector<array<int, 3>> g[N];
int a[N], b[N];
int ans, cur;

void add(int x, int i)
{
    while (x > 1)
    {
        int p = ld[x];
        int cnt = 0;
        while (x % p == 0)
            x /= p, cnt++;

        a[p] += cnt * i;
        b[p] = min(b[p], a[p]);
    }
}
void dfs(int v, int p)
{
    ans = sum(ans, cur);
    for (auto it : g[v])
    {
        int to = it[0];
        int x = it[2];
        int y = it[1];
        if (to == p)
            continue;

        add(x, +1);
        add(y, -1);

        cur = mult(cur, mult(x, pw(y, mod - 2)));

        dfs(to, v);

        cur = mult(cur, mult(y, pw(x, mod - 2)));

        add(y, +1);
        add(x, -1);
    }
}
void solve()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        g[i].clear();
    for (int i = 1; i < n; i++)
    {
        int v, u, x, y;
        scanf("%d%d%d%d", &v, &u, &x, &y);
        g[v].pb({u, x, y});
        g[u].pb({v, y, x});
    }
    for (int i = 0; i <= n; i++)
        a[i] = b[i] = 0;

    ans = 0, cur = 1;
    dfs(1, 1);

    for (int i = 0; i <= n; i++)
        ans = mult(ans, pw(i, -b[i]));
    printf("%d\n", ans);
}
int main()
{
    for (int i = 2; i < N; i++)
        if (ld[i] == 0)
            for (int j = i; j < N; j += i)
                ld[j] = i;

    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}