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

void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);

    auto b = a;
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());

    vector<int> conds;
    for (int j = 0; j < m; j++)
    {
        bool ok = 1;
        for (int i = 0; i < n; i++)
            ok &= (a[i][j] == b[i][j]);
        if (!ok)
            conds.pb(j);
    }
    int x = 0, y = 0;
    if (!conds.empty())
        x = *conds.begin(), y = *conds.rbegin();

    for (int i = 0; i < n; i++)
        swap(a[i][x], a[i][y]);
    auto c = a;
    for (int i = 0; i < n; i++)
        sort(c[i].begin(), c[i].end());
    if (a == c)
        printf("%d %d\n", x + 1, y + 1);
    else
        printf("-1\n");
}

int main()
{
    int t = 1;
    scanf("%d", &t);
    while (t--)
        solve();
}