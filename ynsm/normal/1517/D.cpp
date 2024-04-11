#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 550, inf = 1e9;
const int D = 4;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int n, m, k;
int w[N][N][4];
int dp[N][N][22];
bool was[N][N][22];
int f(int i, int j, int k)
{
    if (k == 0)
        return 0;
    if (was[i][j][k])
        return dp[i][j][k];
    was[i][j][k] = 1;
    int res = inf;
    for (int q = 0; q < D; q++)
    {
        int ni = i + dx[q];
        int nj = j + dy[q];
        if (0 > ni || ni >= n)
            continue;
        if (0 > nj || nj >= m)
            continue;
        res = min(res, f(ni, nj, k - 1) + w[i][j][q]);
    }
    return dp[i][j][k] = res;
}
int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j + 1 < m; j++)
        {
            int x;
            scanf("%d", &x);
            w[i][j][0] = x;
            w[i][j + 1][1] = x;
        }
    }
    for (int i = 0; i + 1 < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            scanf("%d", &x);
            w[i][j][2] = x;
            w[i + 1][j][3] = x;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (k & 1)
            {
                printf("-1 ");
            }
            else
            {
                printf("%d ", 2 * f(i, j, k / 2));
            }
        }
        printf("\n");
    }
}