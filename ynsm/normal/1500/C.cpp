#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 1510;

int n, m, a[N][N], b[N][N];
int p[N], q[N];

int cnt[N];
bool was[N];

bool cmp(int i, int j)
{
    for (int q = 0; q < m; q++)
        if (a[i][q] != a[j][q])
            return a[i][q] < a[j][q];
    return 0;
}
bool cmp2(int i, int j)
{
    for (int q = 0; q < m; q++)
        if (b[i][q] != b[j][q])
            return b[i][q] < b[j][q];
    return 0;
}
void no()
{
    puts("-1");
    exit(0);
}
bool eql(int i, int j)
{
    for (int q = 0; q < m; q++)
        if (a[i][q] != a[j][q])
            return 0;
    return 1;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &b[i][j]);

    for (int i = 0; i < n; i++)
        p[i] = q[i] = i;
    sort(p, p + n, cmp);
    sort(q, q + n, cmp2);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (a[p[i]][j] != b[q[i]][j])
                no();
    for (int i = 0, j = 0; i < n; i = j)
    {
        while (j < n && eql(p[i], p[j]))
            j++;
        sort(p + i, p + j);
        sort(q + i, q + j);
        for (int k = i; k < j; k++)
            b[q[k]][m] = p[k];
    }

    for (int j = 0; j <= m; j++)
        for (int i = 1; i < n; i++)
            if (b[i - 1][j] > b[i][j])
                cnt[j]++;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j <= m; j++)
    //         cerr << b[i][j] << " ";
    //     cerr << endl;
    // }
    // for (int j = 0; j <= m; j++)
    //     cerr << cnt[j] << " ";
    // cerr << endl;
    vector<int> ans;
    while (true)
    {
        int j = -1;
        for (int i = 0; i <= m; i++)
            if (cnt[i] == 0)
                j = i;
        // cerr << j << endl;
        if (j == m)
            break;
        if (j == -1)
            no();
        cnt[j] = -1;
        ans.pb(j);
        for (int i = 1; i < n; i++)
        {
            if (!was[i] && b[i - 1][j] < b[i][j])
            {
                was[i] = 1;
                for (int j = 0; j <= m; j++)
                    if (b[i - 1][j] > b[i][j])
                        cnt[j]--;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    printf("%d\n", ans.size());
    for (auto x : ans)
        printf("%d ", x + 1);
}