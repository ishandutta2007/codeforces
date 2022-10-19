#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 110;

int n, m;
pair<int, pii> a[N * N];
bool was[N][N];
vector<int> v[2][N];
int ans[N][N];

void solve()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &a[i * m + j].f);
            a[i * m + j].s = {i, j};
        }
    }
    sort(a, a + n * m);
    for (int i = 0; i < n; i++)
    {
        v[0][i].clear();
        v[1][i].clear();
    }
    for (int i = 0; i < n * m; i++)
    {
        int val = a[i].f;
        int x = a[i].s.f;
        int y = a[i].s.s;
        if (i < m)
            v[0][x].pb(val);
        else
            v[1][x].pb(val);
    }
    for (int i = 0; i < m; i++)
    {
        bool ok = 0;
        for (int j = 0; j < n; j++)
        {
            if (!ok && !v[0][j].empty())
            {
                ok = 1;
                ans[j][i] = v[0][j].back();
                v[0][j].pop_back();
                continue;
            }
            if (!v[1][j].empty())
            {
                ans[j][i] = v[1][j].back();
                v[1][j].pop_back();
                continue;
            }
            if (!v[0][j].empty())
            {
                ans[j][i] = v[0][j].back();
                v[0][j].pop_back();
                continue;
            }
            assert(0);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", ans[i][j]);
        printf("\n");
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
}