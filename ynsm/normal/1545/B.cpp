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

int n;
ll f[N], rf[N];
char a[N];

ll bp(ll x, ll p)
{
    ll res = 1;
    while (p)
    {
        if (p & 1)
            res = res * x % mod;
        x = x * x % mod;
        p >>= 1;
    }
    return res;
}
ll inv(ll x)
{
    return bp(x, mod - 2);
}

ll C(int k, int n)
{
    return f[n] * rf[k] % mod * rf[n - k] % mod;
}

void solve()
{
    scanf("%d\n", &n);
    scanf("%s", a);
    int x = 0, y = 0;
    for (int i = 0, j = 0; i < n; i = j)
    {
        while (j < n && a[i] == a[j])
            j++;
        if (a[i] == '1')
            x += (j - i) / 2;
        else
            y += (j - i);
    }
    printf("%lld\n", C(x, x + y));
}
int main()
{
    f[0] = rf[0] = 1;
    for (int i = 1; i < N; i++)
        f[i] = f[i - 1] * i % mod, rf[i] = inv(f[i]);
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
}