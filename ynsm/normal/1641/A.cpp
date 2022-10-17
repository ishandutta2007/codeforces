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

int n, ans;
ll x, a[N];
void solve()
{
    ans = 0;
    scanf("%d%lld", &n, &x);
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    sort(a, a + n);
    for (int i = 0, j = 0; i < n; i++)
    {
        if (a[i] == 0)
            continue;
        while (j < n && a[i] * x > a[j])
            j++;
        if (j < n && a[i] * x == a[j])
            a[j] = 0, ans++, j++;
    }
    printf("%d\n", n - 2 * ans);
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}