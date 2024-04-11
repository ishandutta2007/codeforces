#include <cstdio>
#include <cassert>
#include <vector>
using namespace std;

const int N = 2000500;

int E[N][3];
char ept[N];

const int LOG = 21;

int D[N];
int up[LOG][N];

int curt = 0;

void DFS(int x, int p = -1)
{
    if (p == -1)
        D[x] = 0, up[0][x] = x;
    else
        D[x] = D[p] + 1, up[0][x] = p;
    for (int u = 1; u < LOG; u++)
        up[u][x] = up[u - 1][up[u - 1][x]];
    for (int i = 0; i < ept[x]; i++)
        DFS(E[x][i], x);
}

int lca(int a, int b);

inline bool is_par(int a, int b)
{
    return lca(a, b) == a;
}

inline int lca(int a, int b)
{
    if (D[a] >= D[b])
        swap(a, b);
    for (int u = LOG - 1; u >= 0; u--)
        if (D[up[u][b]] >= D[a])
            b = up[u][b];
    if (a == b)
        return a;
    for (int u = LOG - 1; u >= 0; u--)
        if (up[u][b] != up[u][a])
            b = up[u][b], a = up[u][a];
    assert(up[0][a] == up[0][b]);
    return up[0][a];
}

inline int dist(int a, int b)
{
    if (is_par(a, b))
        return D[b] - D[a];
    else if (is_par(b, a))
        return D[a] - D[b];
    int l = lca(a, b);
    return D[a] + D[b] - 2 * D[l];
}

void add_edge(int a, int b)
{
    a *= 2, b *= 2;
    int m = b - 1;
    assert(ept[a] < 3 && ept[m] < 3);
    E[a][ept[a]++] = m;
    E[m][ept[m]++] = b;
}

int cen = 2, diam = 2;

inline void shift(int v)
{
    int nd = dist(cen, v);
    assert(!((nd - diam) & 1));
    if (nd > diam)
    {
        diam++;
        bool was = false;
        for (int i = 0; i < ept[cen]; i++)
        {
            int y = E[cen][i];
            if (is_par(y, v))
            {
                assert(!was);
                cen = y, was = true;
                break;
            }
        }
        if (!was)
            cen = up[0][cen];
    }
}

int main()
{
    int q;
    scanf("%d", &q);
    add_edge(1, 2);
    add_edge(1, 3);
    add_edge(1, 4);
    int n = 4;
    for (int i = 0; i < q; i++)
    {
        int v;
        scanf("%d", &v);
        add_edge(v, n + 1);
        add_edge(v, n + 2);
        n += 2;
    }
    DFS(2);
    n = 4;
    for (int i = 0; i < q; i++)
    {
        shift(2 * n + 2);
        n += 2;
        printf("%d\n", diam);
    }
}