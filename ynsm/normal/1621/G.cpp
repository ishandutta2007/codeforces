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
pii b[N], dp[N], t[N];

vector<int> g;

int sum(int a, int b)
{
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}
int sub(int a, int b)
{
    a -= b;
    if (a < 0)
        a += mod;
    return a;
}
pii sum(pii a, pii b)
{
    return {sum(a.f, b.f), sum(a.s, b.s)};
}
pii sum(int r)
{
    pii res = {0, 0};
    for (; r >= 0; r = (r & (r + 1)) - 1)
        res = sum(res, t[r]);
    return res;
}

void inc(int i, pii x)
{
    for (; i < n; i = (i | (i + 1)))
        t[i] = sum(t[i], x);
}

void add(int i)
{
    g.pb(i);
    pii x = sum(i);
    dp[i] = {x.f, sum(x.s, x.f)};
    dp[i] = sum(dp[i], {1, 1});
    // cerr << i << " " << dp[i].f << " " << dp[i].s << endl;
    inc(i, dp[i]);
}
void clear()
{
    while (!g.empty())
    {
        int i = g.back();
        g.pop_back();
        inc(i, {0, sub(0, dp[i].s)});
        dp[i].s = 0;
    }
}

void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < n; i++)
        b[i] = {a[i], -i};
    sort(b, b + n);

    int ans = 0;
    for (int i = 0; i < n; i++)
        t[i] = {0, 0};
    for (int i = 0; i < n; i++)
    {
        int x = -b[i].s;
        add(x);
        ans = sum(ans, dp[x].s);
    }
    clear();

    for (int i = 0; i < n; i++)
        t[i] = {0, 0};

    int mx = -1;
    for (int i = n - 1, j = 0; i >= 0; i--)
    {
        if (a[i] >= mx)
        {
            mx = a[i];
            while (j < n)
            {
                int x = -b[j].s;
                add(x);
                j++;
                if (x == i)
                    break;
            }
            ans = sub(ans, dp[i].s);
            clear();
        }
    }
    printf("%d\n", ans);
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}