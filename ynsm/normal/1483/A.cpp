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

int n, m;
vector<int> a[N];
int cnt[N], ans[N];
void solve()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        a[i].clear();
    for (int i = 1; i <= m; i++)
        cnt[i] = 0;
    for (int i = 1; i <= m; i++)
    {
        int k;
        scanf("%d", &k);
        while (k--)
        {
            int x;
            scanf("%d", &x);
            a[x].pb(i);
            cnt[i]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int cur = 0;
        for (auto j : a[i])
            if (cnt[j] == 1)
                cur++, cnt[j] = 0, ans[j] = i;
        for (auto j : a[i])
            if (cnt[j])
            {
                if (cur < (m + 1) / 2)
                    cur++, cnt[j] = 0, ans[j] = i;
                else
                    cnt[j]--;
            }
        if (cur > (m + 1) / 2)
        {
            puts("NO");
            return;
        }
    }
    puts("YES");
    for (int i = 1; i <= m; i++)
        printf("%d ", ans[i]);
    printf("\n");
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
}