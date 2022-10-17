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
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        int pos = lower_bound(a, a + n, a[i] + k) - a;
        if (pos != n && a[pos] == a[i] + k)
        {
            printf("YES\n");
            return;
        }
    }
    printf("NO\n");
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}