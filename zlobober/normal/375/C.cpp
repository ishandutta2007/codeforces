#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <cassert>
using namespace std;

const int N = 25;

char buf[N][N];

const int K = 8;
const int MSK = 1 << K;

struct vt
{
    int x, y;
    vt(int _x, int _y)
    {
         x = _x, y = _y;
    }
    vt(){}
    friend int operator ^(vt a, vt b)
    {
        return a.x * b.y - b.x * a.y;
    }
    friend vt operator -(vt a, vt b)
    {
        return vt(a.x - b.x, a.y - b.y);
    }
    friend vt operator +(vt a, vt b)
    {
        return vt(a.x + b.x, a.y + b.y);
    }
};

int T[K];
vt pos[K];
int oldi[K];
int C[K];

const int dx = 42, dy = 43;

int D[MSK][N][N];

int lpt = 0, rpt = 0;
int Q[10 * MSK * N * N];

int vx[] = {1, 0, -1, 0};
int vy[] = {0, 1, 0, -1};

int n, m;

int pt = 0;

inline int sign(int x)
{
    return (x > 0) - (x < 0);
}

inline bool inter(vt a, vt b, vt c, vt d)
{
    return (sign((c - a) ^ (b - a)) * sign((d - a) ^ (b - a)) == -1 && sign((a - c) ^ (d - c)) * sign((b - c) ^ (d - c)) == -1);
}

char _aff[N][N][4][K];

bool affect(int y, int x, int v, int i)
{
    if (_aff[y][x][v][i] != -1)
        return _aff[y][x][v][i];
    else
        return _aff[y][x][v][i] = inter(vt(y, x), vt(y, x) + vt(vy[v], vx[v]), pos[i], pos[i] + vt(dy, dx));
}


void BFS(int sy, int sx)
{
    memset(D, -1, sizeof(D));
    D[0][sy][sx] = 0;
    Q[rpt++] = 0;
    Q[rpt++] = sy;
    Q[rpt++] = sx;
    while (lpt != rpt)   
    {
        int msk = Q[lpt++];
        int y = Q[lpt++];
        int x = Q[lpt++];
        for (int v = 0; v < 4; v++)
        {
            int ty = y + vy[v];
            int tx = x + vx[v];
            if (ty < 0 || tx < 0 || ty >= n || tx >= m)
                continue;
            if (buf[ty][tx] != '.' && buf[ty][tx] != 'S')
                continue;
            int tmsk = msk;
            for (int i = 0; i < pt; i++)
            {
                if (affect(y, x, v, i))
                    tmsk ^= (1 << i);
            }
            if (D[tmsk][ty][tx] != -1)
                continue;
            D[tmsk][ty][tx] = D[msk][y][x] + 1;
            Q[rpt++] = tmsk;
            Q[rpt++] = ty;
            Q[rpt++] = tx;
        }
    }   
}

int main()
{
    memset(_aff, -1, sizeof(_aff));
    scanf("%d %d ", &n, &m);
    int sx = -1, sy = -1;
    int tr = 0;
    for (int i = 0; i < n; i++)
    {
        gets(buf[i]);
        for (int j = 0; j < m; j++)
        {
            if (buf[i][j] == 'S')
                sy = i, sx = j;
            else if (buf[i][j] == 'B')
                T[pt] = 0, pos[pt] = vt(i, j), pt++;
            else if ('1' <= buf[i][j] && buf[i][j] <= '8')
                T[pt] = 1, oldi[pt] = buf[i][j] - '1', pos[pt] = vt(i, j), pt++, tr++;
        }
    }
    for (int i = 0; i < tr; i++)
        scanf("%d", &C[i]);
    assert(sx != -1);
    
    BFS(sy, sx);
    int ans = 0;
    for (int v = 0; v < 4; v++)
    {
        int y = sy - vy[v];
        int x = sx - vx[v];
        if (y < 0 || y >= n || x < 0 || x >= m)
            continue;
        if (buf[y][x] != '.' && buf[y][x] != 'S')
            continue;
        for (int msk = 0; msk < (1 << pt); msk++)
        {
            int rmsk = msk;
            if (D[msk][y][x] != -1)
            {
                for (int i = 0; i < pt; i++)
                    if (affect(y, x, v, i))
                        rmsk ^= (1 << i);
                int cst = 0;
                bool bad = false;
                for (int i = 0; i < pt; i++)
                    if ((rmsk >> i) & 1)
                    {
                        if (!T[i])
                            bad = true;
                        else
                            cst += C[oldi[i]];
                    }
                if (!bad)
                    ans = max(ans, cst - D[msk][y][x] - 1);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}