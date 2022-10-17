#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 5050;

int n, a[N];
int b[N][N];

int get(int l, int r, int k)
{
    if(l > r)
        return 0;
    return b[r][k] - b[l - 1][k];
}

void solve()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        for (int j = 0; j <= n; j++)
        {
            b[i][j] = b[i - 1][j];
            if (a[i] <= j)
                b[i][j]++;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            ans += 1ll * get(1, i - 1, a[j] - 1) * get(j + 1, n, a[i] - 1);
    printf("%lld\n", ans);
}
int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}