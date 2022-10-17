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

int n, k, a[N];
void solve()
{
    scanf("%d%d", &n, &k);

    ll s = 1ll * k * n;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        s += a[i];
        a[i] += i;
    }
    sort(a, a + n);
    reverse(a, a + n);
    for (int i = 0; i < k; i++)
        s -= a[i];
    s -= 1ll * k * (k + 1) / 2;
    printf("%lld\n", s);
}

int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}