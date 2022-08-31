#include <iostream>
#include <cstdio>
using namespace std;

const int H = 15050;
const int N = 1550;

int vx[4] = {-1, 0, 1, 0};
int vy[4] = {0, 1, 0, -1};

bool F[N][N];
int was[N][N];

int n, m;

bool good = false;

void DFS(int y, int x, int cy, int cx)
{
    was[y][x] = cy * H + cx;
    for (int v = 0; v < 4; v++)
    {
        int ty = y + vy[v];
        int tx = x + vx[v];
        int tcy = cy, tcx = cx;
        if (ty < 0)
            ty += n, tcy--;
        if (tx < 0)
            tx += m, tcx--;
        if (ty >= n)
            ty -= n, tcy++;
        if (tx >= m)
            tx -= m, tcx++;
        if (!F[ty][tx])
            continue;
        if (was[ty][tx] != 1e9)
        {
            if (was[ty][tx] != tcy * H + tcx)
            {
                good = true;
                return;
            }
            else
                continue;
        }
        DFS(ty, tx, tcy, tcx);
        if (good)
            return;
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    int sy, sx;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            char t;
            scanf(" %c ", &t);
            F[i][j] = (t != '#');
            if (t == 'S')
                sy = i, sx = j;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            was[i][j] = 1e9;
    DFS(sy, sx, 0, 0);
    if (good)
        printf("Yes\n");
    else
        printf("No\n");
}