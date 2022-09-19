# include <cstdio>
# include <set>
# include <cstdlib>
using namespace std;
const int MN = 1515;
const pair <int, int> NONE = make_pair(MN * MN + MN, MN * MN + 525);
char mapa[MN][MN];
pair <int, int> in[MN][MN];
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int n, m;
void found()
{
    printf("Yes\n");
    exit(0);
}
void dfs(int x, int y, int r1, int r2)
{
    if (x < 0)
    {
        x += n;
        r1--;
    }
    else if (x >= n)
    {
        x -= n;
        r1++;
    }
    else if (y < 0)
    {
        y += m;
        r2--;
    }
    else if (y >= m)
    {
        y -= m;
        r2++;
    }
    if (mapa[x][y] == '#')
        return;
    if (in[x][y] == NONE)
    {
        in[x][y] = make_pair(r1, r2);
        for (int i = 0; i < 4; ++i)
        dfs(x + dx[i], y + dy[i], r1, r2);
    }
    else if (in[x][y] != make_pair(r1, r2))
        found();
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
        scanf("%s", mapa[i]);
    for (int i = 0; i < n; ++i)
        for (int k = 0; k < m; ++k)
            in[i][k] = NONE;
    for (int i = 0; i < n; ++i)
        for (int k = 0; k < m; ++k)
            if (mapa[i][k] == 'S')
            {
                dfs(i, k, 1, 4);
                printf("No\n");
                return 0;
            }
}