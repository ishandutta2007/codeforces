#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 5000;
const ll INF = 1e18;

int n, a[N][N];
ll ans;
void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n + n; i++)
        for (int j = 0; j < n + n; j++)
            scanf("%d", &a[i][j]);
    ans = 0;

    for (int i = n; i < n + n; i++)
        for (int j = n; j < n + n; j++)
            ans += a[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans += a[i][j];
    // cerr << ans << endl;
    printf("%lld\n", ans + min({
                               a[0][n],
                               a[0][n + n - 1],
                               a[n - 1][n],
                               a[n - 1][n + n - 1],
                               a[n][0],
                               a[n][n - 1],
                               a[n + n - 1][0],
                               a[n + n - 1][n - 1],
                           }));
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}