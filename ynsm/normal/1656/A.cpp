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

int n;
pii a[N];
void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i].f);
        a[i].s = i;
    }
    sort(a, a + n);
    printf("%d %d\n", a[0].s + 1, a[n - 1].s + 1);
}
int main()
{
    int t = 1;
    scanf ("%d", &t);
    while (t--)
        solve();
}