#include <cstdio>
using namespace std;

const int N = 550;

char buf[N][N];

int vx[] = {1, 0, -1, 0};
int vy[] = {0, 1, 0, -1};

bool was[N][N];

int n, m, left;

bool DFS(int y, int x, int py = -1, int px = -1)
{
    was[y][x] = true;
    bool kill = true;
    for (int v = 0; v < 4; v++)
    {
        int ty = y + vy[v];
        int tx = x + vx[v];
        if (ty < 0 || ty >= n || tx < 0 || tx >= m || was[ty][tx] || buf[ty][tx] == '#' || buf[ty][tx] == 'X')
            continue;
        kill &= DFS(ty, tx, y, x);
    }
    if (left)
    {
        --left;
        buf[y][x] = 'X';
        return true;
    }
    return false;
}

int main()
{
    scanf("%d %d %d ", &n, &m, &left);
    for (int i = 0; i < n; i++)
        gets(buf[i]);
    int y = -1, x = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (buf[i][j] == '.')
                y = i, x = j;
    DFS(y, x);
    for (int i = 0; i < n; i++)
        puts(buf[i]);
}